#include <iostream>

using namespace std;

class stos {
           int *t;
           int rozmiar;
           int index;
      public: 
           //  konstruktor
           stos (int r) {
                rozmiar = r;    // ustawienie rozmiaru tablicy
                index = 0;       // index na pierwsza komorke tablicy 
                t = new int[rozmiar];
                for (int i=0; i<rozmiar ; i++) {
                    t[i] = 0;
                    }
           }
                
           // dekonstruktor
           ~stos() {
                 delete t;
           }
           
           // wyswietlanie stosu  
           void wypisz() {
                cout << "\n\nSTOS = [ ";
                for (int i=0; i < rozmiar ; i++) {
                    cout << t[i] << " ";
                }
                cout << " ] \n\n";
           }
          
          // dok³adanie do stosu 
          void push(int wartosc) {
              t[index] = wartosc;
              index++;
              }
              
          // zdejmowanie ze stosu
          int pop() {
              int temp = t[index-1];
              t[index-1] = 0;
              if (index > 0) index--;
              return temp;
          }          
};

int main () { 
    
int dzialanie;
stos a(10);

do {
cout << "Jakie operacje sa wykonnywane na stosie: " << endl;
cout << "---------------------------------------- " << endl;
cout << "1. Dodawanie na stos. \n2. Pobieranie ze stosu. \n3. Wypisywanie. \n4. Konczy dzialanie programu." << endl;
cin >> dzialanie;
switch (dzialanie) {
       case 1 : 
               cout << "Wartosc do dodania: \n";
               int wartosc;
               cin >> wartosc;
               a.push(wartosc);
               cout << "\n\n";
               break;
       case 2 :
               cout << "Pobrano: " << a.pop() << "\n\n";
               break;
       case 3 :
               a.wypisz();
               break;
       case 4 : return 0;
}
}
while(0==0);
cout << "\n\n\n";
system ("PAUSE");
return 0;
}
