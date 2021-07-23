#include <iostream>
using namespace std;


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
first=new element;
last=new element;
first->next=last;
last->prev=first;
}

void pokaz()
{
   element *tmp=first->next;
   if(first->next==last)
      cout<<"--> brak elementow na liscie\n";
   while(tmp!=last)
   {
      cout <<tmp->value<<" ";
      tmp=tmp->next;   
   }
   cout<<"\n";
}

void pokaz_wspak()
{
   element *tmp=last->prev;
   if(first->next==last)
      cout<<"--> brak elementow na liscie\n";
   while(tmp!=first)
   {
      cout <<tmp->value<<" ";
      tmp=tmp->prev;   
   }
   cout<<"\n";
}

int usun()
{
    element *tmp=last->prev;
    if(first->next==last)
       return 0;
    last->prev=tmp->prev;
    tmp->prev->next=last;
    delete tmp;
    return 1;   
}

int usun_wybrany(int x)
{
    element *tmp=first->next;
    if(first->next==last)
       return 0;
    while(tmp!=last)
    {
       x--;
       if(x==0)
       {
          tmp->prev->next=tmp->next;
          tmp->next->prev=tmp->prev;
          delete tmp;     
          return 1;
       }             
       tmp=tmp->next;
    }
    return 0;
    
}

void dodaj(int x)
{
   element *nowy=new element;
   element *tmp=first->next;
   nowy->value=x;
   if(first->next==last)
   {
      first->next=nowy;
      last->prev=nowy;
      nowy->prev=first;
      nowy->next=last;
   }
   else
   {
      while(tmp!=last)
      {
         if(tmp->value>x)
            break;
         tmp=tmp->next;
      }
      nowy->next=tmp;
      nowy->prev=tmp->prev;
      tmp->prev->next=nowy;
      tmp->prev=nowy;
   }
}

};


int main()
{
char z;
int x;
lista a;
do
{

cout<<"\nDodaj: 1" <<endl;
cout<<"Usun ostatni: 2"<<endl;
cout<<"Usun wybrany: 3"<<endl;
cout<<"Pokaz: 4"<<endl;
cout<<"Pokaz wspak: 5"<<endl;
cout<<"KONIEC: 6"<<endl;

cout<<"\n Twoj wybor to: ";
cin>>z;
switch(z){
case '1': cout<<"\n Podaj wartosc: ";
cin>>x;
a.dodaj(x);
break;
case '2': if(!a.usun())
cout<<"\n --> Brak elementow do usuniecia";
else
cout<<"\n --> Usunieto ostatni element";
break;
case '3': cout<<"\n Podaj wartosc: ";
cin>>x;
if(!a.usun_wybrany(x))
cout<<"\n --> Brak elementow do usuniecia";
else
cout<<"\n --> Usunieto ostatni element";
break;
case '4': a.pokaz();
break;
case '5': a.pokaz_wspak();
break;
case '6': cout<<"\n --> KONIEC! <--"<<endl<<endl;
break;
default: cout<<"\n --> ERROR,powtorz wybor"<<endl;
break;
}
}while(z!='6');
return 0;
}
