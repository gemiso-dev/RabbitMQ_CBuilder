// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StompClient.pas' rev: 35.00 (Windows)

#ifndef StompclientHPP
#define StompclientHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.DateUtils.hpp>
#include <System.IniFiles.hpp>
#include <Vcl.Dialogs.hpp>
#include <IdTCPClient.hpp>
#include <IdException.hpp>
#include <IdExceptionCore.hpp>
#include <IdHeaderList.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <System.SyncObjs.hpp>
#include <System.Classes.hpp>
#include <System.Generics.Collections.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stompclient
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EStomp;
struct TKeyValue;
class DELPHICLASS StompHeaders;
__interface DELPHIINTERFACE IStompHeaders;
typedef System::DelphiInterface<IStompHeaders> _di_IStompHeaders;
__interface DELPHIINTERFACE IStompFrame;
typedef System::DelphiInterface<IStompFrame> _di_IStompFrame;
__interface DELPHIINTERFACE IStompClient;
typedef System::DelphiInterface<IStompClient> _di_IStompClient;
struct TAddress;
__interface DELPHIINTERFACE IStompListener;
typedef System::DelphiInterface<IStompListener> _di_IStompListener;
__interface DELPHIINTERFACE IStompClientListener;
typedef System::DelphiInterface<IStompClientListener> _di_IStompClientListener;
class DELPHICLASS StompUtils;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TStompConnectNotifyEvent)(_di_IStompClient Client, _di_IStompFrame Frame);

enum DECLSPEC_DENUM TAckMode : unsigned char { amAuto, amClient, amClientIndividual };

enum DECLSPEC_DENUM TStompAcceptProtocol : unsigned char { Ver_1_0, Ver_1_1 };

#pragma pack(push,4)
class PASCALIMPLEMENTATION EStomp : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EStomp(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EStomp(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EStomp(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EStomp(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EStomp(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EStomp(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EStomp(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EStomp(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EStomp(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EStomp(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EStomp(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EStomp(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EStomp() { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TKeyValue
{
public:
	System::UnicodeString Key;
	System::UnicodeString Value;
	__fastcall TKeyValue(const System::UnicodeString Key, const System::UnicodeString Value);
	TKeyValue() {}
};


typedef void __fastcall (__closure *TSenderFrameEvent)(_di_IStompFrame AFrame);

#pragma pack(push,4)
class PASCALIMPLEMENTATION StompHeaders : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	static System::UnicodeString MESSAGE_ID;
	static System::UnicodeString TRANSACTION;
	static System::UnicodeString REPLY_TO;
	static System::UnicodeString AUTO_DELETE;
	static System::UnicodeString CONTENT_LENGTH;
	static System::UnicodeString CONTENT_TYPE;
	static System::UnicodeString RECEIPT;
	static System::UnicodeString PREFETCH_COUNT;
	static System::UnicodeString X_MESSAGE_TTL;
	static System::UnicodeString X_EXPIRES;
	static System::UnicodeString TIMESTAMP;
public:
	/* TObject.Create */ inline __fastcall StompHeaders() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~StompHeaders() { }
	
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{BD087D9D-0576-4C35-88F9-F5D6348E3894}") IStompHeaders  : public System::IInterface 
{
	virtual _di_IStompHeaders __fastcall Add(System::UnicodeString Key, System::UnicodeString Value) = 0 /* overload */;
	virtual _di_IStompHeaders __fastcall Add(const TKeyValue &HeaderItem) = 0 /* overload */;
	virtual System::UnicodeString __fastcall Value(System::UnicodeString Key) = 0 ;
	virtual _di_IStompHeaders __fastcall Remove(System::UnicodeString Key) = 0 ;
	virtual int __fastcall IndexOf(System::UnicodeString Key) = 0 ;
	virtual unsigned __fastcall Count() = 0 ;
	virtual TKeyValue __fastcall GetAt(const int index) = 0 ;
	virtual System::UnicodeString __fastcall Output() = 0 ;
};

__interface  INTERFACE_UUID("{68274885-D3C3-4890-A058-03B769B2191E}") IStompFrame  : public System::IInterface 
{
	virtual System::UnicodeString __fastcall Output() = 0 ;
	virtual System::DynamicArray<System::Byte> __fastcall OutputBytes() = 0 ;
	virtual void __fastcall SetHeaders(const _di_IStompHeaders Value) = 0 ;
	virtual System::UnicodeString __fastcall GetCommand() = 0 ;
	virtual void __fastcall SetCommand(const System::UnicodeString Value) = 0 ;
	virtual System::UnicodeString __fastcall GetBody() = 0 ;
	virtual void __fastcall SetBody(const System::UnicodeString Value) = 0 ;
	__property System::UnicodeString Body = {read=GetBody, write=SetBody};
	virtual System::DynamicArray<System::Byte> __fastcall GetBytesBody() = 0 ;
	virtual void __fastcall SetBytesBody(const System::DynamicArray<System::Byte> Value) = 0 ;
	__property System::DynamicArray<System::Byte> BytesBody = {read=GetBytesBody, write=SetBytesBody};
	virtual _di_IStompHeaders __fastcall GetHeaders() = 0 ;
	virtual System::UnicodeString __fastcall MessageID() = 0 ;
	virtual int __fastcall ContentLength() = 0 ;
	virtual System::UnicodeString __fastcall ReplyTo() = 0 ;
	__property _di_IStompHeaders Headers = {read=GetHeaders, write=SetHeaders};
	__property System::UnicodeString Command = {read=GetCommand, write=SetCommand};
};

__interface  INTERFACE_UUID("{EDE6EF1D-59EE-4FCC-9CD7-B183E606D949}") IStompClient  : public System::IInterface 
{
	virtual bool __fastcall Receive(/* out */ _di_IStompFrame &StompFrame, int ATimeout) = 0 /* overload */;
	virtual _di_IStompFrame __fastcall Receive() = 0 /* overload */;
	virtual _di_IStompFrame __fastcall Receive(int ATimeout) = 0 /* overload */;
	virtual void __fastcall Receipt(const System::UnicodeString ReceiptID) = 0 ;
	virtual _di_IStompClient __fastcall SetHost(System::UnicodeString Host) = 0 ;
	virtual _di_IStompClient __fastcall SetPort(int Port) = 0 ;
	virtual _di_IStompClient __fastcall SetVirtualHost(System::UnicodeString VirtualHost) = 0 ;
	virtual _di_IStompClient __fastcall SetClientId(System::UnicodeString ClientId) = 0 ;
	virtual _di_IStompClient __fastcall SetAcceptVersion(TStompAcceptProtocol AcceptVersion) = 0 ;
	virtual _di_IStompClient __fastcall Connect() = 0 ;
	virtual _di_IStompClient __fastcall Clone() = 0 ;
	virtual void __fastcall Disconnect() = 0 ;
	virtual void __fastcall Subscribe(System::UnicodeString QueueOrTopicName, TAckMode Ack = (TAckMode)(0x0), _di_IStompHeaders Headers = _di_IStompHeaders()) = 0 ;
	virtual void __fastcall Unsubscribe(System::UnicodeString Queue, const System::UnicodeString subscriptionId = System::UnicodeString()) = 0 ;
	virtual void __fastcall Send(System::UnicodeString QueueOrTopicName, System::UnicodeString TextMessage, _di_IStompHeaders Headers = _di_IStompHeaders()) = 0 /* overload */;
	virtual void __fastcall Send(System::UnicodeString QueueOrTopicName, System::UnicodeString TextMessage, System::UnicodeString TransactionIdentifier, _di_IStompHeaders Headers = _di_IStompHeaders()) = 0 /* overload */;
	virtual void __fastcall Send(System::UnicodeString QueueOrTopicName, System::DynamicArray<System::Byte> ByteMessage, _di_IStompHeaders Headers = _di_IStompHeaders()) = 0 /* overload */;
	virtual void __fastcall Send(System::UnicodeString QueueOrTopicName, System::DynamicArray<System::Byte> ByteMessage, System::UnicodeString TransactionIdentifier, _di_IStompHeaders Headers = _di_IStompHeaders()) = 0 /* overload */;
	virtual void __fastcall Ack(const System::UnicodeString MessageID, const System::UnicodeString subscriptionId = System::UnicodeString(), const System::UnicodeString TransactionIdentifier = System::UnicodeString()) = 0 ;
	virtual void __fastcall Nack(const System::UnicodeString MessageID, const System::UnicodeString subscriptionId = System::UnicodeString(), const System::UnicodeString TransactionIdentifier = System::UnicodeString()) = 0 ;
	virtual void __fastcall BeginTransaction(const System::UnicodeString TransactionIdentifier) = 0 ;
	virtual void __fastcall CommitTransaction(const System::UnicodeString TransactionIdentifier) = 0 ;
	virtual void __fastcall AbortTransaction(const System::UnicodeString TransactionIdentifier) = 0 ;
	virtual _di_IStompClient __fastcall SetUseSSL(const bool boUseSSL, const bool PassThrough = true, const System::UnicodeString KeyFile = System::UnicodeString(), const System::UnicodeString CertFile = System::UnicodeString(), const System::UnicodeString PassPhrase = System::UnicodeString()) = 0 ;
	virtual _di_IStompClient __fastcall SetPassword(const System::UnicodeString Value) = 0 ;
	virtual _di_IStompClient __fastcall SetUserName(const System::UnicodeString Value) = 0 ;
	virtual _di_IStompClient __fastcall SetReceiveTimeout(const unsigned AMilliSeconds) = 0 ;
	virtual _di_IStompClient __fastcall SetHeartBeat(const __int64 OutgoingHeartBeats, const __int64 IncomingHeartBeats) = 0 ;
	virtual bool __fastcall Connected() = 0 ;
	virtual System::UnicodeString __fastcall GetProtocolVersion() = 0 ;
	virtual System::UnicodeString __fastcall GetServer() = 0 ;
	virtual System::UnicodeString __fastcall GetSession() = 0 ;
	virtual _di_IStompClient __fastcall SetConnectionTimeout(const unsigned Value) = 0 ;
	virtual _di_IStompClient __fastcall SetOnBeforeSendFrame(const TSenderFrameEvent Value) = 0 ;
	virtual _di_IStompClient __fastcall SetOnAfterSendFrame(const TSenderFrameEvent Value) = 0 ;
	virtual _di_IStompClient __fastcall SetOnHeartBeatError(const System::Classes::TNotifyEvent Value) = 0 ;
	virtual TStompConnectNotifyEvent __fastcall GetOnConnect() = 0 ;
	virtual void __fastcall SetOnConnect(const TStompConnectNotifyEvent Value) = 0 ;
	__property TStompConnectNotifyEvent OnConnect = {read=GetOnConnect, write=SetOnConnect};
};

struct DECLSPEC_DRECORD TAddress
{
public:
	System::UnicodeString Host;
	int Port;
	System::UnicodeString UserName;
	System::UnicodeString Password;
};


typedef System::DynamicArray<TAddress> TAddresses;

__interface  INTERFACE_UUID("{CB3EB297-8616-408E-A0B2-7CCC11224DBC}") IStompListener  : public System::IInterface 
{
	virtual void __fastcall StopListening() = 0 ;
	virtual void __fastcall StartListening() = 0 ;
};

__interface  INTERFACE_UUID("{C4C0D932-8994-43FB-9D32-A03FE86AEFE4}") IStompClientListener  : public System::IInterface 
{
	virtual void __fastcall OnMessage(_di_IStompFrame StompFrame, bool &TerminateListener) = 0 ;
	virtual void __fastcall OnListenerStopped(_di_IStompClient StompClient) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION StompUtils : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod _di_IStompClient __fastcall StompClient();
	__classmethod _di_IStompClient __fastcall StompClientAndConnect(System::UnicodeString Host = L"127.0.0.1", int Port = 0xf0ad, System::UnicodeString VirtualHost = System::UnicodeString(), System::UnicodeString ClientID = System::UnicodeString(), TStompAcceptProtocol AcceptVersion = (TStompAcceptProtocol)(0x0));
	__classmethod TKeyValue __fastcall NewDurableSubscriptionHeader(const System::UnicodeString SubscriptionName);
	__classmethod TKeyValue __fastcall NewPersistentHeader(const bool Value);
	__classmethod TKeyValue __fastcall NewReplyToHeader(const System::UnicodeString DestinationName);
	__classmethod _di_IStompListener __fastcall CreateListener(const _di_IStompClient StompClient, const _di_IStompClientListener StompClientListener);
	__classmethod System::UnicodeString __fastcall StripLastChar(System::UnicodeString Buf);
	__classmethod _di_IStompFrame __fastcall CreateFrame();
	__classmethod _di_IStompFrame __fastcall CreateFrameWithBuffer(System::UnicodeString Buf)/* overload */;
	__classmethod _di_IStompFrame __fastcall CreateFrameWithBuffer(System::DynamicArray<System::Byte> Buf)/* overload */;
	__classmethod System::UnicodeString __fastcall AckModeToStr(TAckMode AckMode);
	__classmethod _di_IStompHeaders __fastcall NewHeaders _DEPRECATED_ATTRIBUTE1("Use Headers instead") ();
	__classmethod _di_IStompHeaders __fastcall Headers();
	__classmethod _di_IStompFrame __fastcall NewFrame();
	__classmethod System::TDateTime __fastcall TimestampAsDateTime(const System::UnicodeString HeaderValue);
public:
	/* TObject.Create */ inline __fastcall StompUtils() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~StompUtils() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::WideChar LINE_END;
extern DELPHI_PACKAGE System::Byte BYTE_LINE_END;
extern DELPHI_PACKAGE System::WideChar COMMAND_END;
#define DEFAULT_STOMP_HOST L"127.0.0.1"
static const System::Word DEFAULT_STOMP_PORT = System::Word(0xf0ad);
static const System::Word DEFAULT_STOMP_TLS_PORT = System::Word(0xf0ae);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ReadIniString(System::UnicodeString Key);
extern DELPHI_PACKAGE int __fastcall ReadIniInteger(System::UnicodeString Key);
}	/* namespace Stompclient */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STOMPCLIENT)
using namespace Stompclient;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StompclientHPP
