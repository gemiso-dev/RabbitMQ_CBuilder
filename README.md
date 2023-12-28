* 32bit와 64bit 버전 동작확인 - 완료
* Stomp 규약을 통한 데이터 수신을 위해 최소한의 컴포넌트를 사용을 줄이고자 적용
* IDE 
RADStudio 10.2.3(Tokyo)
RAD Studio 11.3 (Alexandria)


1. 기본 Stomp 프로토콜 사용하기 위한 클래스
StompClient.pas 

3. 연결하기 위한 코드 정보
StompClientWrapper.pas

4. C++ 사용하기

TMQClient * m_Client = new TMQClient();
m_Client->OnMQMsgEvent = OnMessage;
m_Client->MQStart();


void __fastcall TfrmMain::OnMessage(System::TDateTime msgTime, System::UnicodeString msgBody)
{
	Memo1->Lines->Add( msgBody );
}


// 종료
m_Client->MQEnd();
