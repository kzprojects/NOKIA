#include <iostream.h>
#include <stdlib.h>

void odwracanie(int tab[], int n)
{
     int * tab_o = new int[n];                         //odwracanie tablicy
     for (int i = 0; i < n; i++)
         tab_o[tab[i]] = i;
     for (int i = 0; i < n; i++)
         tab[i] = tab_o[i];
     cout<<"Odwrocona tablica: ";
     for (int i = 0; i < n; i++)
         cout<<tab[i];
     cout<< endl;
}
//------------------------------
int ile(int n)                             //ile jest permutacji
{
    int wynik = 1;
    while (n>0)
    {
          wynik *= n;
          n--;
    }
    return wynik;
}
//------------------------------
void wypisywanie(int tab[],int n)                          //wypisuje permutacje
{
     int m,j, *p=new int[n], *tab_2=new int[n];
     for(int i=0;i<n;i++)
             tab_2[i]=tab[i];
     int l;
     for(l=0;l<ile(n);l++)
     {
         m=l;
         for(int k=2;k<=n;k++)
         {
                 tab_2[k-2]=m%k;
                 m/=k;
         }
         for(int k=0;k<n;k++)
                 p[k] = k;
         for(int k=n;k>=2;k--)
         {
                 j=tab_2[k-2];
                 int tmp=p[j];
                 p[j]=p[k-1];
                 p[k-1]=tmp;
         }
         for(int k=0;k<n;k++)
                 cout<<p[k]<<' ';
         cout<<endl;
     }
     cout<<"Ilosc permutacji: "<<l;
}
//--------------------------
void cykle(int tab[], int n)                                  
{                                                                       
      int k, ile, i=0;
      bool success=false;
      for(i; i<n; i++)
      {
          success=false; //false'ujemy zmienna na nowy cykl
          
          if (i==tab[i])//sprawdzamy sytuacje gdy wartosc w tablicy jest rowna jej indeksowi w tablicy
          {
                        cout<<i<< endl;
                        continue; //do nastepnego cyklu, bo zakonczylismy cykl
          }
          
          k=i;
          ile=0;
          while (k!=tab[i] && ile<=n*n) //sprawdzamy czy istnieje cykl
          {
               k=tab[k];
               ile++;
          }
          if (k==tab[i])
             success=true;
          else
              continue; //skoro nie ma cyklu no to jedziemy na nastepny
          if (success)
          {
                      k=i; //bierzacy cykl go!
                      cout<<k<<" ";
                      k=tab[k];
                      while(i!=k)
                      {
                              cout<<k<<" ";
                              k=tab[k];
                      }
                      cout<<k<< endl;
          }
         
      }   //end of while
}
//-------------------------
int inwersje(int tab[], int n)               //inwersje
{
    int ile=0;
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (tab[i]>tab[j]) 
               ile++;
    cout<<"Ilosc inwersji: "<<ile<<", znak permutacji: ";
    if (ile%2 == 0) 
       cout<<1;
    else 
       cout<<-1;
}

//---------------------------------
int main()
{
    int wybor, jakatab;
    //robimy tablice elementow
    int n;
    do
    {
     cout<<"Wybierz: "<< endl;
     cout<<"0 - Wyjscie z programu."<<endl;
     cout<<"1 - Wypisywanie permutacji."<< endl;
     cout<<"2 - Odwrocenie permutacji tablicy."<< endl;
     cout<<"3 - Wypisywanie cykli."<< endl;
     cout<<"4 - Ile jest inwersji."<< endl;
     cin>>wybor;
     cout<<"------------------------"<< endl;
      cout<< endl;
      cout<<"Podaj wielkosc tablicy: ";
      cin>>n;
      int *tab;
      tab = new int[n];
      cout<< endl;
      cout<<"Tablica automatyczna [1], czy wpisana [2]? ";
      cin>>jakatab;
      switch(jakatab)
      {
           case 1:
           //automat
           { 
                    for(int i=0;i<n;i++)
                            tab[i]=i;                       //³adowanie tablicy
                    cout<<"Twoja tablica: ";
                    for(int i=0;i<n;i++)
                            cout<<tab[i];
           }
           break;

           case 2:
           //wpisywana
           { 
                      for(int i=0;i<n;i++)
                      {
                              cout<<"Element "<<i<<" : ";
                              cin>>tab[i];
                      }
           }
           break;
     }     
     //switch
     switch(wybor)
     {
                  case 1:  wypisywanie(tab,n); break;     //wszystkie permutacje
                  case 2:  odwracanie(tab,n); break;      //odwracanie tablicy
                  case 3:  cykle(tab,n); break;           //wszystkie cykle
                  case 4:  inwersje(tab,n); break;        //inwersje
     }
     system("PAUSE");
     system("cls");
   }
   while(wybor != 0);
   system("PAUSE");
   return 0;
}
