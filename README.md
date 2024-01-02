# Stomp Protocol
* Stomp 규약을 통한 데이터 수신을 위해 최소한의 컴포넌트를 사용을 줄이고자 적용
* 32bit와 64bit 버전 동작확인 - 완료

# IDE 
* RAD Studio 10.2.3 (Tokyo)
* RAD Studio 11.3 (Alexandria)

# 코드 정보

## StompClient.pas 
기본 Stomp 프로토콜 사용하기 위한 클래스

	const
	  LINE_END: char = #10;
	  BYTE_LINE_END: Byte = 10;
	  COMMAND_END: char = #0;
	  DEFAULT_STOMP_HOST = '127.0.0.1';	// 주소 정보를 변경
	  DEFAULT_STOMP_PORT = 61613;
	  DEFAULT_STOMP_TLS_PORT = 61614;


접속 유저명과 패스워드를 변경한다.

	constructor TStompClient.Create;
	begin
	  inherited;
	  FLock := TObject.Create;
	  FInTransaction := False;
	  FSession := '';
	  FUserName := 'admin';			// 사용자 정보 변경
	  FPassword := 'admin';			// 사용자 패스워드
	  FUseSSL := false;
	  FHeaders := TStompHeaders.Create;
	  FTimeout := 200;
	  FReceiptTimeout := FTimeout;
	  FConnectionTimeout := 1000 * 10; // 10secs
	  FIncomingHeartBeats := 10000; // 10secs
	  FOutgoingHeartBeats := 0; // disabled
	
	  FHost := '127.0.0.1';
	  FPort := DEFAULT_STOMP_PORT;
	  FVirtualHost := '';
	  FClientID := '';
	  FAcceptVersion := TStompAcceptProtocol.Ver_1_0;
	end;

## StompClientWrapper.pas
Stomp 연결하기 위한 코드 정보

	  // topic , Route dummy
	  FSTOMPClient.Subscribe('/topic/dummy',
   	 amAuto,
    	StompUtils.Headers.Add('include-seq', 'seq'));

## C++ 사용하기

	TMQClient * m_Client = new TMQClient();
	m_Client->OnMQMsgEvent = OnMessage;
	m_Client->MQStart();


	void __fastcall TfrmMain::OnMessage(System::TDateTime msgTime, System::UnicodeString msgBody)
	{
		Memo1->Lines->Add( msgBody );
	}

	// 종료
	m_Client->MQEnd();
