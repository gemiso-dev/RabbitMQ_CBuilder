//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uMaIn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
	m_Client = new TMQClient( );
	m_Client->OnMQMsgEvent = OnMessage;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::OnMessage(System::TDateTime msgTime, System::UnicodeString msgBody)
{
	Memo1->Lines->Add( msgBody );

}

void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
	m_Client->MQStart();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
    m_Client->MQEnd();
}
//---------------------------------------------------------------------------

