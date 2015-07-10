#include <string>
#include <fstream>
#include <vector>
#include <map>

#include <xlib.h>

#include "SignatureMatcher.h"

using namespace std;

void showinfo(const char* const buf);

extern bool g_file_sig;

extern string g_filename;
extern line g_signature;

extern bool g_create_atom;
extern bool g_cx11;
extern xblk g_blk;

class mathcer_log : public xmsg
  {
  public:
    virtual ~mathcer_log()
      {
      if(empty()) return;
      append("\r\n");
      showinfo(c_str());
      clear();
      }
  };

#define mlog mathcer_log()


static vector<xblk> g_blks;

static signaturematcher::REPORT g_report;

static bool match_report(const signaturematcher::REPORT& rep)
  {
  if(rep.empty())
    {
    mlog << "匹配失败";
    return false;
    }
  for(auto node : rep)
    {
    xmsg msg;
    msg << ">>\t" << node.first << "\t=\t";
    signaturematcher::REPORT_VALUE& rv = node.second.values;
    switch(rv.t)
      {
      case 'q': msg << rv.q;  break;
      case 'd': msg << rv.d;  break;
      case 'w': msg << rv.w;  break;
      case 'b': msg << rv.b;  break;
      case 'p': msg << rv.p;  break;
      default:  msg << rv.q;  break;
      }
    mlog << msg;

    if(!report_add(g_report, node.first, node.second))
      {
      mlog << "加入结果失败";
      g_report.clear();
      return false;
      }
    }
  return true;
  }

static bool match_routine(signaturematcher::ScriptNode sn, void*)
  {
  if(sn.type == signaturematcher::ST_Blk)
    {
    g_blks = signaturematcher::analy_blk(sn.sig);
    if(g_blks.empty())
      {
      mlog << "解析范围指示失败：" << sn.sig;
      return false;
      }
    return true;
    }

  if(sn.type == signaturematcher::ST_Atom)
    {
    while(!sn.atom.empty())
      {
      const DWORD atom_start_time = GetTickCount();
      if(!match_report(signaturematcher::match(g_blks, sn.atom)))  return true;
      mlog << "\t\t\t\t\t\t\t\t" << (int)(GetTickCount() - atom_start_time) << "ms";
      }
    return true;
    }

  if(sn.type != signaturematcher::ST_Sign)
    {
    mlog << "未知类型：" << sn.type;
    return false;
    }

  const DWORD sign_start_time = GetTickCount();
  if(!match_report(signaturematcher::match(g_blks, sn.sig.c_str())))
    {
    mlog << "\r\n" << sn.sig << "\r\n";
    return true;
    }
  mlog << "\t\t\t\t\t\t\t\t" << (int)(GetTickCount() - sign_start_time) << "ms";

  return true;
  }

DWORD WINAPI Thd_Match(PVOID lParam)
  {
  UNREFERENCED_PARAMETER(lParam);
  XLIB_TRY
    {
    const DWORD start_time = GetTickCount();
    mlog << "\r\n\r\n------------------------匹配工作开始------------------------\r\n";
    if(g_file_sig)
      {
      ifstream file(g_filename.c_str(), ios::in | ios::binary);

      if(!file)
        {
        file.close();
        mlog << "无法打开或读取指定的特征码文件:" << g_filename;
        return 0;
        }

      file.seekg(0, ios::end);
      const unsigned int filelen = file.tellg();
      if(filelen == 0)
        {
        file.close();
        mlog << "指定的特征码文件:" << g_filename << "内容为空";
        return 0;
        }
      file.seekg(0, ios::beg);
      g_signature.clear();
      g_signature.reserve(filelen);
      file.read((char*)g_signature.end()._Ptr, filelen);
      g_signature.append(g_signature.end()._Ptr, filelen);
      file.close();

      if(g_create_atom)
        {
        const DWORD atom_start_time = GetTickCount();
        line sig(g_signature);
        const line atoms(signaturematcher::create_atom_by_script(sig));
        if(!atoms.empty())
          {
          string atomname(g_filename);
          const size_t pos = atomname.find_last_of('.');
          if(pos != string::npos)
            {
            atomname.erase(pos);
            }
          atomname.append(".atom");

          ofstream of(atomname.c_str(), ios::out | ios::binary);
          of.write((const char*)atoms.c_str(), atoms.size());
          of.close();
          mlog << "成功解析并写入中间原子文件("
            << (int)(GetTickCount() - atom_start_time)
            << "ms)："<< atomname << "\r\n";
          }
        }
      }

    if(g_blk.start() == nullptr)
      {
      pe tmppe(GetModuleHandle(nullptr));
      g_blk = tmppe.GetImage();
      }

    g_blks.clear();
    g_blks.push_back(g_blk);

    g_report.clear();

    signaturematcher::analy_script(g_signature, match_routine, nullptr);

    if(g_file_sig && !g_report.empty())
      {
      const DWORD h_start_time = GetTickCount();
      xmsg s64, s32, s16, s8, sp;
      const size_t max_name_len = 46;
      for(auto rep : g_report)
        {
        signaturematcher::REPORT_VALUE& rv = rep.second.values;
        xmsg* lpmsg = nullptr;
        xmsg var;
        switch(rv.t)
          {
          case 'q': lpmsg = &s64; var << rv.q;   break;
          case 'd': lpmsg = &s32; var << rv.d;  break;
          case 'w': lpmsg = &s16; var << rv.w;  break;
          case 'b': lpmsg = &s8; var << rv.b;  break;
          case 'p': lpmsg = &sp; var << rv.p;  break;
          default: lpmsg = &s64; var << rv.q;  break;
          }

        if(!(*lpmsg).empty()) (*lpmsg) << "\r\n";
        (*lpmsg) << "  " << rep.first;
        if(rep.first.size() < max_name_len)
          {
          (*lpmsg).append(max_name_len - rep.first.size(),' ');
          }
        (*lpmsg) << "  =  0x" << var << ",";
        if(!rep.second.note.empty())  (*lpmsg) << "  //" << rep.second.note;
        }

      xmsg hmsg;
      hmsg << "#pragma once\r\n\r\n";
      if(g_cx11)
        {
        if(!s64.empty()) hmsg << "enum : unsigned __int64\r\n  {\r\n" << s64 << "\r\n  };\r\n\r\n";
        if(!sp.empty()) hmsg << "enum : size_t\r\n  {\r\n" << sp << "\r\n  };\r\n\r\n";
        if(!s32.empty()) hmsg << "enum : unsigned __int32\r\n  {\r\n" << s32 << "\r\n  };\r\n\r\n";
        if(!s16.empty()) hmsg << "enum : unsigned __int16\r\n  {\r\n" << s16 << "\r\n  };\r\n\r\n";
        if(!s8.empty()) hmsg << "enum : unsigned __int8\r\n  {\r\n" << s8 << "\r\n  };";
        }
      else
        {
        hmsg << "enum\r\n  {";
        if(!s64.empty()) hmsg << "\r\n" << s64;
        if(!sp.empty()) hmsg << "\r\n" << sp;
        if(!s32.empty()) hmsg << "\r\n" << s32;
        if(!s16.empty()) hmsg << "\r\n" << s16;
        if(!s8.empty()) hmsg << "\r\n" << s8;
        hmsg << "\r\n  };";
        }

      string hname(g_filename);
      const size_t pos = hname.find_last_of('.');
      if(pos != string::npos)
        {
        hname.erase(pos);
        }
      hname.append(".h");

      ofstream of(hname.c_str(), ios::out | ios::binary);
      of.write((const char*)hmsg.c_str(), hmsg.size());
      of.close();
      mlog << "成功写入H文件("
        << (int)(GetTickCount() - h_start_time)
        << "ms)：" << hname;

      }

    const DWORD end_time = GetTickCount();
    
    mlog << "\r\n------------------------匹配工作结束------------------------\t"
      << (int)(end_time - start_time) << "ms";
    return 0;
    }
  XLIB_CATCH
    {
    ;
    }
  mlog << "----------------匹配工作出现未知异常，失败！----------------";
  return 0;
  }