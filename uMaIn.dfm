object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'Gemiso RabbitMQ Tester'
  ClientHeight = 298
  ClientWidth = 631
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 40
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 136
    Top = 26
    Width = 465
    Height = 233
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
end
