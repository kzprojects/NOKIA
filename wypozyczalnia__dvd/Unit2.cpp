//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "IniFiles.hpp" //Deklarujemy obs³ugê INI
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::wpiszClick(TObject *Sender)
{
//Spawdzamy czy któreœ pole jest puste.
if(Edit1->Text=="" || Edit2->Text=="" || Edit3->Text==""|| Edit4->Text==""|| Edit5->Text==""|| Edit6->Text=="")
{
ShowMessage("Uzupe³nij wszystkie pola!");
}

else
{
//Deklarujemy stringi
AnsiString imie;
AnsiString nazwisko;
AnsiString adres;
AnsiString telefon;
AnsiString data_ur;
AnsiString pesel;


//Pobieramy dane z pól tekstowych
imie= Edit1->Text;
nazwisko= Edit2->Text;
adres = Edit3->Text;
telefon= Edit4->Text;
data_ur= Edit5->Text;
pesel= Edit6->Text;

//Inicjujemy komponent TIniFile
TIniFile * Ini = new TIniFile(ExtractFileDir(Application->ExeName) + "\\baza.dtb");

//Deklarujemy int 'numer'
int numer;

//Odczytujemy INI do zmiennej 'numer'
numer = Ini->ReadInteger("main", "numer", 0);

//Powiêkszamy zmienn¹ 'numer' o jeden
numer++;

//Zapisujemy spowrotem powiêkszon¹ wartoœæ
Ini->WriteInteger("main", "numer", numer);

//Zapisujemy stringi do INI ;)
Ini->WriteString(numer, "imie", imie);
Ini->WriteString(numer, "nazwisko", nazwisko);
Ini->WriteString(numer, "adres", adres);
Ini->WriteString(numer, "telefon", telefon);
Ini->WriteString(numer, "data_ur", data_ur);
Ini->WriteString(numer, "pesel", pesel);

//Wywo³ujemy kod z przycisku "Odœwiez"
odswiez->Click();

//Czyœcimy pola tekstowe
Edit1->Text="";
Edit2->Text="";
Edit3->Text="";
Edit4->Text="";
Edit5->Text="";
Edit6->Text="";
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::odswiezClick(TObject *Sender)
{
//inicjujemy INI
TIniFile * Ini = new TIniFile(ExtractFileDir(Application->ExeName) + "\\baza.dtb");

//deklarujemy zmienn¹ int "num" i przypisujemy jej wartosc z INI
int num = Ini->ReadInteger("main", "numer", 0);

//deklarujemy zmienne
AnsiString imie1;
AnsiString nazwisko1;
AnsiString adres1;
AnsiString telefon1;
AnsiString data_ur1;
AnsiString pesel1;

//usuwamy zawartoœæ listboxa
ListBox1->Clear();

//podczas kazdego przebiegu pêtli FOR odejmujemy 1 dopoki 'num' jest wieksze od 1
//ka¿dy przebieg wywo³uje inne dane.
for(num; num>=1; num--)
{
//odczytujemy nasze zmienne z pliku INI
imie1 = Ini->ReadString(num, "imie", "error");
nazwisko1 = Ini->ReadString(num, "nazwisko", "error");
adres1 = Ini->ReadString(num, "adres", "error");
telefon1 = Ini->ReadString(num, "telefon", "error");
data_ur1 = Ini->ReadString(num, "data_ur", "error");
pesel1 = Ini->ReadString(num, "pesel", "error");

//dodajemy do listboxa pozycjê z danymi
ListBox1->Items->Add(imie1+" Nazwisko:"+nazwisko1+" ul."+adres1+" tel:"+telefon1+" Data ur.:"+data_ur1+" Pesel:"+pesel1);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
//deklarujemy zmienn¹ int na odpowiedŸ
int odp;

//zadajemy pytanie i zmiennej 'odp' przypisujemy odpowiedz
odp = Application->MessageBox("Czy na pewno chcesz skasowaæ listê?", "Pytanie", MB_YESNO);

//liczba 6 oznacza "TAK" - czyli je¿eli na komunikat odpowiedzono "TAK" zostan¹ wykonane instrukcje z IF
if(odp==6)
{

//inicjujemy INI
TIniFile * Ini = new TIniFile(ExtractFileDir(Application->ExeName) + "\\baza.dtb");

//deklarujemy zmienn¹ int przypisujuj¹c jej wartoœæ pobrana z pliku INI
int num = Ini->ReadInteger("main", "numer", 0);

//podczas kazdego przebiegu pêtli FOR odejmujemy 1  dopoki 'num' jest wiesze od 1
for(num; num>=1; num--)
{
//kasujemy z INI sekcjê o 'nazwie-liczbie' równej wartosi zmiennej 'num'
//!! KA¯DY PRZEBIEG KASUJE INN¥ SEKCJÊ, od koñca
Ini->EraseSection(num);
}

//kasujemy sekcjê "main"
Ini->EraseSection("main");
//odœwiezamy symuluj¹c klikniêcie.
odswiez->Click();

}        
}
//---------------------------------------------------------------------------







