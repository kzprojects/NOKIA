#include <iostream>
using namespace std;

int p=0,q=0;
int quicksort(int a[],int l, int r)
{int v=a[(l+r)/2];
int i,j,x;i=l;j=r;
   do{
     while (a[i]<v){i++;p++;}p++;
     while (a[j]>v){j--;p++;}p++;
     if (i<=j){p++;x=a[i];a[i]=a[j];a[j]=x;q++;i++;j--;}
   }while(i<=j);p++;
   if(j>l) quicksort(a,l,j);
   if(i<r) quicksort(a,i,r); 
}

int main(){
int a[1000];
char wybor;
cout<<"Wybierz typ tablicy: \n";
cout<<"[1] - tablica losowa\n[2] - tablica poukladana 1-1000\n[3] - tablica poukladana 1000-1\n";
cin>>wybor;
switch(wybor){
case '1': 
   srand((unsigned)time(NULL));
   for(int i=0;i<1000;i++){a[i]=rand()%1000;}
   cout<<"Tablica: "<< endl;
   for(int i=0;i<1000;i++){cout<<a[i]<<" ";}
   cout<< endl;
   break;
case '2':
   for(int i=0;i<1000;i++){a[i]=i+1;}break;
case '3':
   for(int i=0;i<1000;i++){a[i]=1000-i;}break;
default: cout<<"\n---!!!Nieprawidlowa wartosc!!!---"<<endl;break;}

int rozmiar=1000;
quicksort(a,0,rozmiar-1);
cout<<"\nPosorotowano:\n";
for(int i=0;i<1000;i++){cout<<a[i]<<" ";}
cout<<"\nIlosc przestawien: "<<q<<"\nIlosc porownan: "<<p;
cout<< endl;

system("PAUSE");
return 0;}
