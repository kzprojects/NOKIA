#include <iostream>


using namespace std;

int main(void)
{
  const int N = 20;  // liczebnoœæ zbioru
  int d[N + 1],i,j,k,m,x;

  srand((unsigned)time(NULL));
  cout << "                    \n\n"
          "Przed sortowaniem:\n\n";

// Wype³niamy tablicê liczbami pseudolosowymi i wyœwietlamy je

  for(i = 1; i <= N; i++)
  {
    d[i] = rand() % 100; cout << d[i]<< " , " ;
  }
  cout << endl;

// Budujemy kopiec

  for(i = 2; i <= N; i++)
  {
    j = i; k = j / 2;
    x = d[i];
    while((k > 0) && (d[k] < x))
    {
      d[j] = d[k];
      j = k; k = j / 2;
    }
    d[j] = x;
  }

// Rozbieramy kopiec

  for(i = N; i > 1; i--)
  {
    swap(d[1], d[i]);
    j = 1; k = 2;
    while(k < i)
    {
      if((k + 1 < i) && (d[k + 1] > d[k]))
        m = k + 1;
      else
        m = k;
      if(d[m] <= d[j]) break;
      swap(d[j], d[m]);
      j = m; k = j + j;
    }
  }

// Wyœwietlamy wynik sortowania

  cout << "Po sortowaniu:\n\n";
  for(i = 1; i <= N; i++) cout << d[i] << " , " ;
  cout << endl;
  system("PAUSE"); 
  return 0;
}

