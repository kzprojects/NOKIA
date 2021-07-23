#include <iostream>
using namespace std;

void wczytaj(int tab[], int x)
{cout<<"Podaj liczby: ";
for(int i=0;i<x;i++)
cin>>tab[i];}

void wypisz(int tab[], int x)
{cout<<"Twoje liczby: ";
for(int i=0;i<x;i++)
cout<<tab[i];
cout<< endl;}

int liczbyparzyste(int tab[], int x)
{int ilosc=0;
int suma=0;
for(int i=0;i<x;i++)
{if(tab[i]%2==0) 
{ilosc++;
suma=suma+tab[i];
}
}
cout<<"Ilosc parzystych: ";
cout<<ilosc<< endl;
cout<<"Srednia parzystych:";
cout<<suma/ilosc<< endl;
}
int liczbynieparzyste(int tab[], int x)
{int ilosc=0;
int suma=0;
for(int i=0;i<x;i++)
if(tab[i]%2==0) 
{ilosc++;}
else
suma=suma+tab[i];
cout<<"Ilosc nieparzystych: ";
cout<<x-ilosc<< endl;
cout<<"Srednia nieparzystych:";
cout<<suma/(x-ilosc)<< endl;
}

/*int liczbynip(int &par, int &npar)
{return par,npar;
}

void zamien(int &a, int &b)
{int t;
t=a;
a=b;
b=t;}*/

int main(){
int x;
cout<<"Podaj wielkosc: "; cin>>x;
int *tab=new int[x];

wczytaj(tab,x);
wypisz(tab,x);
liczbyparzyste(tab,x);
liczbynieparzyste(tab,x);

//int a=1;int b=2;zamien(a,b);cout<<a<<b;
system("PAUSE"); return 0;
}
