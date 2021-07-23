#include <iostream.h>
#include <stdlib.h>
#include<stdio.h>

int main(){
int stopien, x;
cout<<"***Schemat Hornera***"<< endl;
cout<<"Podaj stopien: ";
cin>>stopien;
int *tab; 
tab = new int[stopien+1];
cout<<"Podaj liczby: "<< endl;
for(int i=0;i<(stopien+1);i++)
{cout<<"xi: ";
cin>>tab[i];}
cout<<"Podaj x, dla ktorego policzyc wartosc: ";
cin>>x;

int k=stopien;
int b=tab[k];
int b2;
for(int j=0;j<stopien;j++)
{b2=tab[k-1]+(b*x);
b=b2;
k--;}
cout<<"Wynik: "<<b;

system("PAUSE");
return 0;
}
