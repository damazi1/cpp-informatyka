#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <fstream>


using namespace std;

void wypisz(int* tab,const unsigned int n){
  for(unsigned int i=0;i<n;i++){
    cout<<tab[i]<<'\t';
  }
}

void wypelnij(int *tab,const unsigned int n){
  int max;
  cout<<"Podaj wartosc maksymalna jaka moze przyjac liczba: ";
  cin>>max;
  for(unsigned int i=0;i<n;i++){
    tab[i]=rand()%max;  

  }
}

void wypisz(int *tab,const int parm,const unsigned int n){
  for(unsigned int i=0;i<n;i++){
    if(tab[i]>parm){
      cout<<tab[i]<<'\t';
    }
  }
}

int* dodawanie(int *tab,const unsigned int n){
  int *tab1=new int [n];
  for(unsigned int i=0;i<n;i++){
    tab1[i]=tab[i]+tab[i];
  }
  return tab1;
}

void zapisz(ofstream& fout,int *tab,const unsigned int n){
  if(fout.good()){
    for(unsigned int i=0;i<n;i++){
      fout << tab[i]<<";\n";
    }
  }
}

void usun (int *tab){
  if(tab){
    delete [] tab;
    tab = nullptr;
  }
}

int main(int argc,char* argv[]){
  if (argc!=3){
    cerr<<"Podano bledna ilosc argumentow(3)"<<endl;
    cout<<"Poprawny zapis to ./nazwa liczba plik_wyj"<<endl;
    return 1;
  }
  srand(time(NULL));
  unsigned int n;
  int *tab;
  cout<<"Podaj wielkosc tablicy: ";
  cin>>n;
  
  tab=new int [n];

  size_t k=atoi(argv[1]);
  
  wypelnij(tab,n);
  cout<<"Wypelniona tablica: \n";
  wypisz(tab,n);


  cout<<"\nelementy wieksze niz "<<k<<": "<<endl;
  wypisz(tab,k,n);

  int* tab1=dodawanie(tab,n);
  cout<<"\nDodawanie tablicy: \n";
  wypisz(tab1,n);
  cout<<endl;

  ofstream fout;
  fout.open(argv[2]);
  zapisz(fout,tab1,n);
  fout.close();
  usun(tab);
  usun(tab1);
  
  return 0;
}
