#include <iostream>
using namespace std;

int main()
{        int n; 
    cout<<" Podaj ilosc elementow\n";
    cin>>n;
    int tab[n];   
    
    for(int i=0;i<n;i++)
{   cout<<i+1<<" element: "; 
    cin>>tab[i];           //wpisywanie danych
}
    int max=tab[0];
    
    for(int i=0;i<n;i++)
{   if(max<tab[i])         
      {  max=tab[i];       //max   
      }
}
//----------------------------------------
      int sort[n];                  //algorytm sortowania      
      int min;
      int a;
    for(int k=0;k<n;k++)
{   min=max;                              
    a=k;
    for(int i=0;i<n;i++)
    {   if(min>tab[i])  
         {
         min=tab[i];
        a=i;                
         }   
    }
    tab[a]=max;
    sort[k]=min;
}  
//--------------------------------------------------
  cout<<"\n Posortowane elementy:\n";
    for(int i=0;i<n;i++)
{   cout<<sort[i]<<endl;           //wypisanie posortowanych liczb
}
    system("pause");
    return 0;
}
