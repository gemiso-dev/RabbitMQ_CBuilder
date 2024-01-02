# Stomp Protocol 샘플 프로그램

* Stomp 규약을 통한 데이터 수신을 위해 최소한의 컴포넌트를 사용을 줄이고자 적용
* 32bit와 64bit 버전 동작확인 - 완료
* C++ 프로젝트에서 pas 파일를 추가하고 빌드를 먼저 하면 hpp 자동으로 생성

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
 	// dummy 는 라우트 키로 변경 가능
	FSTOMPClient.Subscribe('/topic/dummy',
   	 amAuto,
    	StompUtils.Headers.Add('include-seq', 'seq'));

## C++ 사용하기
샘플 코드 참고

	// 생성자
	TMQClient * m_Client = new TMQClient();
	m_Client->OnMQMsgEvent = OnMessage;
	m_Client->MQStart();

	// 데이터 받는 함수
	void __fastcall TfrmMain::OnMessage(System::TDateTime msgTime, System::UnicodeString msgBody)
	{
		Memo1->Lines->Add( msgBody );
	}

	// 접속 종료
	m_Client->MQEnd();
 	delete m_Client;

## 환경 설정 파일 추가

[Stomp.ini]

	[StompClient]
	Host=3.35.135.94			// Host 정보
	Port=61613				// Stomp 포트
	User=rabbitmq				// 접속 사용자 정보
	Password=rabbitmq			// 접속 사용자 패스워드
	Subscribe=/topic/dummy			// topic의 route : dummy 
 
 
# 빌드
StompClient.pas 와 StompClientWrapper.pas 프로젝트에 추가하고 먼저 빌드를 하면 hpp 파일이 자동 생성

* 옵션
 ![image](https://github.com/gemiso-dev/RabbitMQ_CBuilder/assets/77775575/a9e8e287-5c2f-4ffd-9d25-e1d0de9c9e5d)



 # RabbitMQ 사용

 ## 개발 서버 접속 정보

 http://3.35.135.94:15672
 (rabbitmq/rabbitmq)
 

 ## 프로그램 접속 성공
 
![image](https://github.com/gemiso-dev/RabbitMQ_CBuilder/assets/77775575/03842135-6afa-48df-ac00-2ffb590ed6e0)

접속 성공하면 위와 같이 접속 된것을 확인 할 수 있음


## Routing Key

* Subscribe에 입력한 정보를 입력하고 Publish message 보내면 끝
  
![image](https://github.com/gemiso-dev/RabbitMQ_CBuilder/assets/77775575/41675f69-2bf5-4b91-b59a-281be44111d6)


다음과 같이 프로그램에 수신 받을 수 있음

![image](https://github.com/gemiso-dev/RabbitMQ_CBuilder/assets/77775575/bcc041c1-2eb1-41db-97db-1a456e9a3b30)
