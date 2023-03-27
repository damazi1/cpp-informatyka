#include <iostream>
#include <cmath>

using namespace std;

void wypelnij(float *tab,const unsigned int n){
  int pierwsza;
  cout<<"Podaj pierwsza liczbe: ";
  cin>>pierwsza;
  float pierwiastek=sqrt(pierwsza);
  tab[0]=pierwsza;
  unsigned int i=1;
  for (;i<n;i++){
    tab[i]=tab[i-1]+pierwiastek;
  }
}

void wypisz(float *tab,const unsigned int n){
  unsigned int i=0;
  for (;i<n;i++){
    cout<<i+1<<". "<<tab[i]<<endl;
  }
}

void przesun(float *tab,const unsigned int n){
  unsigned int i=n-1;
  float temp=tab[n-1];
  
  for (;i>0;i--){
    tab[i]=tab[i-1];
  }
  tab[0]=temp;
}

void usun(float*tab){
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
  float *tab;
  unsigned int n;
  cout<<"Podaj wielkosc tablicy: ";
  cin>>n;
  
  tab=new float [n];

  wypelnij(tab,n);
  wypisz(tab,n);
  cout <<endl;
  przesun(tab,n);
  wypisz(tab,n);

  usun(tab);
    
  return 0;
}
