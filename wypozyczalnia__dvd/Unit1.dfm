object Form1: TForm1
  Left = 191
  Top = 102
  Width = 667
  Height = 629
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 657
    Height = 593
    Color = clSilver
    TabOrder = 0
    object GroupBox1: TGroupBox
      Left = 8
      Top = 8
      Width = 633
      Height = 417
      Caption = 'Wypo'#380'yczalnia DVD'
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clWindowText
      Font.Height = -48
      Font.Name = 'Palatino Linotype'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      object Panel2: TPanel
        Left = 16
        Top = 112
        Width = 609
        Height = 97
        Color = clSilver
        TabOrder = 0
        object Button2: TButton
          Left = 8
          Top = 8
          Width = 593
          Height = 81
          Caption = 'Baza Klientow'
          Font.Charset = EASTEUROPE_CHARSET
          Font.Color = clGreen
          Font.Height = -24
          Font.Name = 'Palatino Linotype'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = Button2Click
        end
      end
      object Panel3: TPanel
        Left = 16
        Top = 216
        Width = 609
        Height = 97
        Color = clSilver
        TabOrder = 1
        object Button1: TButton
          Left = 8
          Top = 8
          Width = 593
          Height = 81
          Caption = 'Baza Filmow'
          Font.Charset = EASTEUROPE_CHARSET
          Font.Color = clGreen
          Font.Height = -24
          Font.Name = 'Palatino Linotype'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = Button1Click
        end
      end
      object Button3: TButton
        Left = 320
        Top = 344
        Width = 305
        Height = 65
        Caption = 'Zamknij'
        Font.Charset = EASTEUROPE_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Palatino Linotype'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 8
        Top = 344
        Width = 305
        Height = 65
        Caption = 'O programie'
        Font.Charset = EASTEUROPE_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Palatino Linotype'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = Button4Click
      end
    end
    object GroupBox2: TGroupBox
      Left = 8
      Top = 424
      Width = 633
      Height = 161
      Caption = 'Aplety'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object Button5: TButton
        Left = 16
        Top = 32
        Width = 177
        Height = 49
        Caption = 'Data i czas'
        TabOrder = 0
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 16
        Top = 96
        Width = 177
        Height = 49
        Caption = 'Drukarki'
        TabOrder = 1
        OnClick = Button6Click
      end
      object Button8: TButton
        Left = 200
        Top = 32
        Width = 177
        Height = 49
        Caption = 'Fonty'
        TabOrder = 2
        OnClick = Button8Click
      end
      object Button10: TButton
        Left = 200
        Top = 96
        Width = 177
        Height = 49
        Caption = 'Myszka'
        TabOrder = 3
        OnClick = Button10Click
      end
      object GroupBox3: TGroupBox
        Left = 424
        Top = 16
        Width = 201
        Height = 137
        Caption = 'Pomoc'
        TabOrder = 4
        object Button7: TButton
          Left = 16
          Top = 40
          Width = 169
          Height = 65
          Caption = 'Pomoc'
          TabOrder = 0
          OnClick = Button7Click
        end
      end
    end
  end
end
