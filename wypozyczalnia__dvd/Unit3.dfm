object Form3: TForm3
  Left = 265
  Top = 217
  Width = 780
  Height = 470
  Caption = 'BAZA DANYCH FILM'#211'W'
  Color = clBtnShadow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 208
    Top = 0
    Width = 561
    Height = 273
    Caption = 'Baza Filmow'
    Color = clBtnShadow
    ParentColor = False
    TabOrder = 0
    object ListBox1: TListBox
      Left = 8
      Top = 16
      Width = 545
      Height = 249
      ItemHeight = 13
      TabOrder = 0
    end
  end
  object TGroupBox
    Left = 0
    Top = 0
    Width = 201
    Height = 433
    Caption = 'Dane Filmu'
    Color = clBtnShadow
    ParentColor = False
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 32
      Width = 26
      Height = 13
      Caption = 'Tytul:'
    end
    object Label2: TLabel
      Left = 8
      Top = 72
      Width = 36
      Height = 13
      Caption = 'Rodzaj:'
    end
    object Label3: TLabel
      Left = 8
      Top = 112
      Width = 100
      Height = 13
      Caption = 'Cena Wypozyczenia:'
    end
    object Label4: TLabel
      Left = 8
      Top = 152
      Width = 28
      Height = 13
      Caption = 'Cena:'
    end
    object Label5: TLabel
      Left = 8
      Top = 192
      Width = 86
      Height = 13
      Caption = 'Wersja Jezykowa:'
    end
    object Label6: TLabel
      Left = 8
      Top = 232
      Width = 70
      Height = 13
      Caption = 'Rok Produkcji:'
    end
    object Edit1: TEdit
      Left = 8
      Top = 48
      Width = 177
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 8
      Top = 88
      Width = 177
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 8
      Top = 128
      Width = 177
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 8
      Top = 168
      Width = 177
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
    end
    object wpisz: TButton
      Left = 8
      Top = 328
      Width = 185
      Height = 97
      Caption = 'Wpisz'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = wpiszClick
    end
    object Edit5: TEdit
      Left = 8
      Top = 208
      Width = 177
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
    end
    object Edit6: TEdit
      Left = 8
      Top = 248
      Width = 177
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
    end
  end
  object GroupBox3: TGroupBox
    Left = 208
    Top = 280
    Width = 561
    Height = 153
    Caption = 'Przyciski Pomocnicze'
    Color = clBtnShadow
    ParentColor = False
    TabOrder = 2
    object odswiez: TButton
      Left = 288
      Top = 56
      Width = 249
      Height = 65
      Caption = 'Odswiez liste'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = odswiezClick
    end
    object Button5: TButton
      Left = 16
      Top = 56
      Width = 249
      Height = 65
      Caption = 'Kasuj Liste'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = Button5Click
    end
  end
end
