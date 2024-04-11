unit StompClientWrapper;

interface

uses
  Winapi.Windows,
  Winapi.Messages,
  System.SysUtils,
  System.Variants,
  System.Classes,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  Vcl.StdCtrls,
  StompClient;

type
  TMQLogEvent = procedure (log: String) of object;
  TMQMessageEvent = procedure (msgTime: TDateTime; msgBody: String) of object;

type
  TMQClient = class(TInterfacedObject, IStompClientListener)

 private
    FOnMQLogEvent: TMQLogEvent;
    FOnMQMsgEvent: TMQMessageEvent;
    FSTOMPListener: IStompListener;
    FSTOMPClient: IStompClient;
    FFormClosing: Boolean;

    // 인터페이스 구현 항목
    procedure OnMessage(StompFrame: IStompFrame; var TerminateListener: Boolean);
    procedure OnListenerStopped(StompClient: IStompClient);

  public
    constructor Create;
    destructor Destroy; override;

    procedure MQStart;
    procedure MQEnd;

    procedure OnStompStart;
  published
    // 이벤트 처리 하기 위한 코드
    property OnMQLogEvent: TMQLogEvent read FOnMQLogEvent write FOnMQLogEvent;
    property OnMQMsgEvent: TMQMessageEvent read FOnMQMsgEvent write FOnMQMsgEvent;

  end;

var
  MQClient: TMQClient;

implementation

{ TMQClient }

constructor TMQClient.Create;
begin
  OnStompStart;
end;


procedure TMQClient.OnStompStart;
var
  Subscribe : String;
begin
  FFormClosing := false;
  FSTOMPClient := StompUtils.StompClientAndConnect;

  if not FSTOMPClient.Connected  then
  begin
    if Assigned(FOnMQLogEvent) then
      FOnMQLogEvent('############ Connection failed..');
    Exit;
  end;

  Subscribe := ReadIniString( 'Subscribe' );
  if Assigned(FOnMQLogEvent) then
    FOnMQLogEvent('>> ' + Subscribe);

  FSTOMPClient.Subscribe(Subscribe,
    amAuto,
    StompUtils.Headers.Add('include-seq', 'seq'));

  // 리스터에서 Self를 전달해는게 안됨(C++)에서
  FSTOMPListener := StompUtils.CreateListener(FSTOMPClient, Self);

  if Assigned(FOnMQLogEvent) then
    FOnMQLogEvent('Listener Start.');
end;


destructor TMQClient.Destroy;
begin
  FFormClosing := True;
  FSTOMPListener := nil;
  inherited;
end;

procedure TMQClient.OnMessage(StompFrame: IStompFrame; var TerminateListener: Boolean);
begin
  if StompFrame.GetBody.Length<>0 then
  begin
    OutputDebugString( PWideChar(StompFrame.Body) );

    if Assigned(FOnMQMsgEvent) then
       FOnMQMsgEvent(Now,StompFrame.GetBody);
  end;

  TerminateListener := FFormClosing;
end;

procedure TMQClient.OnListenerStopped(StompClient: IStompClient);
begin
  FOnMQLogEvent( 'Listener OnListenerStopped' );

  if Assigned(FOnMQLogEvent) then
      FOnMQLogEvent('Listener Stopped');

  if not FSTOMPClient.Connected  then
  begin
    if Assigned(FOnMQLogEvent) then
      FOnMQLogEvent('Connection failed..');
   end;

end;

procedure TMQClient.MQStart;
begin

  if Assigned(FOnMQLogEvent) then
      FOnMQLogEvent('## Start ######## ..');

  FSTOMPListener.StopListening;
  OutputDebugString('Listener Started');

  FSTOMPListener.StartListening;

end;

procedure TMQClient.MQEnd;
begin

  if Assigned(FOnMQLogEvent) then
    FOnMQLogEvent('Listener Stopping.');

  FSTOMPListener.StopListening;

end;

end.
