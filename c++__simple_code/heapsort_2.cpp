#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int q=0,p=0,pozycja=1,ku=0;int nowy;
class kopiec{public: 
int a[1000];

kopiec(){for(int i=0;i<1000;i++){a[i]=0;}}
int wstaw(int nowy){a[pozycja]=nowy;pozycja++;}
int wyjmij(){
    if(pozycja>0){ku=a[pozycja-1];a[pozycja-1]=0;pozycja--;}
    else cout<<"kopiec jest pusty\n";}
int build(){
  for(int i=2;i<=pozycja;i++)
  {int j=i;int k=j/2;int x=a[i];
    while((k>0)&&(a[k]<x)){a[j]=a[k];j=k;k=j/2;}
  a[j]=x;
  }cout<<"\nKopiec:   ";for(int i=1;i<pozycja;i++){cout<<a[i]<<" ";}cout<< endl;}
int heapsort(){
  for(int i=pozycja-1;i>1;i--)
  {swap(a[1],a[i]);int m,j=1,k=2;
    while(k<i){
      if((k+1<i)&&(a[k+1]>a[k])){p++;m=k+1;}
      else m=k;
      if(a[m]<=a[j]){p++;break;}
      swap(a[j],a[m]);q++;
      j=m;k=j+j;
    }}cout<< endl;for(int i=1;i<pozycja;i++){cout<<a[i]<<" ";}}
};
int main(){
kopiec nowyKopiec;   
char wybor;
do{
cout<<"[1] - wstaw\n[2] - wyjmij\n[3] - sortuj!\n";
cout<<"Wybor: ";
cin>>wybor;
switch(wybor){
case '1': 
   cout<<"Podaj wartosc do wstawienia: ";
   cin>>nowy;
   nowyKopiec.wstaw(nowy);
   nowyKopiec.build();
   break;
case '2':
   nowyKopiec.wyjmij();
   nowyKopiec.build();
   cout<<"Wyjeto: "<<ku<< endl;
   break;
case '3':
   nowyKopiec.heapsort();
   cout<<"\nPosorotowano\n";
   //for(int i=1;i<pozycja;i++){cout<<a[i]<<" ";}
   cout<<"\nIlosc przestawien: "<<q<<"\nIlosc porownan: "<<p;
   cout<< endl;
   break;
case '0': return 0;
default: cout<<"\n---!!!Nieprawidlowa wartosc!!!---"<<endl;break;}
/*WYPISANIE
cout<<"\nKopiec:\n";
for(int i=1;i<1001;i++){cout<<a[i]<<" ";}*/
}
while(wybor!=0);
system("PAUSE");
return 0;}
