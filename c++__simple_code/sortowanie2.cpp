#include <iostream>		
using namespace std;


const int ilosc_elementow = 10; 
int x, wylosowane[ilosc_elementow];
int tab[ilosc_elementow];
int taba[ilosc_elementow];
int tabb[ilosc_elementow]; 
int tabc[ilosc_elementow]; 
typedef int TYP;
int T[10];
void wygenerujliczby()
{
//  srand((unsigned)time(NULL)); losowane liczby nie beda sie powtarzac
 for (x = 0; x < ilosc_elementow; x++)
 {
 wylosowane[x] = taba[x] = tabb[x] = tab[x] = tabc[x] = T[x] = 1 + rand() % (ilosc_elementow + ilosc_elementow);
 }
 
}
 
 
int babelkowe()
{

 for (int licza=0; licza<ilosc_elementow-1; licza++)
 {
  for (int liczb=licza; liczb<ilosc_elementow; liczb++)
  {
   if (tab[liczb]<tab[licza])
   {
   int temporary;
   temporary = tab[licza];
   tab[licza]=tab[liczb];
   tab[liczb]=temporary;
   }
  }
 }
return 0;
}

int wstawianie()
{
int licza, liczb;	
int temp;   
 for (licza = ilosc_elementow-2; licza >= 0; licza--)
 {
 liczb = licza;
 temp = tabb[licza];
  while ((liczb < ilosc_elementow-1) && (temp > tabb[liczb+1]))
  {
  tabb[liczb] = tabb[liczb+1];
  liczb++;
  }
 tabb[liczb] = temp;
 }

 return 0;
}
 
 
int wybieranie()
{
size_t liczc, liczd, t;
int z;
 
  // w³aœciwe sortowanie przez wybieranie
  for(liczc = 0; liczc < ilosc_elementow - 1; liczc++)
  {
    t = liczc;
    for (liczd = liczc + 1; liczd < ilosc_elementow; liczd ++)
 
    // porownanie
      if (taba[liczd]< taba[t])
        t = liczd;
    z = taba[t]; taba[t] = taba[liczc]; taba[liczc] = z;
  }
 

return 0;   
}



void QuickSort(TYP *T, int Lo, int Hi)
{
   int i,j;
   TYP z;
   z = T[(Lo+Hi)/2];
   i = Lo;
   j = Hi;
   do
   {
      while (T[i] < z) i++;
      while (T[j] > z) j--;
      if (i<=j)
      {
         TYP tmp = T[i];
         T[i] = T[j];
         T[j] = tmp;
         i++; j--;
      }
    } 
   while(i < j);
   if (Lo < j) QuickSort(T, Lo, j);
   if (Hi > i) QuickSort(T, i, Hi);
}
 
int main()
{
wygenerujliczby();
wybieranie();
wstawianie();
babelkowe(); 

QuickSort(T,0,ilosc_elementow-1);

// wyswietlenie sortowania 
 cout << "Sortowanie przez:\n" ;
 cout << "------------------------------------------------------------------\n" 
 << " lp       przed    wstawienie   wybieranie    babelkowe     quicksort\n"
 << "------------------------------------------------------------------------" << endl;
  for(x = 0; x < ilosc_elementow; x++)
  {
    cout.width(4); cout << x + 1;
    cout.width(10); cout << wylosowane[x];
    cout.width(10); cout << tabb[x] ;
	cout.width(10); cout << taba[x] ;
	cout.width(15); cout << tab[x] ;
	cout.width(15); cout << T[x] << endl;
  };
  cout << "------------------------------------------------------------------------" << endl;
  cout << endl;

system("pause"); 
return 0;
}
