#include "dlg.h"

#include <string>

#include <gcroot.h>

#include <xlib.h>

#include "SelectMem.h"

static const wchar_t* const gk_app_name = L"特征码扫描/更新";
static const wchar_t* const gk_app_ver = L"ver 1.0";
static const wchar_t* const gk_author = L"by triones";
static const wchar_t* const gk_copyright = L"All rights reserved (c)";

using namespace std;
using namespace SignatureMatcher;

//! 线程用于使混合DLL成功启动CLR窗口
static gcroot <dlg^> mydlg = nullptr;
void CLR_Main()
  {
  mydlg = gcnew dlg;
  mydlg->ShowDialog();
  }
DWORD WINAPI StartCLR(PVOID lParam)
  {
  UNREFERENCED_PARAMETER(lParam);
  //线程再起线程是为了处理DrapDrop在多线程情况下注册失败的问题
  System::Threading::Thread^ th = gcnew System::Threading::Thread(
    gcnew System::Threading::ThreadStart(CLR_Main));
  th->SetApartmentState(System::Threading::ApartmentState::STA);
  th->Start();
  return 0;
  }

//! 用于输出信息，也被用作输出回调
void showinfo(const char* const buf)
  {
  mydlg->TB_mem->AppendText(gcnew System::String(buf));
  }

//! 控制面板显示或关闭
System::Void dlg::Btn_Show_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  GB_Main->Visible = !GB_Main->Visible;
  }

//! 用于阻止ok、cancel键关闭窗口
static bool g_canclose = true;

//! 控制面板隐藏，阻止cancel事件
System::Void dlg::Btn_Hide_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  if(GB_Main->Visible)
    {
    g_canclose = false;
    GB_Main->Visible = false;
    }
  }

//! 窗口加载初始化
System::Void dlg::dlg_Load(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);

  //设置信息输出等级及回调
  signaturematcher::log_level() = xlog::lvl_error;
  signaturematcher::set_log_out(showinfo);

  wchar_t procname[MAX_PATH];
  GetModuleFileNameW(nullptr, procname, _countof(procname));

  //做标题
  wstring title;
  title += procname;
  title += L"--";
  title += gk_app_name;
  title += L"  ";
  title += gk_app_ver;
  title += L"  ";
  title += gk_author;
  title += L"  ";
  title += gk_copyright;
  this->Text = gcnew System::String(title.c_str());

  //GroupBox没有AllowDrop选项，只好这里设置
  GB_Main->AllowDrop = true;

  //控制面板选项设置
  PL_Sig->Top = PL_File->Top;
  RB_File_CheckedChanged(sender, e);

  //x86下，控制地址长度
#ifndef _WIN64
  TB_Start->MaxLength = 11;
  TB_End->MaxLength = 11;
#endif
  }

//! 模态窗口阻止非意图关闭
System::Void dlg::dlg_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  if(!g_canclose)
    {
    e->Cancel = true;
    }
  g_canclose = true;
  }

//! 窗口关闭
System::Void dlg::Btn_Close_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  g_canclose = true;
  Close();
  }

//! 窗口最小化
System::Void dlg::Btn_Min_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  this->WindowState = FormWindowState::Minimized;
  }

//! 窗口移动
System::Void dlg::LB_Pos_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  ReleaseCapture();
  SendMessage((HWND)this->Handle.ToPointer(), WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
  }

//! 处理十六进制地址输入
System::Void dlg::TB_Start_TextChanged(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  TextBox^ tb = (TextBox^)sender;

  if(System::String::IsNullOrEmpty(tb->Text)) return;

  //提取文本内容
  const wchar_t* tmplp = (wchar_t*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalUni(tb->Text);

  const wstring src(tmplp);

  //注意释放资源
  System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)(void*)tmplp);

  wstring hexstr;

  //开始处理文本，识别十六进制
  for(auto ch : src)
    {
    if(hexstr.size() >= (sizeof(void*)* 2))   break;  //数据足够，丢弃后继数据

    wchar_t dch;
    switch(ch)
      {
      case L'0':      case L'1':      case L'2':      case L'3':
      case L'4':      case L'5':      case L'6':      case L'7':
      case L'8':      case L'9':
      case L'A':      case L'B':      case L'C':      case L'D':
      case L'E':      case L'F':
        dch = ch;
        break;
      case L'a':      case L'b':      case L'c':      case L'd':
      case L'e':      case L'f':
        dch = ch - L'a' + L'A';
        break;
      default: continue;
      }

    hexstr.push_back(dch);
    }

  //处理十六进制地址显示格式
  wstring dest;
  for(wstring::const_reverse_iterator it = hexstr.rbegin(); it != hexstr.rend(); ++it)
    {
    dest.insert(dest.begin(), *it);
    switch(dest.size())
      {
      case 3:   case 6:   case 9:
      case 17:  case 20:  case 23:
        dest.insert(1, 1, L' ');
        break;
      case 12:
        dest.insert(1, 1, L' ');
        dest.insert(1, 1, L'`');
        dest.insert(1, 1, L' ');
        break;
      default:
        break;
      }
    }

  System::String^ cur_str = gcnew System::String(dest.c_str());

  //比较文本是否需要修改
  if(cur_str->CompareTo(tb->Text) != 0)
    {
    tb->Text = cur_str;
    //文本修改后需要改变光标位置，这里简单的处理指向文本最后一个字符
    tb->SelectionStart = tb->MaxLength;
    }
  }

//! 文本清空
System::Void dlg::TB_mem_DoubleClick(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  TB_mem->Clear();
  }

//! 打开文件对话框
System::Void dlg::Btn_File_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  //阻止传递给Form的OK或CANCEL事件
  g_canclose = false;
  if(OFD_File->ShowDialog() != System::Windows::Forms::DialogResult::OK)  return;
  TB_File->Text = OFD_File->FileName;
  }

//! 拖放事件
System::Void dlg::GB_Main_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  if(e->Data->GetDataPresent(DataFormats::FileDrop))
    {
    e->Effect = DragDropEffects::Link;
    return;
    }
  if(e->Data->GetDataPresent(DataFormats::Text))
    {
    e->Effect = DragDropEffects::Copy;
    return;
    }
  e->Effect = DragDropEffects::None;
  }
System::Void dlg::GB_Main_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);

  if(e->Data->GetDataPresent(DataFormats::FileDrop))
    {
    RB_File->Checked = true;
    RB_Sig->Checked = false;
    TB_File->Text = ((Array^)e->Data->GetData(DataFormats::FileDrop))->GetValue(0)->ToString();
    }
  else
    {
    RB_File->Checked = false;
    RB_Sig->Checked = true;
    TB_Sig->Text = e->Data->GetData(DataFormats::Text)->ToString();
    }
  Btn_Match_Click(sender, e);
  }

//! 全局特征码文件、特征码匹配标记
bool g_file_sig = false;

string g_filename;
line g_signature;

static HANDLE g_thd_matcher = nullptr;      //!< 工作线程

static xlog::levels g_log_lvl = xlog::lvl_error;  //!< Trace信息等级
bool g_create_atom = true;                 //!< 指定是否自动生成中间原子
bool g_cx11 = true;                        //!< 指定是否生成C++11格式头文件
xblk g_blk;                                //!< 指定内存范围

DWORD WINAPI Thd_Match(PVOID lParam);

//! 特征码匹配
System::Void dlg::Btn_Match_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  g_canclose = false;

  //判定上次工作线程是否结束，如未结束，需请示处理
  if(g_thd_matcher != nullptr)
    {
    if(WAIT_OBJECT_0 != WaitForSingleObject(g_thd_matcher, 0))
      {
      if(MessageBox::Show(
        L"上一次的匹配过程还没结束，是否等待？\n\n如不等待请选择'否'，将强制结束之前的工作",
        L"警告", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) != ::DialogResult::No)
        {
        return;
        }
      TerminateThread(g_thd_matcher, 0);
      xmsg msg;
      msg << "上次的工作:" << g_thd_matcher << " 现被强制关闭\r\n";
      showinfo(msg.c_str());
      }
    }
  g_thd_matcher = nullptr;

  //设定Trace信息等级
  if(RB_Trace->Checked) g_log_lvl = xlog::lvl_on;
  if(RB_TraceErr->Checked)  g_log_lvl = xlog::lvl_error;
  if(RB_NoTrace->Checked) g_log_lvl = xlog::lvl_off;
  signaturematcher::log_level() = g_log_lvl;

  g_file_sig = RB_File->Checked;

  if(g_file_sig)
    {
    //提取属性
    g_create_atom = CB_CreateAtom->Checked;
    g_cx11 = CB_Cx11->Checked;
    //判定文件有效性
    if(System::String::IsNullOrEmpty(TB_File->Text))
      {
      tp->Show("请指定特征码文件", TB_File, 10, -45, 3000);
      TB_File->Focus();
      return;
      }
    const char* filename = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(TB_File->Text);

    g_filename.assign(filename);

    System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)(void*)filename);
    }
  else
    {
    //判定地址有效性
    if(System::String::IsNullOrEmpty(TB_Start->Text))
      {
      TB_Start->Text = "0";
      }
    if(System::String::IsNullOrEmpty(TB_End->Text))
      {
      TB_End->Text = "0";
      }
    //判定特征码有效性
    if(System::String::IsNullOrEmpty(TB_Sig->Text))
      {
      tp->Show("请给出特征码", TB_Sig, 10, 10, 3000);
      TB_Sig->Focus();
      return;
      }

    //提取地址
    const char* s[2];
    s[0] = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(TB_Start->Text);
    s[1] = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(TB_End->Text);

    void* p[_countof(s)];
    for(size_t i = 0; i < _countof(s); ++i)
      {
      size_t pp = 0;
      for(const char* str = s[i]; *str != '\0'; ++str)
        {
        switch(*str)
          {
          case '0':      case '1':      case '2':      case '3':
          case '4':      case '5':      case '6':      case '7':
          case '8':      case '9':
            pp <<= 4;
            pp += ((*str) - '0');
            break;
          case 'A':      case 'B':      case 'C':      case 'D':
          case 'E':      case 'F':
            pp <<= 4;
            pp += ((*str) - 'A') + 0xA;
            break;
          case 'a':      case 'b':      case 'c':      case 'd':
          case 'e':      case 'f':
            pp <<= 4;
            pp += ((*str) - 'a') + 0xA;
            break;
          default: break;
          }
        }
      p[i] = (void*)pp;
      }
    g_blk = xblk(p[0], p[1]);

    System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)(void*)s[0]);
    System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)(void*)s[1]);

    //提取特征码
    const char* sig = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(TB_Sig->Text);

    g_signature.assign((unsigned char*)sig);

    System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)(void*)sig);
    }


  Btn_Hide_Click(sender, e);

  g_thd_matcher = CreateThread(nullptr, 0, Thd_Match, nullptr, 0, nullptr);
  }


//! 控制不同选项显隐
System::Void dlg::RB_File_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  g_file_sig = (RB_File->Checked);

  Panel^ pl_show = g_file_sig ? PL_File : PL_Sig;
  Panel^ pl_hide = g_file_sig ? PL_Sig : PL_File;

  pl_show->Visible = true;
  pl_hide->Visible = false;
  GB_Main->Height = pl_show->Top + pl_show->Height + 8;
  }

static void* TB_End_Get(const pe& tmppe, const bool img)
  {
  __try
    {
    if(!tmppe.IsPE()) return nullptr;
    return (img ? tmppe.GetImage() : tmppe.GetCode()).end();
    }
  __except(EXCEPTION_EXECUTE_HANDLER)
    {
    return nullptr;
    }
  }

//! 如果start是一个PE头，根据image或code选项，自动给出end
System::Void dlg::TB_End_Enter(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);

  if(System::String::IsNullOrEmpty(TB_Start->Text)) return;

  if(!System::String::IsNullOrEmpty(TB_End->Text))
    {
    if(TB_End->Text->Length > 4)  return;
    }

  //提取地址
  const char* const ps = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(TB_Start->Text);
  
  size_t pp = 0;
  for(const char* str = ps; *str != '\0'; ++str)
    {
    switch(*str)
      {
      case '0':      case '1':      case '2':      case '3':
      case '4':      case '5':      case '6':      case '7':
      case '8':      case '9':
        pp <<= 4;
        pp += ((*str) - '0');
        break;
      case 'A':      case 'B':      case 'C':      case L'D':
      case 'E':      case 'F':
        pp <<= 4;
        pp += ((*str) - 'A') + 0xA;
        break;
      case L'a':      case L'b':      case L'c':      case L'd':
      case L'e':      case L'f':
        pp <<= 4;
        pp += ((*str) - 'a') + 0xA;
        break;
      default: break;
      }
    }

  System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)(void*)ps);

  if(pp == 0) return;

  const bool img = RB_Image->Checked;

  const pe tmppe((HMODULE)pp);

  void* end = TB_End_Get(tmppe, img);

  if(end == nullptr)  return;

  xmsg msg;
  msg << end;

  TB_End->Text = gcnew System::String(msg.c_str());
  }

//! 响应code和image的变动
System::Void dlg::RB_Image_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  //提取旧的end值
  System::String^ tmpend = TB_End->Text;
  //删除end数据
  TB_End->Text = nullptr;
  //触发修改
  TB_End_Enter(sender, e);
  //如果修改完成，则返回
  if(!System::String::IsNullOrEmpty(TB_End->Text))  return;
  //如果修改没有完成，改回原来的数据
  TB_End->Text = tmpend;
  }

bool g_img_code = true;
bool g_img_vm = true;

System::Void dlg::StartSelectMem()
  {
  this->Visible = false;
  SelectMem^ sm = gcnew SelectMem;
  const bool needchange = sm->ShowDialog() == ::DialogResult::OK;
  this->Visible = true;

  if(!needchange) return;

  TB_Start->Text = sm->DGV_mem->SelectedRows[0]->Cells[0]->Value->ToString();

  TB_End->Text = sm->DGV_mem->SelectedRows[0]->Cells[1]->Value->ToString();
  }

System::Void dlg::Btn_Mod_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);

  g_img_code = RB_Image->Checked;
  g_img_vm = true;

  StartSelectMem();
  }

System::Void dlg::Btn_VM_Click(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);

  g_img_code = RB_Image->Checked;
  g_img_vm = false;

  StartSelectMem();
  }