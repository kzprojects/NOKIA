#include <iostream.h>
#include <stdio.h>

int dznabin(int liczba,int tab[],int g)
{int i=0;
while(liczba!=0){
    if(liczba%2==0)
      {tab[i]=0;
      liczba=liczba/2;
      }
    else
      {tab[i]=1;
      liczba=(liczba-1)/2;
      }
    i++;}
    
cout<<"Liczba binarna: ";
for(int j=g-1;j>=0;j--)
    {cout<<tab[j];
    }
}

//---------main-----------------
int main()
{int liczba;
cout<<"Podaj liczbe: ";
cin>>liczba;

//-----------liczba komorek tablicy binarnej---------
int g=0;
int tmp=liczba;
while(tmp!=0)
  {if(tmp%2==0)
   tmp=tmp/2;
  else
   tmp=(tmp-1)/2;
  g++;
  }
cout<<"Liczba komorek tablicy: "<<g<< endl;

int *tab=new int[g];
dznabin(liczba,tab,g);

cout<< endl;
system("pause");
return 0;
}
