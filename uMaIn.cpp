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
	timer = new TElapsedTime();

	m_Client = new TMQClient( );
	m_Client->OnMQMsgEvent = OnMessage;
	m_Client->OnMQLogEvent = OnLogMessage;

	mMessageCount = 0;

	Button1->Enabled = true;
	Button2->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::OnLogMessage(System::UnicodeString log)
{
	String time = Now().FormatString("HH:nn:ss");

	Memo2->Lines->Add( time + " || LOG :>> " + log );

//	timer->End();
//	Memo2->Lines->Add( timer->Performance() );


	if(log == "Connection failed..")
	{
		Timer1->Enabled = true;
	}
}

void __fastcall TfrmMain::OnMessage(System::TDateTime msgTime, System::UnicodeString msgBody)
{
	// 메시지 받는 부분 처리
	Memo1->Lines->Add( msgBody );

	++mMessageCount;

	Label1->Caption = String().sprintf( L"Count : %d" , mMessageCount);
}

void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
	Button1->Enabled = false;
	Button2->Enabled = true;

	mMessageCount = 0;

	timer->Start();

	m_Client->MQStart();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	m_Client->MQEnd();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button2Click(TObject *Sender)
{
	Button1->Enabled = true;
	Button2->Enabled = false;

	m_Client->MQEnd();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ReConnect( )
{
	m_Client->MQEnd();

	m_Client == NULL;

	m_Client = new TMQClient( );
	m_Client->OnMQMsgEvent = OnMessage;
	m_Client->OnMQLogEvent = OnLogMessage;

	Button1->Enabled = false;
	Button2->Enabled = true;

	mMessageCount = 0;

	m_Client->MQStart();
}


void __fastcall TfrmMain::Button3Click(TObject *Sender)
{
	ReConnect( );
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Timer1Timer(TObject *Sender)
{
	Timer1->Enabled = false;

	ReConnect( );
}
//---------------------------------------------------------------------------

