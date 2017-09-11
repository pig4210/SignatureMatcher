#include "SelectMem.h"

#include <string>
#include <vector>

#include <gcroot.h>

#include <xlib.h>

using namespace std;
using namespace SignatureMatcher;


extern bool g_img_code;
extern bool g_img_vm;

System::Void SelectMem::SelectMem_Load(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  xmsg msg;

  if(g_img_vm)
    {
    ModuleSnap ms;
    for(auto m : ms)
      {
      int index = DGV_mem->Rows->Add();
      msg.clear();
      msg << (void*)m.modBaseAddr;
      DGV_mem->Rows[index]->Cells[0]->Value = gcnew System::String(msg.c_str());
      const pe tmppe(m.hModule);
      const xblk blk(g_img_code ? tmppe.GetImage() : tmppe.GetCode());
      msg.clear();
      msg << blk.end();
      DGV_mem->Rows[index]->Cells[1]->Value = gcnew System::String(msg.c_str());

      DGV_mem->Rows[index]->Cells[2]->Value = gcnew System::String(m.szExePath);
      }
#ifdef _WIN64
    Snapshot<
      MODULEENTRY32,
      Module32First,
      Module32Next,
      TH32CS_SNAPMODULE32> mms;
    for(auto m : mms)
      {

      int index = DGV_mem->Rows->Add();
      msg.clear();
      msg << (void*)m.modBaseAddr;
      DGV_mem->Rows[index]->Cells[0]->Value = gcnew System::String(msg.c_str());

      const pe tmppe(m.hModule);
      const xblk blk(g_img_code ? tmppe.GetImage() : tmppe.GetCode());
      msg.clear();
      msg << blk.end();
      DGV_mem->Rows[index]->Cells[1]->Value = gcnew System::String(msg.c_str());

      DGV_mem->Rows[index]->Cells[2]->Value = gcnew System::String(m.szExePath);
      }
#endif
    }
  else
    {
    vector<xblk> vblk;

    MEMORY_BASIC_INFORMATION mbi;

    void* mem = nullptr;

    bool ignore = true;

    size_t size = 0;

    for(void* lp = 0;
        (VirtualQueryEx(GetCurrentProcess(), lp, &mbi, sizeof(mbi)) == sizeof(MEMORY_BASIC_INFORMATION));
        lp = (void*)((size_t)lp + mbi.RegionSize), size += mbi.RegionSize
        )
      {

      void* const nowmem = (mbi.State & MEM_FREE) ? mbi.BaseAddress : mbi.AllocationBase;

      if(mem != nowmem)
        {
        if(!ignore)
          {
          vblk.push_back(xblk(mem, size));
          }
        mem = nowmem;
        size = 0;
        }

      ignore = false;

      if(!(mbi.State & (MEM_COMMIT | MEM_RESERVE)))
        {
        ignore = true;
        continue;
        }
      }
    
    char modname[MAX_PATH];

    for(auto blk : vblk)
      {
      int index = DGV_mem->Rows->Add();
      msg.clear();
      msg << (void*)blk.start();
      DGV_mem->Rows[index]->Cells[0]->Value = gcnew System::String(msg.c_str());

      msg.clear();
      msg << blk.end();
      DGV_mem->Rows[index]->Cells[1]->Value = gcnew System::String(msg.c_str());

      modname[0] = '\0';

      HMODULE hmod = nullptr;
      if(GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
        (LPCWSTR)blk.start(), &hmod))
        {
        GetModuleFileNameA(hmod, (LPSTR)&modname, sizeof(modname));

        DGV_mem->Rows[index]->Cells[2]->Value = gcnew System::String(modname);
        }
      }
    }

  }

System::Void SelectMem::DGV_mem_DoubleClick(System::Object^  sender, System::EventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  this->DialogResult = ::DialogResult::OK;
  Close();
  }

System::Void SelectMem::DGV_mem_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
  {
  UNREFERENCED_PARAMETER(sender);
  UNREFERENCED_PARAMETER(e);
  if(e->KeyData == Keys::Enter)
    {
    e->Handled = true;

    this->DialogResult = ::DialogResult::OK;
    Close();
    }
  }