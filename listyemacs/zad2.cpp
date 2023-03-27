#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void wypelnij(int *tab,const int n){
  for(int i=0;i<n;i++){
    tab[i]=rand()%100;
  }
}

void wypisz(int *tab,const int n){
  for(int i=0;i<n;i++){
    cout<<i+1<<". "<<tab[i]<<endl;
  }
}

int maksymalna(int *tab,const int n){
  int max=tab[0],i=0;
  for(i=0;i<n;i++){
    if(max<tab[i]){
      max=tab[i];
    }
  }
  return max;
}

int pozycja(int *tab,const int n){
  int poz=0,i=0;
  for (i=0;i<n;i++){
    if(tab[poz]<tab[i]){
      poz=i;
    }
  }
  return poz;
}

void usun(int*tab){
  if(tab){
    delete [] tab;
    tab=nullptr;
  }
}

int main(int argc,char *argv[]){
  if(argc!=1){
    cerr<<"Podano bledna ilosc argumentow(1)"<<endl;
    cout<<"Poprawny zapis to ./nazwa"<<endl;
    return 1;
  }
  srand(time(nullptr));
  int *tab;
  int n;
  cout <<"Podaj wielkosc tablicy: ";
  cin>>n;
  tab=new int [n];

  wypelnij (tab,n);
  wypisz (tab,n);

  cout<<"Maksymalna liczba to: "<< maksymalna(tab,n)<<endl;

  cout<<"Indeks na ktorym znajduje sie maksymalna liczba to: "<<pozycja(tab,n)<<endl;
  
  usun (tab);
  return 0;
}
