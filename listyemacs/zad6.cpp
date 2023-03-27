#include <iostream>
#include <cmath>

using namespace std;

void wypelnij(int*tab,const int n){
  int i=n-1;
  for(i=n-1;i>=0;i--){
    if(i>(n/2)){
      tab[i]=i;
    }
    else{
      tab[i]=pow(i,2);
    }
  }
}

void wypisz(int *tab,const int n){
  int i=0;
  for (;i<n;i++){
    cout<<i+1<<". "<<tab[i]<<endl;
  }
}

void zamien(int *tab,const int n){
  int i=0;
  int liczba;
  cout<<"Podaj liczbe o ktora maja sie zmienic wartosci: ";
  cin>>liczba;
  for(;i<n;i++){
    if(tab[i]%2==0){
      tab[i]+=liczba;
    }
    else{
      tab[i]-=liczba;
    }
  }
}

void usun(int*tab){
  if(tab){
    delete [] tab;
    tab=nullptr;
  }
}


int main(int argc,char *argv[]){
  if (argc!=1){
    cerr<<"Podana liczba argumentow jest bledna(1)\n";
    cout<<"Poprawny zapis to ./nazwa\n";
    return 1;
  }
  int *tab;
  int n;
  cout<<"Podaj wielkosc tablicy: ";
  cin>>n;
  
  tab=new int [n];

  wypelnij(tab,n);
  wypisz(tab,n);

  zamien(tab,n);
  wypisz(tab,n);  
  
  usun(tab);
  
  return 0;
}
