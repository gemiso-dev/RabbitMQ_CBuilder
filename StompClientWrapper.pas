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
    FOnMQMsgEvent: TMQMessageEvent;    FSTOMPListener: IStompListener;
    FSTOMPClient: IStompClient;
    FFormClosing: Boolean;

    // �������̽� ���� �׸�
    procedure OnMessage(StompFrame: IStompFrame; var TerminateListener: Boolean);
    procedure OnListenerStopped(StompClient: IStompClient);

  public
    constructor Create;
    destructor Destroy; override;

    procedure MQStart;
    procedure MQEnd;

  published
    // �̺�Ʈ ó�� �ϱ� ���� �ڵ�
    property OnMQLogEvent: TMQLogEvent read FOnMQLogEvent write FOnMQLogEvent;
    property OnMQMsgEvent: TMQMessageEvent read FOnMQMsgEvent write FOnMQMsgEvent;

  end;

var
  MQClient: TMQClient;

implementation

{ TMQClient }

constructor TMQClient.Create;
begin
  FFormClosing := false;

  // �����ϱ�
  // ���� ������ �ܺη� ����
  FSTOMPClient := StompUtils.StompClientAndConnect;

  // topic , Route dummy
  FSTOMPClient.Subscribe('/topic/dummy',
    amAuto,
    StompUtils.Headers.Add('include-seq', 'seq'));

  // �����Ϳ��� Self�� �����ش°� �ȵ�(C++)����
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
  OutputDebugString( 'Listener Stopped' );

  if Assigned(FOnMQLogEvent) then
      FOnMQLogEvent('Listener Stopped');end;

procedure TMQClient.MQStart;
begin

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
