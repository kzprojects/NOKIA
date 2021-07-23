#include <iostream.h>
using namespace std;

int zamien_na_dziesietna (int tab[], int cyfry)
{
int i,j,k;
int liczba_dziesietna =0;
for (j=0; j<cyfry; j++)
{
i=1;
for	(k=j+1; k<cyfry; k++) i=i*2;
  liczba_dziesietna=liczba_dziesietna+tab[j]*i;
  }
  return liczba_dziesietna;
  }
  
int main()
{
int binarna[20];
int i,ilosc_cyfr;
int comabyc;
cout<<"wcisnij 1 jesli chcesz zamienic binarne na dziesietne"<<endl;
cout<<"wcisnij 2 jesli chcesz zmienic dziesietne na binarne" << endl;
cin>>comabyc;

switch (comabyc)
{
case 1: {
    
  cout<< "ilu cyfr bedzie sie skladac liczba?:"<<endl ;
  cin>>ilosc_cyfr;
  cout<<"odaj liczbe w postaci binarnej; po kazdej cyfrze nacisnij Enter" <<endl;
  for (i=0;i<ilosc_cyfr;i++)
  cin>>binarna[i];
  cout<< "systemie dziesietnym to:" <<zamien_na_dziesietna(binarna, ilosc_cyfr);
  } break;
 case 2: {
 cout << "podaj liczbe diesietna" <<endl;
 int liczba,b;
 int licznik=0;
 int bintab[30];
 float test;
 cin >> liczba;
     while (b!=1)
    {
    licznik+=1;
    //test
    b=liczba/2;
    test=b%2;
    if (test==0) {bintab[licznik]=0;} else {bintab[licznik]=1;}
    liczba=liczba/2;
    cout<< bintab[licznik];      
     }
 } break;
 }
 system("pause");
   return 0;
 }
