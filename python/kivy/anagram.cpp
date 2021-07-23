#include <iostream.h>
#include <string.h>

//program wyznacza anagram danego lancucha znakow
// (tzn. odwraca go)
// ........................
void anagram(char[]);
void zamiana(char&,char&);

int main(){
  char L[100];
  
  cout << " Podaj lancuch znaków : ";
  cin.get(L,100);

  anagram(L);
  
  cout << "Anagram podanego lancucha to \n" << L << endl;
system("pause");
  return 0;
}

// ........................

void zamiana(char &x,char &y){
  char pom=x;
  x=y;
  y=pom;
}
void anagram(char L[]){
  int i;
  int dl=strlen(L);		// funkcja strlen zwraca dlugosc lancucha


  for ( i=0 ; i<dl/2 ; i++ )
    zamiana(L[i],L[dl-1-i]);
}
  
    
