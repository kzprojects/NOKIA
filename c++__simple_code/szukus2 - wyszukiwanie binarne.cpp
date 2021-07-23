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
     
   int wstaw(int element,int wielkosc){
    int spr=0,j=0,p2=element,p1=1; 
    if(tab[0]==0){tab[0]=element;spr=1;}
      while(spr==0){
       if(tab[j]!=0)
        {if(tab[j]<=element)
        j++;
        else while(j<wielkosc)
          {p1=tab[j];
          tab[j]=p2;
          p2=p1;
          j++;
          }
        }
       else if(tab[j]==0){tab[j]=element;spr=1;}
       if(j>=wielkosc)spr=1;
      }
    cout<<"Obecna tablica: ";
    for(int j=0;j<wielkosc;j++)
    cout<<"tab["<<j<<"]="<<tab[j]<<" ";
    cout<< endl;
    } 
    
  int szukaj(int wanted, int wielkosc){
     {int spr=0,l=0,r=wielkosc-1;
     while(r>=l)
     {int m=(l+r)/2; 
     if(wanted==tab[m]) {cout<<"Liczba znaleziona na pozycji "<<m<< endl;spr=1;}
     if(wanted<tab[m]) r=m-1;
     else l=m+1;    
     }
     if(spr==0) cout<<"Liczby nie ma w tablicy. :("<< endl;
     } 
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
  tablica.wstaw(a,wielkosc);
  }
  
cout<<"Podaj poszukiwana liczbe: ";
cin>>wanted;
tablica.szukaj(wanted,wielkosc);

system("pause");
return 0;
}
