#include <iostream>
using namespace std;

class element
{friend class lista; 
int wartosc;
class element *next;
class element *prev;};
class lista
{element *first;
 element *last;
public:
lista()//---konstruktor---
{first=new element;
last=new element;
first->next=last;
last->prev=first;}
//---wstawienie---
void wstaw_end(int x)
{    element *nowy=new element;
     element *tmp=first->next;
     nowy->wartosc=x;
 if(first->next==last)
   {first->next=nowy;
    last->prev=nowy;
    nowy->prev=first;
    nowy->next=last;}
 else
   {while(tmp!=last)
     {if(tmp->wartosc>x) break;
      tmp=tmp->next;}     
    nowy->next=tmp;
    nowy->prev=tmp->prev;
    tmp->prev->next=nowy;
    tmp->prev=nowy;}}
void wstaw_top(int x)
{
     element *nowy=new element;
     element *tmp=last->prev;
     nowy->wartosc=x;
 if(last->prev==first)
   {last->prev=nowy;
    first->next=nowy;
    nowy->next=last;
    nowy->prev=first;}
 else
   {while(tmp!=first)
     {if(tmp->wartosc<x) break;
      tmp=tmp->prev;}     
    nowy->prev=tmp;
    nowy->next=tmp->next;
    tmp->next->prev=nowy;
    tmp->next=nowy;}}
//---wyjecie---
int wyjmij_end()
{ element *tmp=last->prev;
  if(first->next==last) return 0;
  last->prev=tmp->prev;
  tmp->prev->next=last;
  delete tmp;
  return 1;   
}
int wyjmij_top()
{ element *tmp=first->next;
  if(first->next==last) return 0;
  first->next=tmp->next;
  tmp->next->prev=first;
  delete tmp;
  return 1;   
}
//---wypisanie---
void wypisz()
{  element *tmp=first->next;
   if(first->next==last)
      cout<<"---Lista jest pusta---\n";
   while(tmp!=last)
   {cout <<tmp->wartosc<<" ";
    tmp=tmp->next;}
   cout<<"\n";}
};
//---main---
int main()
{char wybor;int x;lista l;
do
{cout<<"\n\n[1] Wstaw na koniec" <<endl;
cout<<"[2] Wstaw na poczatek" <<endl;
cout<<"[3] Wyjmij z konca"<<endl;
cout<<"[4] Wyjmij z poczatku"<<endl;
cout<<"[5] Wypisz"<<endl;
cout<<"[6] Wyjdz"<<endl;
cout<<"\n---Wybor: ";
cin>>wybor;
switch(wybor){
case '1': 
   cout<<"\n---Podaj wartosc: ";
   cin>>x; l.wstaw_end(x); break;
case '2': 
   cout<<"\n---Podaj wartosc: ";
   cin>>x; l.wstaw_top(x); break;
case '3': 
   if(!l.wyjmij_end()) cout<<"\n---Brak elementow do usuniecia---";
   else cout<<"\n---Usunieto ostatni element---";break;
case '4': 
   if(!l.wyjmij_top()) cout<<"\n---Brak elementow do usuniecia---";
   else cout<<"\n---Usunieto pierwszy element---";break;
case '5': 
   l.wypisz();break;
case '6': 
   cout<<"\n---KONIEC---"<<endl<<endl;break;
default: cout<<"\n---!!!Nieprawidlowa wartosc!!!---"<<endl;break;
}
}while(wybor!='6');
return 0;}
