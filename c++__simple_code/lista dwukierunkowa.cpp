#include <iostream>
using namespace std;

//---------------------------------------------------------------------------

class element
{
 int value;
 class element *next;
 class element *prev;
 friend class lista;
 };

class lista
{
 element *first;
 element *last;
 public:

 lista()
 {
  first=last=NULL;
 }
//dodawanie na koniec
 void dodaj(int x)
 {
  element *nowy=new element;
  nowy->next=last;
  nowy->prev=last;
  nowy->value=x;
  if(first==last&&first==NULL)
  {
   first=last=nowy;
   first->next=last;
   }
  else
  {
   nowy->next=first;
   first=nowy;
   first->next->prev=first;
   last->next=first;
   first->prev=last;
   }
  }
//dodawanie na poczatek
void dodajp(int x)
 {element *nowy=new element;
nowy->value = x;
if (first==NULL && last==NULL)
  {
  first=nowy;
  last=nowy;
  nowy->next=NULL;
  nowy->prev=NULL;
  }
else
  {
  nowy->next=first;
  nowy->prev=NULL;
  first->prev=nowy;
  first=nowy;
  }
} 
//usuwanie z konca
 int usun()
 {if(last==first&&first==NULL)
   return 0;
   else
   {
  if(first==last&&first!=NULL)
  {
   last=first=NULL;
   }
  else
  {
    last=last->prev;
    delete last->next;
    last->next=first;
    first->prev=last;
    }
   return 1;
   }
  }
//usuwanie z poczatku
int usunp()
 {if (first!=NULL)
  {
  if (last==first)
      {
      last=NULL;
      free(*head);
      first=NULL;
      }
  else
      {
      nowy=first->next;
      (*head)->next->prev=NULL;
      free(*head);
      *head=a;
      }
  } }
 ~lista()
 {
usun();
  }
/*
 void usun_wybrany(int x)
 {
    element *pomoc;
   pomoc=first;
   if(pomoc!=NULL)
   {
   do
   {
   if(pomoc->value==x)
   {
    if(first==last&&last!=NULL)
     usun();
    else
    {
    pomoc->prev->next=pomoc->next;
    pomoc->next->prev=pomoc->prev;
    if(pomoc==first)
     first=pomoc->next;
    if(pomoc==last)
     last=pomoc->prev;
    delete pomoc;
    }
    cout<<"\n --> Element wykryto i usuniêto :)";
    break;
    }
    else
     pomoc=pomoc->next;
     if(pomoc==first)
     {
      cout<<"\n --> Brak takiego elementu na liscie!";
      break;
      }
    }while(pomoc!=first);
   }
  else
   cout<<"\n --> Lisat jest pusta";
  }*/

 void pokaz()
 {
 element *temp;
 temp=first;
 cout<<endl;
 if(temp==NULL)
  cout<<"\n --> Nie ma nic na liscie"<<endl;
 else
 {
  cout<<"\n --> LISTA: ";
 do
 {
  cout<<temp->value<<" ";
  if(temp==last)
   break;
  temp=temp->next;
  }
  while(temp!=first);
 }
 }
/*
  void pokaz_wspak()
  {
 element *temp;
 temp=last;
 if(temp==NULL)
  cout<<"\n --> Nie ma nic na liscie"<<endl;
 else
 {
 cout<<endl<<" --> LISTA WSPAK: ";
 do
 {
  cout<<temp->value<<" ";
  if(temp==first)
   break;
  temp=temp->prev;
  }
  while(temp!=last);
 }

 }*/
};

//---------------------------------------------------------------------------

int main(){
 char z;
 int x;
 lista a;
 do
 {
 cout<<"\n\n ------------------------------------------------------";
 cout<<"\n |  Dodaj na koniec: d  |  Usun ostatni: o  |  Usun wybrany: u  |";
 cout<<"\n ----------------------------------------------------";
 cout<<"\n |  Pokaz: p  |  Dodaj na poczatek: w   |  KONIEC: q        |";
 cout<<"\n ------------------------------------------------------"<<endl;
 cout<<"\n Twoj wybor to: ";
 cin>>z;
  switch(z)
  {
  case 'd': cout<<"\n Podaj wartosc: ";
            cin>>x;
            a.dodaj(x);
            break;
  case 'o': if(!a.usun())
             cout<<"\n --> Brak elementow do usuniecia";
	    else
             cout<<"\n --> Usunieto ostatni element";
            break;
  case 'u': cout<<"\n Podaj wartosc: ";
            cin>>x;
            a.usun_wybrany(x);
            break;
  case 'p': a.pokaz();
            break;
  case 'w': cout<<"\n Podaj wartosc: ";
            cin>>x;
            a.dodajp(x);
            break;
  case 'q': cout<<"\n --> KONIEC!!! <--"<<endl<<endl;
            break;
   default:  cout<<"\n --> ERROR,powtorz wybor"<<endl;
            break;
  }
 }while(z!='q');

 return 0;
}
//---------------------------------------------------------------------------
