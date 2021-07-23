#include <iostream>

using namespace std;

class lista {
           int *t;
           int rozmiar;
           int index;
      public: 
           //  konstruktor
           lista (int r) {
                rozmiar = r;    // ustawienie rozmiaru tablicy
                index = 0;
                t = new int[rozmiar];
                for (int i=0; i<rozmiar ; i++) {
                    t[i] = 0;
                    }
           }
                
           // dekonstruktor
           ~lista() {
                 delete t;
           }
           
           // wyswietlanie listy 
           void wypisz() {
                cout << "\n\nLista: \n";
                for (int i=0; i < rozmiar ; i++) {
                    cout << i+1 << ".   " << t[i] << endl;
                }
                cout << "==========";
           }
          
          // dopisywanie do listy 
          void dodaj(int wartosc) {
              t[index] = wartosc;
              index++;
              }
              
          // usowanie z listy
          void usun(int numer) {
              t[numer-1] = t[index-1];
              t[index-1] = 0;
              index--;
          }          
};

int main () { 
    
lista a(15);

a.wypisz();
a.dodaj(22);
a.wypisz();
a.dodaj(34);
a.wypisz();
a.dodaj(45);
a.wypisz();
a.dodaj(56);
a.wypisz();
a.dodaj(67);
a.wypisz();
a.dodaj(78);
a.wypisz();
a.usun(9);
a.wypisz();
a.dodaj(99);
a.wypisz();
cout << "\n\n\n";
system ("PAUSE");
return 0;
}
