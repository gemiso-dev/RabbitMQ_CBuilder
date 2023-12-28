//---------------------------------------------------------------------------

#ifndef uMaInH
#define uMaInH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "StompClientWrapper.hpp"

//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TMemo *Memo1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	TMQClient * m_Client;
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
	void __fastcall OnMessage(System::TDateTime msgTime, System::UnicodeString msgBody) ;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
