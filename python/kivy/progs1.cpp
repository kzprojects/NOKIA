#include <iostream>		
using namespace std;


const int ilosc_elementow = 10; 
int i, wylosowane[ilosc_elementow];
int tab[ilosc_elementow];
int tab1[ilosc_elementow];
int tab2[ilosc_elementow]; 
int tab3[ilosc_elementow]; 
typedef int TYP;
int T[10];
void wygenerujliczby()
{
//  srand((unsigned)time(NULL)); losowane liczby nie beda sie powtarzac
 for (i = 0; i < ilosc_elementow; i++)
 {
 wylosowane[i] = tab1[i] = tab2[i] = tab[i] = tab3[i] = T[i] = 1 + rand() % (ilosc_elementow + ilosc_elementow);
 }
 
}
 
 
int przezbabelkowe()
{

 for (int licz1=0; licz1<ilosc_elementow-1; licz1++)
 {
  for (int licz2=licz1; licz2<ilosc_elementow; licz2++)
  {
   if (tab[licz2]<tab[licz1])
   {
   int temporary;
   temporary = tab[licz1];
   tab[licz1]=tab[licz2];
   tab[licz2]=temporary;
   }
  }
 }
return 0;
}

int przezwstawianie()
{
int licz1, licz2;	
int temp;   
 for (licz1 = ilosc_elementow-2; licz1 >= 0; licz1--)
 {
 licz2 = licz1;
 temp = tab2[licz1];
  while ((licz2 < ilosc_elementow-1) && (temp > tab2[licz2+1]))
  {
  tab2[licz2] = tab2[licz2+1];
  licz2++;
  }
 tab2[licz2] = temp;
 }

 return 0;
}
 
 
int przezwybieranie()
{
size_t licz3, licz4, t;
int x;
 
  // w³aœciwe sortowanie przez wybieranie
  for(licz3 = 0; licz3 < ilosc_elementow - 1; licz3++)
  {
    t = licz3;
    for (licz4 = licz3 + 1; licz4 < ilosc_elementow; licz4 ++)
 
    // porownanie
      if (tab1[licz4]< tab1[t])
        t = licz4;
    x = tab1[t]; tab1[t] = tab1[licz3]; tab1[licz3] = x;
  }
 

return 0;   
}



void QuickSort(TYP *T, int Lo, int Hi)
{
   int i,j;
   TYP x;
   x = T[(Lo+Hi)/2];
   i = Lo;
   j = Hi;
   do
   {
      while (T[i] < x) i++;
      while (T[j] > x) j--;
      if (i<=j)
      {
         TYP tmp = T[i];
         T[i] = T[j];
         T[j] = tmp;
         i++; j--;
      }
   } while(i < j);
   if (Lo < j) QuickSort(T, Lo, j);
   if (Hi > i) QuickSort(T, i, Hi);
}
 
int main()
{
wygenerujliczby();
przezwybieranie();
przezwstawianie();
przezbabelkowe(); 
//przezquickSort(tab3, 0, ilosc_elementow-1);
QuickSort(T,0,ilosc_elementow-1);

// wyswietlenie sortowania 
 cout << "Sortowanie przez:\n" ;
 cout << "------------------------------------------------------------------\n" 
 << " lp       przed    wstawienie   wybieranie    babelkowe     quicksort\n"
 << "------------------------------------------------------------------------" << endl;
  for(i = 0; i < ilosc_elementow; i++)
  {
    cout.width(4); cout << i + 1;
    cout.width(10); cout << wylosowane[i];
    cout.width(10); cout << tab2[i] ;
	cout.width(10); cout << tab1[i] ;
	cout.width(15); cout << tab[i] ;
	cout.width(15); cout << T[i] << endl;
  };
  cout << "------------------------------------------------------------------------" << endl;
  cout << endl;

system("pause"); 
return 0;
}
