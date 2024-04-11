// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StompClientWrapper.pas' rev: 35.00 (Windows)

#ifndef StompclientwrapperHPP
#define StompclientwrapperHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.SysUtils.hpp>
#include <System.Variants.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.StdCtrls.hpp>
#include <StompClient.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stompclientwrapper
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TMQClient;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TMQLogEvent)(System::UnicodeString log);

typedef void __fastcall (__closure *TMQMessageEvent)(System::TDateTime msgTime, System::UnicodeString msgBody);

class PASCALIMPLEMENTATION TMQClient : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	TMQLogEvent FOnMQLogEvent;
	TMQMessageEvent FOnMQMsgEvent;
	Stompclient::_di_IStompListener FSTOMPListener;
	Stompclient::_di_IStompClient FSTOMPClient;
	bool FFormClosing;
	void __fastcall OnMessage(Stompclient::_di_IStompFrame StompFrame, bool &TerminateListener);
	void __fastcall OnListenerStopped(Stompclient::_di_IStompClient StompClient);
	
public:
	__fastcall TMQClient();
	__fastcall virtual ~TMQClient();
	void __fastcall MQStart();
	void __fastcall MQEnd();
	void __fastcall OnStompStart();
	
__published:
	__property TMQLogEvent OnMQLogEvent = {read=FOnMQLogEvent, write=FOnMQLogEvent};
	__property TMQMessageEvent OnMQMsgEvent = {read=FOnMQMsgEvent, write=FOnMQMsgEvent};
private:
	void *__IStompClientListener;	// Stompclient::IStompClientListener 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C4C0D932-8994-43FB-9D32-A03FE86AEFE4}
	operator Stompclient::_di_IStompClientListener()
	{
		Stompclient::_di_IStompClientListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Stompclient::IStompClientListener*(void) { return (Stompclient::IStompClientListener*)&__IStompClientListener; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TMQClient* MQClient;
}	/* namespace Stompclientwrapper */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STOMPCLIENTWRAPPER)
using namespace Stompclientwrapper;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StompclientwrapperHPP
