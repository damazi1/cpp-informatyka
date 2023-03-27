#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void wypelnij(int *tab,const int n){
  int i=0;
  for(;i<n;i++){
    tab[i]=rand()%10;
  }
}
void wypisz(int *tab,const int n){
  int i=0;
  for(;i<n;i++){
    cout<<i+1<<". "<<tab[i]<<endl;
  }
}

void usun(int *tab){
  if(tab){
    delete [] tab;
    tab=nullptr;
  }
}

void sortuj(int *tab,const int n){
  int i=0;
  int pom;
  pom=tab[0];
  for(;i<n-1;i++){
    if(tab[i]>tab[i+1]){
      pom=tab[i];
      tab[i]=tab[i+1];
      tab[i+1]=pom;
      i=-1;
    }
  }
}

void szukaj(int *tab,const int n){
  int szukana,l=0,p=n-1,sr=0;
  cout<<"Podaj szukana liczbe: ";
  cin>>szukana;
  while(l<=p){
    sr=(l+p)/2;
    if(tab[sr]== szukana){
      cout<<"Liczba "<<szukana<<" znajduje sie na ideksie "<<sr<<endl;
      return;
    }
    if(tab[sr]>szukana)p=sr-1;
    else{l=sr+1;}
  }
  cout<<"Ta liczba nie znajduje sie w tablicy."<<endl;
  return;
}

int main(int argc,char *argv[]){
  if (argc!=1){
    cerr<<"Podana liczba argumentow jest bledna(1)\n";
    cout<<"Poprawny zapis to ./nazwa\n";
    return 1;
  }
  srand(time(NULL));
  int *tab;
  unsigned int n;
  cout<<"Podaj wielkosc tablicy: ";
  cin>>n;
  
  tab=new int [n];

  wypelnij(tab,n);
  wypisz(tab,n);
  cout <<"\nPosortowany ciag: \n";
  sortuj(tab,n);
  wypisz(tab,n);

  szukaj(tab,n);

  usun(tab);
  
  return 0;
}
