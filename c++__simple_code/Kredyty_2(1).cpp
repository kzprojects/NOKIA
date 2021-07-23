#include <iostream>
using namespace std;
double pot(double q,double n)
   {double qq=q;
     if(n!=0){
     for(int i=1;i<n;i++)
      {qq*=q;}}
     else {qq=1;}
    return qq;}

int main()
{ double An,Tn,Zn,Sn,S,N,nn,r,q,qN,qnn,qnn1,nn1;
    nn=1;//numer kolejnej raty
    cout<<"Podaj S (kwota kredytu): ";
    cin>>S;
    cout<<"Podaj N (liczba lat): ";
    cin>>N;
    cout<<"Podaj r (oprocentowanie): ";
    cin>>r;
    q=1+r;
    qN=pot(q,N);//n-ta potega liczby q
    
    cout<<"  | An | Tn | Zn | Sn"<< endl;    
    int i=1;
    do{
    nn1=nn-1;
    qnn1=pot(q,nn1);
    qnn=pot(q,nn);
    An=S*qN*((q-1)/(qN-1));//rata ³¹czna
    Zn=S*r*(qN-qnn1)/(qN-1);//rata odsetek
    Sn=S*(qN-qnn)/(qN-1);//pozosta³a do sp³aty czêœæ d³ugu
    Tn=S*(qnn-qnn1)/(qN-1);//rata d³ugu
    cout<<i<<" |  "<<An<<"  |  "<<Tn<<"  |  "<<Zn<<"  |  "<<Sn<< endl;
    i++;nn++;}
    while(nn<=N);
    
    system("PAUSE");
    return 0;
}
