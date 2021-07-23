#include<iostream.h>
#include<stdio.h>
class bfs{
  public: int *tab, r, max;
  
  bfs(int wielkosc)
     {tab=new int[wielkosc];
     r=0;
     for(int i=0;i<wielkosc;i++)//wyzerowanie tablicy
     tab[i]=0;
     } 
     
  int wstaw(int element){
    int spr=0,j=0;
    while(spr==0){
     if(tab[j]==0) {tab[j]=element;spr=1;}
     else j++;}
  }
  int szukaj(int wanted, int wielkosc){
    int spr=0;
    for(int i=0;i<wielkosc;i++)
    {if(tab[i]==wanted) {cout<<"Liczba znaleziona na pozycji "<<i<< endl;spr=1;
    }}
    if(spr==0) cout<<"Liczby nie ma w tablicy. :("<< endl;
  }
};

int main(){
int wielkosc,a,wanted;
cout<<"Podaj wielkosc: ";
cin>>wielkosc;
bfs tablica(wielkosc);
for(int i=0;i<wielkosc;i++)
  {cout<<"Podaj element "<<i<<": ";
  cin>>a;
  tablica.wstaw(a);
  }
cout<<"Podaj poszukiwana liczbe: ";
cin>>wanted;
tablica.szukaj(wanted,wielkosc);
system("pause");
return 0;
}
