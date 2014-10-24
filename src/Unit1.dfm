object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'ReleaseMaker'
  ClientHeight = 630
  ClientWidth = 577
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 351
    Width = 125
    Height = 13
    Caption = #1057#1082#1088#1080#1085#1096#1086#1090#1099' '#1080#1085#1089#1090#1083#1103#1090#1086#1088#1072':'
  end
  object Label2: TLabel
    Left = 306
    Top = 351
    Width = 91
    Height = 13
    Caption = #1057#1082#1088#1080#1085#1096#1086#1090#1099' '#1080#1075#1088#1099':'
  end
  object Description: TLabel
    Left = 8
    Top = 464
    Width = 53
    Height = 13
    Caption = #1054#1087#1080#1089#1072#1085#1080#1077':'
  end
  object Label3: TLabel
    Left = 306
    Top = 464
    Width = 113
    Height = 13
    Caption = #1054#1089#1086#1073#1077#1085#1085#1086#1089#1090#1080' Repacl'#39#1072':'
  end
  object Label4: TLabel
    Left = 304
    Top = 560
    Width = 52
    Height = 13
    Caption = #1064#1072#1073#1083#1086#1085#1099':'
  end
  object ValueListEditor: TValueListEditor
    Left = 0
    Top = 0
    Width = 571
    Height = 345
    Cursor = crHandPoint
    Strings.Strings = (
      #1051#1086#1075#1086':=%'#1051#1086#1075#1086'%'
      #1055#1086#1089#1090#1077#1088':=%'#1055#1086#1089#1090#1077#1088'%'
      #1044#1072#1090#1072' '#1074#1099#1093#1086#1076#1072':=%'#1044#1072#1090#1072'%'
      #1046#1072#1085#1088':=%'#1046#1072#1085#1088'%'
      #1056#1072#1079#1088#1072#1073#1086#1090#1095#1080#1082':=%'#1056#1072#1079#1088#1072#1073'%'
      #1048#1079#1076#1072#1090#1077#1083#1100':=%'#1048#1079#1076#1072#1090#1077#1083#1100'%'
      #1058#1080#1087' '#1080#1079#1076#1072#1085#1080#1103':=%'#1048#1079#1076#1072#1085#1080#1077'%'
      #1042#1077#1088#1089#1080#1103' '#1080#1075#1088#1099':=%'#1042#1077#1088#1089#1080#1103'%'
      #1071#1079#1099#1082' '#1080#1085#1090#1077#1088#1092#1077#1081#1089#1072':=%'#1048#1085#1090#1077#1088#1092#1077#1081#1089'%'
      #1071#1079#1099#1082' '#1086#1079#1074#1091#1095#1082#1080':=%'#1054#1079#1074#1091#1095#1082#1072'%'
      #1051#1077#1082#1072#1088#1089#1090#1074#1086':=%'#1051#1077#1082#1072#1088#1089#1090#1074#1086'%'
      #1054#1087#1077#1088#1072#1094#1080#1086#1085#1085#1072#1103' '#1089#1080#1089#1090#1077#1084#1072':=%'#1057#1080#1089#1090#1077#1084#1072'%'
      #1055#1088#1086#1094#1077#1089#1089#1086#1088':=%'#1055#1088#1086#1094#1077#1089#1089#1086#1088'%'
      #1054#1087#1077#1088#1072#1090#1080#1074#1085#1072#1103' '#1087#1072#1084#1103#1090#1100':=%'#1054#1087#1077#1088#1072#1090#1080#1074#1072'%'
      #1042#1080#1076#1077#1086#1082#1072#1088#1090#1072':=%'#1042#1080#1076#1077#1086'%'
      #1047#1074#1091#1082#1086#1074#1086#1077' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1086':=%'#1047#1074#1091#1082'%'
      #1057#1074#1086#1073#1086#1076#1085#1086#1077' '#1084#1077#1089#1090#1086' '#1085#1072' '#1076#1080#1089#1082#1077':=%'#1057#1074#1086#1073#1086#1076#1085#1086#1077' '#1084#1077#1089#1090#1086'%')
    TabOrder = 0
    TitleCaptions.Strings = (
      #1050#1083#1102#1095
      #1047#1085#1072#1095#1077#1085#1080#1077)
    ColWidths = (
      150
      415)
  end
  object ScreenInst: TMemo
    Left = 8
    Top = 370
    Width = 265
    Height = 79
    Lines.Strings = (
      '%'#1057#1082#1088#1080#1085#1099' '#1080#1085#1089#1090#1072#1083#1072'%')
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object GameSkrin: TMemo
    Left = 304
    Top = 370
    Width = 265
    Height = 79
    Lines.Strings = (
      '%'#1057#1082#1088#1080#1085#1099' '#1080#1075#1088#1099'%')
    ScrollBars = ssBoth
    TabOrder = 2
  end
  object DescriptionMemo: TMemo
    Left = 8
    Top = 483
    Width = 265
    Height = 70
    Lines.Strings = (
      '%'#1054#1087#1080#1089#1072#1085#1080#1077'%')
    ScrollBars = ssBoth
    TabOrder = 3
  end
  object DopContentMemo: TMemo
    Left = 8
    Top = 483
    Width = 265
    Height = 70
    Lines.Strings = (
      '%'#1044#1086#1087' '#1082#1086#1085#1090#1077#1085#1090'%')
    ScrollBars = ssBoth
    TabOrder = 4
    Visible = False
  end
  object OsobeGameMemo: TMemo
    Left = 8
    Top = 483
    Width = 265
    Height = 70
    Lines.Strings = (
      '%'#1054#1089#1086#1073#1077#1085#1085#1086#1089#1090#1080' '#1080#1075#1088#1099'%')
    ScrollBars = ssBoth
    TabOrder = 5
    Visible = False
  end
  object DopContent: TCheckBox
    Left = 8
    Top = 568
    Width = 153
    Height = 17
    Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1099#1081' '#1082#1086#1085#1090#1077#1085#1090
    TabOrder = 6
    OnClick = DopContentClick
  end
  object OsobeGame: TCheckBox
    Left = 167
    Top = 568
    Width = 113
    Height = 17
    Caption = #1054#1089#1086#1073#1077#1085#1085#1086#1089#1090#1080' '#1080#1075#1088#1099
    TabOrder = 7
    OnClick = OsobeGameClick
  end
  object OsobRepacka: TMemo
    Left = 304
    Top = 483
    Width = 265
    Height = 70
    Lines.Strings = (
      '%'#1054#1089#1086#1073#1077#1085#1085#1086#1089#1090#1080' '#1088#1077#1087#1072#1082#1072'%')
    ScrollBars = ssBoth
    TabOrder = 8
  end
  object ShabloniEdit: TEdit
    Left = 362
    Top = 559
    Width = 128
    Height = 21
    TabOrder = 9
  end
  object Button1: TButton
    Left = 496
    Top = 559
    Width = 75
    Height = 25
    Caption = #1054#1073#1079#1086#1088
    TabOrder = 10
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 591
    Width = 561
    Height = 33
    Caption = #1057#1086#1079#1076#1072#1090#1100
    TabOrder = 11
    OnClick = Button2Click
  end
  object MainMenu1: TMainMenu
    Left = 480
    Top = 368
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = N2Click
      end
    end
    object N4: TMenuItem
      Caption = '?'
      object N5: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
        OnClick = N5Click
      end
    end
  end
  object XPManifest1: TXPManifest
    Left = 448
    Top = 368
  end
  object OpenDialog1: TOpenDialog
    Filter = '(*.htm, *.html)|*.htm;*.html'
    InitialDir = 'GetCurrentDir()'
    Options = [ofReadOnly, ofHideReadOnly, ofEnableSizing]
    Left = 400
    Top = 368
  end
end
