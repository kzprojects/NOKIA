#include <iostream.h>
#include <stdlib.h>
#include<stdio.h>

double zaokr(double x)
{
int y=x*10000;
if (y%10>=5) y+=10;
return (y/10)*0.001;
}

int main(){
int a;
double x;
cout<<"Podaj liczbe, ktorej pierwiastek policzyc: ";
cin>>a;
cout<<"Podaj dowolne x (domniemany pierwiastek): ";
cin>>x;
double b=a/x;
double x1;
double pol=0.5;   
while(true)
{x1=pol*(x+b);   //zmienic do ilus po przecinku
b=a/x1;
x1=zaokr(x1);
b=zaokr(b);
x=x1;
if(b==x1)
break;
}
cout<<"Wynik: "<<x;

 system("PAUSE");
 return 1;
}
