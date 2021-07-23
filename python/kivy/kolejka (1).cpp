#include<iostream>
using namespace std;

class element
{
   int wartosc;
   class element *next;
   friend class kolejka;
};

class kolejka
{
   element *first;
   element *last;
 public:
   kolejka()
     {
	first=last=NULL;
     }
   ~kolejka();
   int czy_pusta()
     {
	return(first==NULL);
     }
   void wstaw(int x);
   int odloz(int &x);
};

kolejka::~kolejka()
{
  
}


void kolejka::wstaw(int x)
{
   element *nowy = new element;
   nowy->wartosc=x;
   nowy->next=NULL;
   if (first==NULL)
     {
	first=last=nowy;
     }
   else
     {
	last->next=nowy;
	last=nowy;
     }
}

int kolejka::odloz(int &x)
{
   if (last==first)
     {
	if (first!=NULL)
	  {
	     x=first->wartosc;
	     cout<<"odlozony";
	     delete first;
	     first=last=NULL;
	     return 1;
	  }
     }
   else
     {
	element *pomoc=first;
	x=first->wartosc;
	first=first->next;
	delete pomoc;
	return 1;
     }
   return 0;
}

int main()
{
   kolejka Kolejka;
   int menu, liczba, kontrola;
   
   for (;;)
     {
        cout<<"Wybierz:\n1 - wstawienie do kolejki";
        cout<<"\n2 - odlozenie z kolejki";
        cout<<"\n0 - wyjscie z programu"<<endl;
	cin>>menu;
	switch (menu)
	  {
	   case 1:
	       {
		  cout<<"Podaj liczbe do wstawienia"<<endl;
		  cin>>liczba;
		  Kolejka.wstaw(liczba);
		  break;
	       }
	   case 2:
	       {
		  if (!Kolejka.czy_pusta())
		    {
		       kontrola=Kolejka.odloz(liczba);
		       if (kontrola) 
			 {
			  cout<<"Pobrana liczba to: "<<liczba<<endl;
			 }
		       else 
			 {
			    cout<<"nie udalo sie pobrac liczby"<<endl;
			 }
		    }
		  else 
		    {
		       cout<<"Kolejka pusta"<<endl;
		    }
		  break;
	       }
	     case 0:
	       {
		  Kolejka.~kolejka();
		  break;
	       }
	   default: 
	       {
		  cout<<"Musisz wybrac jedna z opcji 0-2"<<endl;
		  break;
	       }
	  }
	if (!menu) break;
     }
     system("pause");
   return 0;
}

	  
