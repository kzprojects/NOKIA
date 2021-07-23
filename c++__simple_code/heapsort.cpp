#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int q=0,p=0;

int build(int d[],int rozmiar){
  for(int i=2;i<=rozmiar;i++)
  {int j=i;int k=j/2;int x=d[i];
    while((k>0)&&(d[k]<x)){d[j]=d[k];j=k;k=j/2;}
  d[j]=x;}}
int heapsort(int d[],int rozmiar){
  for(int i=rozmiar;i>1;i--)
  {swap(d[1],d[i]);int m,j=1,k=2;
    while(k<i){
      if((k+1<i)&&(d[k+1]>d[k])){p++;m=k+1;}
      else m=k;
      if(d[m]<=d[j]){p++;break;}
      swap(d[j],d[m]);q++;
      j=m;k=j+j;
    }}}
  
int main(){
int a[1001];
a[0]=0;
char wybor;
do{
cout<<"\n\nWybierz typ tablicy: \n";
cout<<"[1] - tablica losowa\n[2] - tablica poukladana 1-1000\n[3] - tablica poukladana 1000-1\n";
cin>>wybor;
switch(wybor){
case '1': 
   srand((unsigned)time(NULL));
   for(int i=1;i<1001;i++){a[i]=rand()%1000;}
   cout<<"Tablica: "<< endl;
   for(int i=1;i<1001;i++){cout<<a[i]<<" ";}
   cout<< endl;
   break;
case '2':
   for(int i=1;i<1001;i++){a[i]=i+1;}break;
case '3':
   for(int i=1;i<1001;i++){a[i]=1000-i;}break;
case '0': return 0;
default: cout<<"\n---!!!Nieprawidlowa wartosc!!!---"<<endl;break;}
int rozmiar=1001;
build(a,rozmiar);
cout<<"\nKopiec:\n";
for(int i=1;i<1001;i++){cout<<a[i]<<" ";}
heapsort(a,rozmiar);
cout<<"\nPosorotowano:\n";
for(int i=1;i<1001;i++){cout<<a[i]<<" ";}
cout<<"\nIlosc przestawien: "<<q<<"\nIlosc porownan: "<<p;
cout<< endl;
}
while(wybor!=0);

system("PAUSE");
return 0;}
