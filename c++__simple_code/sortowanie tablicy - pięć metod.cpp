#include <iostream>
#include <time.h>
using namespace std;
int pb=0,qb=0,ps=0,qs=0,pw=0,qw=0,qq=0,pq=0,ph=0,qh=0;
int babelkowa(int a[],int rozmiar)
{int p=0,q=0; for(int i=1;i<rozmiar;i++){for(int j=rozmiar-1;j>=i;j--)
{q++;if(a[j]<a[j-1]){p++;int tmp=a[j-1];a[j-1]=a[j];a[j]=tmp;}}}
for(int i=0;i<rozmiar;i++){cout<<a[i]<<" ";}
cout<<"\nIlosc przestawien: "<<p<<"\nIlosc porownan: "<<q;
pb=p;qb=q;
}
int selekcja (int a[],int rozmiar)
{int p=0,q=0; for(int i=0;i<rozmiar;i++){int min=i; for(int j=i+1;j<rozmiar;j++){q++;if(a[j]<a[min]){p++; 
int tmp=a[j];a[j]=a[min];a[min]=tmp;}}}
for(int i=0;i<rozmiar;i++){cout<<a[i]<<" ";}
cout<<"\nIlosc przestawien: "<<p<<"\nIlosc porownan: "<<q;
ps=p;qs=q;
}
int wstawianie(int a[],int rozmiar)
{int p=0,q=0; for(int i=0;i<rozmiar;i++){int j=i;int t=a[j];if(!(a[j-1]>t))q++;
while((j>0)&&(a[j-1]>t)){q++;p++; a[j]=a[j-1];j--;}a[j]=t;}
for(int i=0;i<rozmiar;i++){cout<<a[i]<<" ";}
cout<<"\nIlosc przestawien: "<<p<<"\nIlosc porownan: "<<q;
pw=p;qw=q;
}
int quicksort(int a[],int l, int r)
{int v=a[(l+r)/2];
int i,j,x;i=l;j=r;
   do{
     while (a[i]<v){i++;pq++;}pq++;
     while (a[j]>v){j--;pq++;}pq++;
     if (i<=j){pq++;x=a[i];a[i]=a[j];a[j]=x;qq++;i++;j--;}
   }while(i<=j);pq++;
   if(j>l) quicksort(a,l,j);
   if(i<r) quicksort(a,i,r); 
}
int build(int d[],int rozmiar){
  for(int i=2;i<=rozmiar;i++)
  {int j=i;int k=j/2;int x=d[i];
    while((k>0)&&(d[k]<x)){d[j]=d[k];j=k;k=j/2;}
  d[j]=x;}}
int heapsort(int d[],int rozmiar){int p=0,q=0;
  for(int i=rozmiar;i>1;i--)
  {swap(d[1],d[i]);int m,j=1,k=2;
    while(k<i){
      if((k+1<i)&&(d[k+1]>d[k])){p++;m=k+1;}
      else m=k;
      if(d[m]<=d[j]){p++;break;}
      swap(d[j],d[m]);q++;
      j=m;k=j+j;
    }}ph=p;qh=q;}
    
int main(){
int a[1000],b[1000],c[1001];
c[0]=0;
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

for(int i=0;i<1000;i++){b[i]=a[i];}
int r=1000;
cout<<"Babelkowa: "<< endl;
babelkowa(b,r);
cout<< endl;
for(int i=0;i<1000;i++){b[i]=a[i];}
cout<<"Selekcja: "<< endl;
selekcja(b,r);
cout<< endl;
for(int i=0;i<1000;i++){b[i]=a[i];}
cout<<"Wstawianie: "<< endl;
wstawianie(b,r);
cout<< endl;
for(int i=0;i<1000;i++){b[i]=a[i];}
cout<<"Quicksort: "<< endl;
quicksort(b,0,r-1);
for(int i=0;i<1000;i++){cout<<a[i]<<" ";}
cout<<"\nIlosc przestawien: "<<qq<<"\nIlosc porownan: "<<pq<< endl;
for(int i=0;i<1000;i++){c[i+1]=a[i];}
cout<<"Heapsort: "<< endl;
build(c,r);
cout<<"\nKopiec:\n";
for(int i=1;i<1001;i++){cout<<c[i]<<" ";}
heapsort(c,r);
cout<<"\nPosorotowano:\n";
for(int i=1;i<1001;i++){cout<<c[i]<<" ";}
cout<<"\nIlosc przestawien: "<<ph<<"\nIlosc porownan: "<<qh;



cout<< endl;cout<< endl;
cout<<"ZESTAWIENIE:"<< endl;
cout<< endl;
cout<<"Babelkowe: ilosc przestawien - "<<pb<<" ilosc porownan - "<<qb<< endl;
cout<<"Selekcja: ilosc przestawien - "<<ps<<" ilosc porownan - "<<qs<< endl;
cout<<"Wstawianie: ilosc przestawien - "<<pw<<" ilosc porownan - "<<qw<< endl;
cout<<"Quicksort: ilosc przestawien - "<<qq<<" ilosc porownan - "<<pq<< endl;
cout<<"Heapsort: ilosc przestawien - "<<ph<<" ilosc porownan - "<<qh<< endl;
system("PAUSE");
return 0;}
