//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <iostream>
using namespace std;

class woz_mechaniczny{
  public:
    virtual void ruch() = 0;
    virtual void tankuj() = 0;
    int zawartoscbenzyny, zuzyciebenzyny;
};

class samochod : public woz_mechaniczny
{
  public:
    samochod(){zawartoscbenzyny = 65;zuzyciebenzyny = 8;}
    void ruch()
    {
      kilometry=0;
      minpoziom=5;
      zuzyto=5;
      cout << "Poczatkowy stan paliwa w samochodzie = "<<zawartoscbenzyny<<" \n\n ";
      for(;;)
      {
        if((zawartoscbenzyny-zuzyciebenzyny)>=minpoziom)
        {
          zawartoscbenzyny-=zuzyciebenzyny;
          kilometry+=100;
          zuzyto+=5;
        }
        else
        {
          cout << " >>> Zuzyto "<<zuzyto-zawartoscbenzyny<< " Litrow paliwa na "<<kilometry<<" Kilometrow \n";
          cout << "  >>> Stan paliwa min. "<<zawartoscbenzyny<< "!!!  -  FULL Tankuje\n";
          void tankuj();
          break;
        }
      }
    }
    void tankuj()
    {
       zawartoscbenzyny +=195;
       cout << "  >>> Stan po zalaniu: "<<zawartoscbenzyny<< "!!!\n\n\n";
    }
  private:
    int kilometry;
    int minpoziom;
    int zuzyto;
};

class motorowka : woz_mechaniczny
{
  public:
    motorowka(){zawartoscbenzyny = 180;zuzyciebenzyny = 15;}
    void ruch()
    {
      kilometry=0;
      minpoziom=20;
      zuzyto=50;
      cout << "Poczatkowy stan paliwa w motorowce = "<<zawartoscbenzyny<<" \n\n ";
      for(;;)
      {
        if((zawartoscbenzyny-zuzyciebenzyny)>=minpoziom)
        {
          zawartoscbenzyny-=zuzyciebenzyny;
          kilometry+=100;
          zuzyto+=50;
        }
        else
        {
          cout << " >>> Zuzyto "<<zuzyto-zawartoscbenzyny<< " Litrow paliwa na "<<kilometry<<" Kilometrow \n";
          cout << "  >>> Stan paliwa w motorowce jest min. "<<zawartoscbenzyny< "!!!  -  ZATANKUJ!!!\n";
          void tankuj();
          break;
        }
      }
    }
    void tankuj()
    {
      zawartoscbenzyny +=350;
      cout << " >>> Stan po zalaniu: "<<zawartoscbenzyny<< "!!!\n\";
    }
  private:
    int kilometry;
    int minpoziom;
    int zuzyto;
};

class amfibia : public samochod, public motorowka
{
  public:
    int kilometry;
    int minpoziom;
    void ruch(int parametr)
    {
      if(parametr)
      {
        samochod::ruch();
      }
      else motorowka::ruch();
    }
    void tankuj(int parametr1)
    {
      if(parametr1)
      {
        samochod::tankuj();
      }
      else motorowka::tankuj();
    }
};

main()
{
  amfibia sm;
  sm.ruch(1);
  sm.tankuj(1);
  sm.ruch(0);
  sm.tankuj(0);
  system("PAUSE");
}
