#include <iostream>
using namespace std;

int main()
{     srand((int) time(NULL));
      int n; 
    cout<<" Podaj ilosc elementow\n";
    cin>>n;
    int tab[n];   
    cout<<endl;
    for(int i=0;i<n;i++)
{  tab[i]=rand()%49+1;      
cout<<tab[i]<<"  ";    //wpisywanie danych
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
  cout<<"\n\nPosortowane elementy:\n\n";
    for(int i=0;i<n;i++)
{   cout<<sort[i]<<"  ";           //wypisanie posortowanych liczb
}
    cout<<endl;
    system("pause");
    return 0;
}
