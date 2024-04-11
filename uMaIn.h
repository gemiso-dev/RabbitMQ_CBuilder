//---------------------------------------------------------------------------

#ifndef uMaInH
#define uMaInH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "StompClientWrapper.hpp"

#include "uElapsedTime.h"
#include <Vcl.ExtCtrls.hpp>

//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TMemo *Memo1;
	TLabel *Label1;
	TMemo *Memo2;
	TButton *Button3;
	TTimer *Timer1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
	TMQClient * m_Client;

    int mMessageCount;
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);

	void __fastcall OnLogMessage(System::UnicodeString log);
	void __fastcall OnMessage(System::TDateTime msgTime, System::UnicodeString msgBody) ;


	TElapsedTime * timer; //= new TElapsedTime();
    void __fastcall ReConnect( );
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
