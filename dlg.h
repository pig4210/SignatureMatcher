#pragma once

namespace SignatureMatcher
  {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;

  /// <summary>
  /// dlg 摘要
  /// </summary>
  public ref class dlg : public System::Windows::Forms::Form
    {
    public:
      dlg(void)
        {
        InitializeComponent();
        //
        //TODO:  在此处添加构造函数代码
        //
        }

    protected:
      /// <summary>
      /// 清理所有正在使用的资源。
      /// </summary>
      ~dlg()
        {
        if(components)
          {
          delete components;
          }
        }

    private: System::Windows::Forms::ToolTip^  tp;

    private: System::Windows::Forms::Button^  Btn_Close;
    private: System::Windows::Forms::Button^  Btn_Min;
    private: System::Windows::Forms::Label^  LB_Pos;
    private: System::Windows::Forms::Button^  Btn_Show;
    public: System::Windows::Forms::TextBox^  TB_mem;
    private:

    private: System::Windows::Forms::OpenFileDialog^  OFD_File;


    private: System::Windows::Forms::GroupBox^  GB_Main;

    private: System::Windows::Forms::RadioButton^  RB_File;
    private: System::Windows::Forms::RadioButton^  RB_Sig;
    private: System::Windows::Forms::Button^  Btn_Match;
    private: System::Windows::Forms::Button^  Btn_Hide;


    private: System::Windows::Forms::Panel^  PL_Trace;

    private: System::Windows::Forms::Label^  LB_Trace;
    private: System::Windows::Forms::RadioButton^  RB_Trace;
    private: System::Windows::Forms::RadioButton^  RB_TraceErr;
    private: System::Windows::Forms::RadioButton^  RB_NoTrace;


    private: System::Windows::Forms::Panel^  PL_File;

    private: System::Windows::Forms::Label^  LB_File;
    private: System::Windows::Forms::TextBox^  TB_File;
    private: System::Windows::Forms::Button^  Btn_File;
    private: System::Windows::Forms::CheckBox^  CB_CreateAtom;
    private: System::Windows::Forms::CheckBox^  CB_Cx11;


    private: System::Windows::Forms::Panel^  PL_Sig;

    private: System::Windows::Forms::TextBox^  TB_Start;
    private: System::Windows::Forms::Label^  LB_to;
    private: System::Windows::Forms::TextBox^  TB_End;

    private: System::Windows::Forms::TextBox^  TB_Sig;

    private: System::Windows::Forms::RadioButton^  RB_Image;
    private: System::Windows::Forms::RadioButton^  RB_Code;

    private: System::Windows::Forms::Label^  LB_Sep;

    private: System::Windows::Forms::Button^  Btn_Mod;
    private: System::Windows::Forms::Button^  Btn_VM;


    private: System::ComponentModel::IContainer^  components;

    protected:


    protected:

    private:
      /// <summary>
      /// 必需的设计器变量。
      /// </summary>


#pragma region Windows Form Designer generated code
      /// <summary>
      /// 设计器支持所需的方法 - 不要
      /// 使用代码编辑器修改此方法的内容。
      /// </summary>
      void InitializeComponent(void)
        {
        this->components = (gcnew System::ComponentModel::Container());
        System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(dlg::typeid));
        this->tp = (gcnew System::Windows::Forms::ToolTip(this->components));
        this->Btn_Close = (gcnew System::Windows::Forms::Button());
        this->Btn_Min = (gcnew System::Windows::Forms::Button());
        this->LB_Pos = (gcnew System::Windows::Forms::Label());
        this->Btn_Show = (gcnew System::Windows::Forms::Button());
        this->RB_Trace = (gcnew System::Windows::Forms::RadioButton());
        this->RB_TraceErr = (gcnew System::Windows::Forms::RadioButton());
        this->RB_NoTrace = (gcnew System::Windows::Forms::RadioButton());
        this->CB_CreateAtom = (gcnew System::Windows::Forms::CheckBox());
        this->CB_Cx11 = (gcnew System::Windows::Forms::CheckBox());
        this->TB_Start = (gcnew System::Windows::Forms::TextBox());
        this->TB_End = (gcnew System::Windows::Forms::TextBox());
        this->RB_Image = (gcnew System::Windows::Forms::RadioButton());
        this->RB_Code = (gcnew System::Windows::Forms::RadioButton());
        this->Btn_Mod = (gcnew System::Windows::Forms::Button());
        this->Btn_VM = (gcnew System::Windows::Forms::Button());
        this->TB_mem = (gcnew System::Windows::Forms::TextBox());
        this->OFD_File = (gcnew System::Windows::Forms::OpenFileDialog());
        this->GB_Main = (gcnew System::Windows::Forms::GroupBox());
        this->PL_Trace = (gcnew System::Windows::Forms::Panel());
        this->LB_Trace = (gcnew System::Windows::Forms::Label());
        this->RB_File = (gcnew System::Windows::Forms::RadioButton());
        this->RB_Sig = (gcnew System::Windows::Forms::RadioButton());
        this->Btn_Match = (gcnew System::Windows::Forms::Button());
        this->Btn_Hide = (gcnew System::Windows::Forms::Button());
        this->PL_File = (gcnew System::Windows::Forms::Panel());
        this->LB_File = (gcnew System::Windows::Forms::Label());
        this->TB_File = (gcnew System::Windows::Forms::TextBox());
        this->Btn_File = (gcnew System::Windows::Forms::Button());
        this->PL_Sig = (gcnew System::Windows::Forms::Panel());
        this->LB_to = (gcnew System::Windows::Forms::Label());
        this->TB_Sig = (gcnew System::Windows::Forms::TextBox());
        this->LB_Sep = (gcnew System::Windows::Forms::Label());
        this->GB_Main->SuspendLayout();
        this->PL_Trace->SuspendLayout();
        this->PL_File->SuspendLayout();
        this->PL_Sig->SuspendLayout();
        this->SuspendLayout();
        // 
        // tp
        // 
        this->tp->AutomaticDelay = 0;
        this->tp->AutoPopDelay = 2000;
        this->tp->BackColor = System::Drawing::Color::Gold;
        this->tp->ForeColor = System::Drawing::Color::Black;
        this->tp->InitialDelay = 500;
        this->tp->IsBalloon = true;
        this->tp->ReshowDelay = 0;
        // 
        // Btn_Close
        // 
        this->Btn_Close->BackColor = System::Drawing::Color::Brown;
        this->Btn_Close->FlatAppearance->BorderSize = 0;
        this->Btn_Close->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Fuchsia;
        this->Btn_Close->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
        this->Btn_Close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->Btn_Close->Location = System::Drawing::Point(0, 0);
        this->Btn_Close->Name = L"Btn_Close";
        this->Btn_Close->Size = System::Drawing::Size(32, 10);
        this->Btn_Close->TabIndex = 3;
        this->Btn_Close->Text = L"&X";
        this->Btn_Close->TextAlign = System::Drawing::ContentAlignment::TopLeft;
        this->tp->SetToolTip(this->Btn_Close, L"关闭(X)");
        this->Btn_Close->UseVisualStyleBackColor = false;
        this->Btn_Close->Click += gcnew System::EventHandler(this, &dlg::Btn_Close_Click);
        // 
        // Btn_Min
        // 
        this->Btn_Min->BackColor = System::Drawing::Color::Goldenrod;
        this->Btn_Min->FlatAppearance->BorderSize = 0;
        this->Btn_Min->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Lime;
        this->Btn_Min->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gold;
        this->Btn_Min->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->Btn_Min->Location = System::Drawing::Point(32, 0);
        this->Btn_Min->Name = L"Btn_Min";
        this->Btn_Min->Size = System::Drawing::Size(32, 10);
        this->Btn_Min->TabIndex = 4;
        this->Btn_Min->Text = L"&N";
        this->Btn_Min->TextAlign = System::Drawing::ContentAlignment::TopLeft;
        this->tp->SetToolTip(this->Btn_Min, L"最小化(N)");
        this->Btn_Min->UseVisualStyleBackColor = false;
        this->Btn_Min->Click += gcnew System::EventHandler(this, &dlg::Btn_Min_Click);
        // 
        // LB_Pos
        // 
        this->LB_Pos->BackColor = System::Drawing::Color::DimGray;
        this->LB_Pos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->LB_Pos->Location = System::Drawing::Point(64, 0);
        this->LB_Pos->Name = L"LB_Pos";
        this->LB_Pos->Size = System::Drawing::Size(250, 10);
        this->LB_Pos->TabIndex = 5;
        this->tp->SetToolTip(this->LB_Pos, L"拖拽移动窗口");
        this->LB_Pos->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &dlg::LB_Pos_MouseDown);
        // 
        // Btn_Show
        // 
        this->Btn_Show->BackColor = System::Drawing::Color::DarkSlateBlue;
        this->Btn_Show->FlatAppearance->BorderSize = 0;
        this->Btn_Show->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->Btn_Show->Location = System::Drawing::Point(314, 0);
        this->Btn_Show->Name = L"Btn_Show";
        this->Btn_Show->Size = System::Drawing::Size(166, 10);
        this->Btn_Show->TabIndex = 2;
        this->Btn_Show->Text = L"&D";
        this->Btn_Show->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
        this->tp->SetToolTip(this->Btn_Show, L"打开或关闭控制面板(D)");
        this->Btn_Show->UseVisualStyleBackColor = false;
        this->Btn_Show->Click += gcnew System::EventHandler(this, &dlg::Btn_Show_Click);
        this->Btn_Show->MouseHover += gcnew System::EventHandler(this, &dlg::Btn_Show_Click);
        // 
        // RB_Trace
        // 
        this->RB_Trace->AutoSize = true;
        this->RB_Trace->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->RB_Trace->Location = System::Drawing::Point(102, 1);
        this->RB_Trace->Name = L"RB_Trace";
        this->RB_Trace->Size = System::Drawing::Size(88, 16);
        this->RB_Trace->TabIndex = 1;
        this->RB_Trace->Text = L"详细信息(&L)";
        this->tp->SetToolTip(this->RB_Trace, L"将捕获最详细的匹配过程输出信息（警告：可能会严重影响运行效率）");
        this->RB_Trace->UseVisualStyleBackColor = true;
        // 
        // RB_TraceErr
        // 
        this->RB_TraceErr->AutoSize = true;
        this->RB_TraceErr->Checked = true;
        this->RB_TraceErr->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->RB_TraceErr->Location = System::Drawing::Point(200, 1);
        this->RB_TraceErr->Name = L"RB_TraceErr";
        this->RB_TraceErr->Size = System::Drawing::Size(76, 16);
        this->RB_TraceErr->TabIndex = 2;
        this->RB_TraceErr->TabStop = true;
        this->RB_TraceErr->Text = L"仅错误(&E)";
        this->tp->SetToolTip(this->RB_TraceErr, L"默认只捕获匹配过程的错误信息");
        this->RB_TraceErr->UseVisualStyleBackColor = true;
        // 
        // RB_NoTrace
        // 
        this->RB_NoTrace->AutoSize = true;
        this->RB_NoTrace->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->RB_NoTrace->Location = System::Drawing::Point(286, 1);
        this->RB_NoTrace->Name = L"RB_NoTrace";
        this->RB_NoTrace->Size = System::Drawing::Size(88, 16);
        this->RB_NoTrace->TabIndex = 3;
        this->RB_NoTrace->Text = L"No Trace(&Q)";
        this->tp->SetToolTip(this->RB_NoTrace, L"不捕获任何信息");
        this->RB_NoTrace->UseVisualStyleBackColor = true;
        // 
        // CB_CreateAtom
        // 
        this->CB_CreateAtom->AutoSize = true;
        this->CB_CreateAtom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->CB_CreateAtom->Location = System::Drawing::Point(5, 40);
        this->CB_CreateAtom->Name = L"CB_CreateAtom";
        this->CB_CreateAtom->Size = System::Drawing::Size(135, 16);
        this->CB_CreateAtom->TabIndex = 3;
        this->CB_CreateAtom->Text = L"自动生成中间原子(&A)";
        this->tp->SetToolTip(this->CB_CreateAtom, L"如果指定的文件是.sig文件，将自动生成中间原子文件");
        this->CB_CreateAtom->UseVisualStyleBackColor = true;
        // 
        // CB_Cx11
        // 
        this->CB_Cx11->AutoSize = true;
        this->CB_Cx11->Checked = true;
        this->CB_Cx11->CheckState = System::Windows::Forms::CheckState::Checked;
        this->CB_Cx11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->CB_Cx11->Location = System::Drawing::Point(146, 40);
        this->CB_Cx11->Name = L"CB_Cx11";
        this->CB_Cx11->Size = System::Drawing::Size(153, 16);
        this->CB_Cx11->TabIndex = 4;
        this->CB_Cx11->Text = L"生成C++11格式头文件(&Z)";
        this->tp->SetToolTip(this->CB_Cx11, L"避免出现QWORD无法设置枚举值的情况");
        this->CB_Cx11->UseVisualStyleBackColor = true;
        // 
        // TB_Start
        // 
        this->TB_Start->BackColor = System::Drawing::Color::Silver;
        this->TB_Start->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->TB_Start->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
        this->TB_Start->ForeColor = System::Drawing::Color::Black;
        this->TB_Start->Location = System::Drawing::Point(8, 12);
        this->TB_Start->MaxLength = 25;
        this->TB_Start->Name = L"TB_Start";
        this->TB_Start->Size = System::Drawing::Size(160, 14);
        this->TB_Start->TabIndex = 0;
        this->TB_Start->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
        this->tp->SetToolTip(this->TB_Start, L"起始地址");
        this->TB_Start->TextChanged += gcnew System::EventHandler(this, &dlg::TB_Start_TextChanged);
        // 
        // TB_End
        // 
        this->TB_End->BackColor = System::Drawing::Color::Silver;
        this->TB_End->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->TB_End->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
        this->TB_End->ForeColor = System::Drawing::Color::Black;
        this->TB_End->Location = System::Drawing::Point(211, 12);
        this->TB_End->MaxLength = 25;
        this->TB_End->Name = L"TB_End";
        this->TB_End->Size = System::Drawing::Size(160, 14);
        this->TB_End->TabIndex = 2;
        this->TB_End->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
        this->tp->SetToolTip(this->TB_End, L"结束地址");
        this->TB_End->TextChanged += gcnew System::EventHandler(this, &dlg::TB_Start_TextChanged);
        this->TB_End->Enter += gcnew System::EventHandler(this, &dlg::TB_End_Enter);
        // 
        // RB_Image
        // 
        this->RB_Image->AutoSize = true;
        this->RB_Image->Checked = true;
        this->RB_Image->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->RB_Image->Location = System::Drawing::Point(296, 40);
        this->RB_Image->Name = L"RB_Image";
        this->RB_Image->Size = System::Drawing::Size(76, 16);
        this->RB_Image->TabIndex = 4;
        this->RB_Image->TabStop = true;
        this->RB_Image->Text = L"全映像(&I)";
        this->tp->SetToolTip(this->RB_Image, L"PE全映像，非PE不判定");
        this->RB_Image->UseVisualStyleBackColor = true;
        this->RB_Image->CheckedChanged += gcnew System::EventHandler(this, &dlg::RB_Image_CheckedChanged);
        // 
        // RB_Code
        // 
        this->RB_Code->AutoSize = true;
        this->RB_Code->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->RB_Code->Location = System::Drawing::Point(296, 72);
        this->RB_Code->Name = L"RB_Code";
        this->RB_Code->Size = System::Drawing::Size(76, 16);
        this->RB_Code->TabIndex = 5;
        this->RB_Code->Text = L"代码段(&O)";
        this->tp->SetToolTip(this->RB_Code, L"PE代码段，非PE不判定");
        this->RB_Code->UseVisualStyleBackColor = true;
        // 
        // Btn_Mod
        // 
        this->Btn_Mod->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                                                    static_cast<System::Int32>(static_cast<System::Byte>(40)));
        this->Btn_Mod->FlatAppearance->BorderSize = 0;
        this->Btn_Mod->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
        this->Btn_Mod->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                             static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->Btn_Mod->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->Btn_Mod->Location = System::Drawing::Point(296, 121);
        this->Btn_Mod->Name = L"Btn_Mod";
        this->Btn_Mod->Size = System::Drawing::Size(76, 22);
        this->Btn_Mod->TabIndex = 7;
        this->Btn_Mod->Text = L"模　块(&A)";
        this->tp->SetToolTip(this->Btn_Mod, L"选择DLL模块");
        this->Btn_Mod->UseVisualStyleBackColor = false;
        this->Btn_Mod->Click += gcnew System::EventHandler(this, &dlg::Btn_Mod_Click);
        // 
        // Btn_VM
        // 
        this->Btn_VM->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                                                   static_cast<System::Int32>(static_cast<System::Byte>(40)));
        this->Btn_VM->FlatAppearance->BorderSize = 0;
        this->Btn_VM->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
        this->Btn_VM->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                            static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->Btn_VM->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->Btn_VM->Location = System::Drawing::Point(296, 159);
        this->Btn_VM->Name = L"Btn_VM";
        this->Btn_VM->Size = System::Drawing::Size(76, 22);
        this->Btn_VM->TabIndex = 8;
        this->Btn_VM->Text = L"内存块(&Z)";
        this->tp->SetToolTip(this->Btn_VM, L"选择进程内存块");
        this->Btn_VM->UseVisualStyleBackColor = false;
        this->Btn_VM->Click += gcnew System::EventHandler(this, &dlg::Btn_VM_Click);
        // 
        // TB_mem
        // 
        this->TB_mem->BackColor = System::Drawing::Color::Black;
        this->TB_mem->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->TB_mem->Cursor = System::Windows::Forms::Cursors::Default;
        this->TB_mem->Dock = System::Windows::Forms::DockStyle::Bottom;
        this->TB_mem->ForeColor = System::Drawing::Color::Silver;
        this->TB_mem->HideSelection = false;
        this->TB_mem->Location = System::Drawing::Point(0, 12);
        this->TB_mem->Multiline = true;
        this->TB_mem->Name = L"TB_mem";
        this->TB_mem->ReadOnly = true;
        this->TB_mem->ScrollBars = System::Windows::Forms::ScrollBars::Both;
        this->TB_mem->Size = System::Drawing::Size(480, 428);
        this->TB_mem->TabIndex = 0;
        this->TB_mem->WordWrap = false;
        this->TB_mem->Click += gcnew System::EventHandler(this, &dlg::Btn_Hide_Click);
        this->TB_mem->DoubleClick += gcnew System::EventHandler(this, &dlg::TB_mem_DoubleClick);
        // 
        // OFD_File
        // 
        this->OFD_File->Filter = L"特征码文件|*.sig|特征码原子文件|*.atom|所有文件|*.*";
        this->OFD_File->ReadOnlyChecked = true;
        this->OFD_File->RestoreDirectory = true;
        this->OFD_File->ShowReadOnly = true;
        // 
        // GB_Main
        // 
        this->GB_Main->BackColor = System::Drawing::Color::Black;
        this->GB_Main->Controls->Add(this->PL_Trace);
        this->GB_Main->Controls->Add(this->RB_File);
        this->GB_Main->Controls->Add(this->RB_Sig);
        this->GB_Main->Controls->Add(this->Btn_Match);
        this->GB_Main->Controls->Add(this->Btn_Hide);
        this->GB_Main->Controls->Add(this->PL_File);
        this->GB_Main->Controls->Add(this->PL_Sig);
        this->GB_Main->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->GB_Main->ForeColor = System::Drawing::Color::Silver;
        this->GB_Main->Location = System::Drawing::Point(43, 82);
        this->GB_Main->Name = L"GB_Main";
        this->GB_Main->Size = System::Drawing::Size(392, 333);
        this->GB_Main->TabIndex = 1;
        this->GB_Main->TabStop = false;
        this->GB_Main->Text = L"控制面板";
        this->GB_Main->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &dlg::GB_Main_DragDrop);
        this->GB_Main->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &dlg::GB_Main_DragEnter);
        // 
        // PL_Trace
        // 
        this->PL_Trace->BackColor = System::Drawing::Color::Black;
        this->PL_Trace->Controls->Add(this->LB_Trace);
        this->PL_Trace->Controls->Add(this->RB_NoTrace);
        this->PL_Trace->Controls->Add(this->RB_TraceErr);
        this->PL_Trace->Controls->Add(this->RB_Trace);
        this->PL_Trace->Location = System::Drawing::Point(7, 44);
        this->PL_Trace->Name = L"PL_Trace";
        this->PL_Trace->Size = System::Drawing::Size(378, 20);
        this->PL_Trace->TabIndex = 4;
        // 
        // LB_Trace
        // 
        this->LB_Trace->AutoSize = true;
        this->LB_Trace->Location = System::Drawing::Point(3, 3);
        this->LB_Trace->Name = L"LB_Trace";
        this->LB_Trace->Size = System::Drawing::Size(89, 12);
        this->LB_Trace->TabIndex = 0;
        this->LB_Trace->Text = L"Trace信息设置:";
        // 
        // RB_File
        // 
        this->RB_File->AutoSize = true;
        this->RB_File->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->RB_File->Location = System::Drawing::Point(12, 20);
        this->RB_File->Name = L"RB_File";
        this->RB_File->Size = System::Drawing::Size(124, 16);
        this->RB_File->TabIndex = 0;
        this->RB_File->Text = L"指定特征码文件(&F)";
        this->RB_File->UseVisualStyleBackColor = true;
        this->RB_File->CheckedChanged += gcnew System::EventHandler(this, &dlg::RB_File_CheckedChanged);
        // 
        // RB_Sig
        // 
        this->RB_Sig->AutoSize = true;
        this->RB_Sig->Checked = true;
        this->RB_Sig->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->RB_Sig->Location = System::Drawing::Point(147, 20);
        this->RB_Sig->Name = L"RB_Sig";
        this->RB_Sig->Size = System::Drawing::Size(100, 16);
        this->RB_Sig->TabIndex = 1;
        this->RB_Sig->TabStop = true;
        this->RB_Sig->Text = L"输入特征码(&B)";
        this->RB_Sig->UseVisualStyleBackColor = true;
        // 
        // Btn_Match
        // 
        this->Btn_Match->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                                                      static_cast<System::Int32>(static_cast<System::Byte>(40)));
        this->Btn_Match->DialogResult = System::Windows::Forms::DialogResult::OK;
        this->Btn_Match->FlatAppearance->BorderSize = 0;
        this->Btn_Match->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
        this->Btn_Match->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                               static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->Btn_Match->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->Btn_Match->Location = System::Drawing::Point(258, 17);
        this->Btn_Match->Name = L"Btn_Match";
        this->Btn_Match->Size = System::Drawing::Size(58, 22);
        this->Btn_Match->TabIndex = 2;
        this->Btn_Match->Text = L"匹配(&M)";
        this->Btn_Match->UseVisualStyleBackColor = false;
        this->Btn_Match->Click += gcnew System::EventHandler(this, &dlg::Btn_Match_Click);
        // 
        // Btn_Hide
        // 
        this->Btn_Hide->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                                                     static_cast<System::Int32>(static_cast<System::Byte>(40)));
        this->Btn_Hide->DialogResult = System::Windows::Forms::DialogResult::Cancel;
        this->Btn_Hide->FlatAppearance->BorderSize = 0;
        this->Btn_Hide->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
        this->Btn_Hide->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                              static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->Btn_Hide->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->Btn_Hide->Location = System::Drawing::Point(327, 17);
        this->Btn_Hide->Name = L"Btn_Hide";
        this->Btn_Hide->Size = System::Drawing::Size(58, 22);
        this->Btn_Hide->TabIndex = 3;
        this->Btn_Hide->Text = L"关闭(&C)";
        this->Btn_Hide->UseVisualStyleBackColor = false;
        this->Btn_Hide->Click += gcnew System::EventHandler(this, &dlg::Btn_Hide_Click);
        // 
        // PL_File
        // 
        this->PL_File->Controls->Add(this->CB_Cx11);
        this->PL_File->Controls->Add(this->CB_CreateAtom);
        this->PL_File->Controls->Add(this->LB_File);
        this->PL_File->Controls->Add(this->TB_File);
        this->PL_File->Controls->Add(this->Btn_File);
        this->PL_File->Location = System::Drawing::Point(7, 65);
        this->PL_File->Name = L"PL_File";
        this->PL_File->Size = System::Drawing::Size(379, 69);
        this->PL_File->TabIndex = 5;
        // 
        // LB_File
        // 
        this->LB_File->AutoSize = true;
        this->LB_File->Location = System::Drawing::Point(3, 12);
        this->LB_File->Name = L"LB_File";
        this->LB_File->Size = System::Drawing::Size(47, 12);
        this->LB_File->TabIndex = 0;
        this->LB_File->Text = L"文件(&S)";
        // 
        // TB_File
        // 
        this->TB_File->AllowDrop = true;
        this->TB_File->BackColor = System::Drawing::Color::Silver;
        this->TB_File->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->TB_File->ForeColor = System::Drawing::Color::Black;
        this->TB_File->Location = System::Drawing::Point(50, 12);
        this->TB_File->Name = L"TB_File";
        this->TB_File->Size = System::Drawing::Size(321, 14);
        this->TB_File->TabIndex = 1;
        this->TB_File->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &dlg::GB_Main_DragDrop);
        this->TB_File->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &dlg::GB_Main_DragEnter);
        this->TB_File->DoubleClick += gcnew System::EventHandler(this, &dlg::Btn_File_Click);
        // 
        // Btn_File
        // 
        this->Btn_File->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                                                                     static_cast<System::Int32>(static_cast<System::Byte>(40)));
        this->Btn_File->DialogResult = System::Windows::Forms::DialogResult::Cancel;
        this->Btn_File->FlatAppearance->BorderSize = 0;
        this->Btn_File->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
        this->Btn_File->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                                                                                              static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
        this->Btn_File->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->Btn_File->Location = System::Drawing::Point(314, 37);
        this->Btn_File->Name = L"Btn_File";
        this->Btn_File->Size = System::Drawing::Size(58, 22);
        this->Btn_File->TabIndex = 2;
        this->Btn_File->Text = L"打开(&O)";
        this->Btn_File->UseVisualStyleBackColor = false;
        this->Btn_File->Click += gcnew System::EventHandler(this, &dlg::Btn_File_Click);
        // 
        // PL_Sig
        // 
        this->PL_Sig->Controls->Add(this->TB_Start);
        this->PL_Sig->Controls->Add(this->LB_to);
        this->PL_Sig->Controls->Add(this->TB_End);
        this->PL_Sig->Controls->Add(this->TB_Sig);
        this->PL_Sig->Controls->Add(this->RB_Image);
        this->PL_Sig->Controls->Add(this->RB_Code);
        this->PL_Sig->Controls->Add(this->LB_Sep);
        this->PL_Sig->Controls->Add(this->Btn_Mod);
        this->PL_Sig->Controls->Add(this->Btn_VM);
        this->PL_Sig->Location = System::Drawing::Point(7, 140);
        this->PL_Sig->Name = L"PL_Sig";
        this->PL_Sig->Size = System::Drawing::Size(380, 189);
        this->PL_Sig->TabIndex = 6;
        // 
        // LB_to
        // 
        this->LB_to->AutoSize = true;
        this->LB_to->Location = System::Drawing::Point(181, 12);
        this->LB_to->Name = L"LB_to";
        this->LB_to->Size = System::Drawing::Size(17, 12);
        this->LB_to->TabIndex = 1;
        this->LB_to->Text = L"～";
        // 
        // TB_Sig
        // 
        this->TB_Sig->AcceptsReturn = true;
        this->TB_Sig->BackColor = System::Drawing::Color::Silver;
        this->TB_Sig->BorderStyle = System::Windows::Forms::BorderStyle::None;
        this->TB_Sig->ForeColor = System::Drawing::Color::Black;
        this->TB_Sig->Location = System::Drawing::Point(8, 40);
        this->TB_Sig->Multiline = true;
        this->TB_Sig->Name = L"TB_Sig";
        this->TB_Sig->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
        this->TB_Sig->Size = System::Drawing::Size(280, 141);
        this->TB_Sig->TabIndex = 3;
        // 
        // LB_Sep
        // 
        this->LB_Sep->BackColor = System::Drawing::Color::Silver;
        this->LB_Sep->Location = System::Drawing::Point(294, 104);
        this->LB_Sep->Name = L"LB_Sep";
        this->LB_Sep->Size = System::Drawing::Size(79, 1);
        this->LB_Sep->TabIndex = 6;
        // 
        // dlg
        // 
        this->AcceptButton = this->Btn_Match;
        this->AllowDrop = true;
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->BackColor = System::Drawing::Color::Black;
        this->CancelButton = this->Btn_Hide;
        this->ClientSize = System::Drawing::Size(480, 440);
        this->Controls->Add(this->GB_Main);
        this->Controls->Add(this->Btn_Close);
        this->Controls->Add(this->Btn_Min);
        this->Controls->Add(this->LB_Pos);
        this->Controls->Add(this->Btn_Show);
        this->Controls->Add(this->TB_mem);
        this->ForeColor = System::Drawing::Color::Silver;
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
        this->MaximizeBox = false;
        this->Name = L"dlg";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &dlg::dlg_FormClosing);
        this->Load += gcnew System::EventHandler(this, &dlg::dlg_Load);
        this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &dlg::GB_Main_DragDrop);
        this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &dlg::GB_Main_DragEnter);
        this->GB_Main->ResumeLayout(false);
        this->GB_Main->PerformLayout();
        this->PL_Trace->ResumeLayout(false);
        this->PL_Trace->PerformLayout();
        this->PL_File->ResumeLayout(false);
        this->PL_File->PerformLayout();
        this->PL_Sig->ResumeLayout(false);
        this->PL_Sig->PerformLayout();
        this->ResumeLayout(false);
        this->PerformLayout();

        }
#pragma endregion
    private: System::Void Btn_Show_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void Btn_Hide_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void dlg_Load(System::Object^  sender, System::EventArgs^  e);

    private: System::Void dlg_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);

    private: System::Void Btn_Close_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void Btn_Min_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void LB_Pos_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

    private: System::Void TB_Start_TextChanged(System::Object^  sender, System::EventArgs^  e);

    private: System::Void TB_mem_DoubleClick(System::Object^  sender, System::EventArgs^  e);

    private: System::Void Btn_File_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void GB_Main_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);

    private: System::Void GB_Main_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);

    private: System::Void Btn_Match_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void RB_File_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

    private: System::Void TB_End_Enter(System::Object^  sender, System::EventArgs^  e);

    private: System::Void RB_Image_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

    private: System::Void StartSelectMem();

    private: System::Void Btn_Mod_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void Btn_VM_Click(System::Object^  sender, System::EventArgs^  e);
};
  }
