object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'Gemiso RabbitMQ Tester'
  ClientHeight = 445
  ClientWidth = 755
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OnClose = FormClose
  DesignSize = (
    755
    445)
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 96
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Button1: TButton
    Left = 8
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Start'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 89
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Stop'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 270
    Top = 8
    Width = 484
    Height = 429
    Anchors = [akLeft, akTop, akRight, akBottom]
    ScrollBars = ssVertical
    TabOrder = 2
    ExplicitWidth = 480
    ExplicitHeight = 428
  end
  object Memo2: TMemo
    Left = 1
    Top = 115
    Width = 263
    Height = 322
    Anchors = [akLeft, akTop, akBottom]
    ScrollBars = ssVertical
    TabOrder = 3
    ExplicitHeight = 321
  end
  object Button3: TButton
    Left = 89
    Top = 84
    Width = 75
    Height = 25
    Caption = 'Stop'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 232
    Top = 8
  end
end
