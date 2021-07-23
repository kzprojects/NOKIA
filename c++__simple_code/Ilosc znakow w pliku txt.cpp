#include <iostream.h>
#include <stdlib.h>
#include<stdio.h>
#include <math.h>

int main(){
FILE *we;
char znak;
char plik_jawny[20];
int ilosc=0;
cout<<"Podaj nazwe pliku, ktorego tresc ma zostac zaszyfrowana: " ;
cin>>plik_jawny;
if((we=fopen(plik_jawny,"rb"))!=NULL)    //otwieranie pliku 1. do odczytu - w przypadku gdy takiego pliku nie ma program nie wykona sie
{
while((znak=getc(we))!=EOF)
 ilosc++;
 fclose(we);     //zamykanie pliku wejsciowego
 cout<<ilosc;
 }
 system("PAUSE");
 return 1;
}
