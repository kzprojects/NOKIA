#include <iostream>
using namespace std;

class element
{friend class lista; 
int wartosc;
class element *next;
class element *prev;
};

class lista
{element *first;
element *last;
public:
//---konstruktor---
lista()
{
first=new element;
last=new element;
first->next=last;
last->prev=first;
}
//---wstawienie na koniec---
void wstaw(int x)
{element *nowy=new element;
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
//---wyjecie z konca---
int wyjmij()
{ element *tmp=last->prev;
  if(first->next==last) return 0;
  last->prev=tmp->prev;
  tmp->prev->next=last;
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
{cout<<"\n---Wstaw:  1---" <<endl;
cout<<"---Wyjmij: 2---"<<endl;
cout<<"---Wypisz: 3---"<<endl;
cout<<"---Wyjdz:  4---"<<endl;
cout<<"\n---Wybor: ";
cin>>wybor;
switch(wybor){
case '1': 
   cout<<"\n---Podaj wartosc: ";
   cin>>x; l.wstaw(x); break;
case '2': 
   if(!l.wyjmij()) cout<<"\n---Brak elementow do usuniecia---";
   else cout<<"\n---Usunieto ostatni element---";break;
case '3': 
   l.wypisz();break;
case '4': 
   cout<<"\n---KONIEC---"<<endl<<endl;break;
default: cout<<"\n---!!!Nieprawidlowa wartosc!!!---"<<endl;break;
}
}while(wybor!='4');
return 0;}
