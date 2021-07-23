//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
exit(0);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
Form4->ShowModal();        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
char SysDir[_MAX_PATH], *CtrlDir;
 GetSystemDirectory(SysDir, _MAX_PATH);
 CtrlDir = ((AnsiString)SysDir + "\\Control.exe Timedate.cpl").c_str();

 WinExec(CtrlDir, SW_SHOWNORMAL);
        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
char SysDir[_MAX_PATH], *CtrlDir;
 GetSystemDirectory(SysDir, _MAX_PATH);
 CtrlDir = ((AnsiString)SysDir + "\\Control.exe PRINTERS").c_str();

 WinExec(CtrlDir, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
Form5->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 char WinDir[_MAX_PATH], *CtrlDir;
 GetWindowsDirectory(WinDir, _MAX_PATH);
 CtrlDir = ((AnsiString)WinDir + "\\Fonts\\").c_str();

 ShellExecute(Form1->Handle, NULL , CtrlDir, "", "", SW_SHOWMAXIMIZED);
       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
char SysDir[_MAX_PATH], *CtrlDir;
 GetSystemDirectory(SysDir, _MAX_PATH);
 CtrlDir = ((AnsiString)SysDir +
            "\\rundll32.exe shell32.dll,Control_RunDLL main.cpl @1").c_str();

 WinExec(CtrlDir, SW_SHOWNORMAL);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
 char SysDir[_MAX_PATH], *CtrlDir;
 GetSystemDirectory(SysDir, _MAX_PATH);
 CtrlDir = ((AnsiString)SysDir + "\\Control.exe main.cpl").c_str();

 WinExec(CtrlDir, SW_SHOWNORMAL);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
 char SysDir[_MAX_PATH], *CtrlDir;
 GetSystemDirectory(SysDir, _MAX_PATH);
 CtrlDir = ((AnsiString)SysDir +
            "\\rundll32.exe shell32.dll,Control_RunDLL main.cpl @1").c_str();

 WinExec(CtrlDir, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------


