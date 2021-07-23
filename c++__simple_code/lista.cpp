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
              
          // usuwanie z listy
          void usun(int numer) {
              t[numer-1] = t[index-1];
              t[index-1] = 0;
              index--;
          }          
};

int main () { 
    
lista a(10);

a.wypisz();
a.dodaj(34);
a.wypisz();
a.dodaj(55);
a.wypisz();
a.dodaj(66);
a.wypisz();
a.dodaj(77);
a.wypisz();
a.dodaj(88);
a.wypisz();
a.dodaj(99);
a.wypisz();
a.usun(3);
a.wypisz();
a.dodaj(100);
a.wypisz();
cout << "\n\n\n";
system ("PAUSE");
return 0;
}
