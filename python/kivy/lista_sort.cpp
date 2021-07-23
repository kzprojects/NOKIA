#include <iostream>

using namespace std;

class element{
      int wartosc;
      class element *next;
      class element *prev;
      friend class lista;
};

class lista {
      element *first;
      element *last;
      public:
      lista() {
              first = new element;
              last = new element;
              first->next = last;
              last->prev = first;
      }

      void pokaz() {
           element *tmp = first->next;
           if (first->next == last) cout<<"Lista pusta"<< endl;
           while(tmp != last) {
                     cout <<tmp->wartosc<<" ";
                     tmp=tmp->next;   
           }
           cout << endl;
      }
      
      int usun() {
           element *tmp = last->prev;
           if(first->next == last) return 0;
           last->prev = tmp->prev;
           tmp->prev->next = last;
           delete tmp;
           return 1;   
       }


       void dodaj(int x) {
           element *nowy = new element;
           element *tmp = first->next;
           nowy->wartosc = x;
           if(first->next == last) {
               first->next = nowy;
               last->prev = nowy;
               nowy->prev = first;
               nowy->next = last;
           } else {
               while(tmp != last) {
               if(tmp->wartosc > x) break;
               tmp = tmp->next;
               }
           nowy->next = tmp;
           nowy->prev = tmp->prev;
           tmp->prev->next = nowy;
           tmp->prev = nowy;
           }
       }
};

// PROGRAM

int main(){
char z;
int x;
lista a;



do{

cout<<"\nDodaj: 1" <<"\n";
cout<<"Usun ostatni: 2"<<"\n";
cout<<"Usun wybrany: 3"<<"\n";
cout<<"Pokaz: 4"<<"\n";
cout<<"Pokaz wspak: 5"<<"\n";
cout<<"KONIEC: 6"<<"\n";

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
case '4': a.pokaz();
break;
case '6': cout<<"\n --> KONIEC! <--"<<endl<<endl;
break;
default: cout<<"\n --> ERROR,powtorz wybor"<<endl;
break;
}
}while(z!='6');
return 0;
}
