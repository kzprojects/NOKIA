//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "IniFiles.hpp" //Deklarujemy obs?ug? INI
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button5Click(TObject *Sender)
{
//deklarujemy zmienn? int na odpowied?
int odp;

//zadajemy pytanie i zmiennej 'odp' przypisujemy odpowiedz

odp = Application->MessageBox("Czy na pewno chcesz skasowa? list??", "Pytanie", MB_YESNO);

//liczba 6 oznacza "TAK" - czyli je?eli na komunikat odpowiedzono "TAK" zostan? wykonane instrukcje z IF
if(odp==6)
{

//inicjujemy INI
TIniFile * Ini = new TIniFile(ExtractFileDir(Application->ExeName) + "\\baza.dtb");

//deklarujemy zmienn? int przypisujuj?c jej warto?? pobranaz pliku INI
int num = Ini->ReadInteger("main", "numer", 0);

//podczas kazdego przebiegu p?tli FOR odejmujemy 1 dopkki'num' jest wieksze od 1
for(num; num>=1; num--)
{
//kasujemy z INI sekcj? o 'nazwie-liczbie' r?wnej  wartosci zmiennej 'num'
//!! KA?DY PRZEBIEG KASUJE INN? SEKCJ?, od ko?ca
Ini->EraseSection(num);
}

//kasujemy sekcj? "main"
Ini->EraseSection("main");
//od?wiezamy symuluj?c klikni?cie.
odswiez->Click();

}        
}
//---------------------------------------------------------------------------
void __fastcall TForm3::wpiszClick(TObject *Sender)
{
//Spawdzamy czy kt?re? pole jest puste.
if(Edit1->Text=="" || Edit2->Text=="" || Edit3->Text==""|| Edit4->Text==""|| Edit5->Text==""|| Edit6->Text=="")
{
ShowMessage("Uzupe?nij wszystkie pola!");
}

else
{
//Deklarujemy stringi
AnsiString tytul;
AnsiString rodzaj;
AnsiString cena_wypozyczenia;
AnsiString cena;
AnsiString wersja_jezykowa;
AnsiString rok_produkcji;

//Pobieramy dane z p?l tekstowych
tytul= Edit1->Text;
rodzaj= Edit2->Text;
cena_wypozyczenia = Edit3->Text;
cena= Edit4->Text;
wersja_jezykowa= Edit5->Text;
rok_produkcji= Edit6->Text;

//Inicjujemy komponent TIniFile
TIniFile * Ini = new TIniFile(ExtractFileDir(Application->ExeName) + "\\baza.dtb");

//Deklarujemy int 'numer'
int numer;

//Odczytujemy INI do zmiennej 'numer'
numer = Ini->ReadInteger("main", "numer", 0);

//Powi?kszamy zmienn? 'numer' o jeden
numer++;

//Zapisujemy spowrotem powi?kszon? warto??
Ini->WriteInteger("main", "numer", numer);

//Zapisujemy stringi do INI ;)
Ini->WriteString(numer, "tytul", tytul);
Ini->WriteString(numer, "rodzaj", rodzaj);
Ini->WriteString(numer, "cena_wypozyczenia", cena_wypozyczenia);
Ini->WriteString(numer, "cena", cena);
Ini->WriteString(numer, "wersja_jezykowa", wersja_jezykowa);
Ini->WriteString(numer, "rok_produkcji", rok_produkcji);

//Wywo?ujemy kod z przycisku "Od?wiez"
odswiez->Click();

//Czy?cimy pola tekstowe
Edit1->Text="";
Edit2->Text="";
Edit3->Text="";
Edit4->Text="";
Edit5->Text="";
Edit6->Text="";
}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::odswiezClick(TObject *Sender)
{
//inicjujemy INI
TIniFile * Ini = new TIniFile(ExtractFileDir(Application->ExeName) + "\\baza.dtb");

//deklarujemy zmienn? int "num" i przypisujemy jej wartosc z INI
int num = Ini->ReadInteger("main", "numer", 0);

//deklarujemy zmienne
AnsiString tytul1;
AnsiString rodzaj1;
AnsiString cena_wypozyczenia1;
AnsiString cena1;
AnsiString wersja_jezykowa1;
AnsiString rok_produkcji1;

//usuwamy zawarto?? listboxa
ListBox1->Clear();

//podczas kazdego przebiegu p?tli FOR odejmujemy 1 dopoki 'num' jest wieksze od 1
//ka?dy przebieg wywo?uje inne dane.
for(num; num>=1; num--)
{
//odczytujemy nasze zmienne z pliku INI
tytul1 = Ini->ReadString(num, "tytul", "error");
rodzaj1 = Ini->ReadString(num, "rodzaj", "error");
cena_wypozyczenia1 = Ini->ReadString(num, "cena_wypozyczenia", "error");
cena1 = Ini->ReadString(num, "cena", "error");
wersja_jezykowa1 = Ini->ReadString(num, "wersja_jezykowa", "error");
rok_produkcji1 = Ini->ReadString(num, "rok_produkcji", "error");

//dodajemy do listboxa pozycj? z danymi
ListBox1->Items->Add(tytul1+" Rodzaj:"+rodzaj1+" Cena wyp.:"+cena_wypozyczenia1+" Cena:"+cena1+" Ver.:"+wersja_jezykowa1+" Rok pro.:"+rok_produkcji1);
}        
}
//---------------------------------------------------------------------------




