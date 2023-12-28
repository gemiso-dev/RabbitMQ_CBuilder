1. 기본 Stomp 프로토콜 사용하기 위한 클래스

StompClient.pas 

2. 연결하기 위한 코드 정보
StompClientWrapper.pas

3. C++ 사용하기

TMQClient * m_Client = new TMQClient();
m_Client->OnMQMsgEvent = OnMessage;
m_Client->MQStart();


void __fastcall TfrmMain::OnMessage(System::TDateTime msgTime, System::UnicodeString msgBody)
{
	Memo1->Lines->Add( msgBody );
}


// 종료
m_Client->MQEnd();
