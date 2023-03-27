#include <iostream>

using namespace std;


void wypelnij(int *tab,const unsigned int n){
  tab[0]=0;
  tab[1]=1;
  for(unsigned int i=2;i<n;i++){
    tab[i]=tab[i-1]+tab[i-2];
  }
}

void wypisz(int *tab,const unsigned int n){
  unsigned int i=0;
  for(;i<n;i++){
    cout<<i+1<<". "<<tab[i]<<endl;
  }
}

float srednia(int *tab,const unsigned int n){
  unsigned int i=0;
  float srednia=0;
  for (;i<n;i++){
    srednia+=tab[i];
  }
  return srednia/n;
}

float srednia_parz(int *tab,const unsigned int n){
  unsigned int i=0;
  float srednia=0;
  int dzielnik=0;
  for(;i<n;i++){
    if(tab[i]%2==0){
      srednia+=tab[i];
      dzielnik++;
    }
  }
  return srednia/dzielnik;
}


float srednia_podz(int *tab,const unsigned int n){
  unsigned int i=0;
  float srednia=0;
  int dzielnik=0;
  for(;i<n;i++){
    if(i%3==0){
      srednia+=tab[i];
      dzielnik++;
    }
  }
  return srednia/dzielnik;
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
  unsigned int n;
  cout<<"Podaj wielkosc tablicy: ";
  cin>>n;
  
  tab=new int [n];
  
  wypelnij(tab,n);
  wypisz(tab,n);

  cout<<"Twoja srednia to: "<<srednia(tab,n)<<endl;
  cout<<"Twoja srednia z liczb parzystych to: "<<srednia_parz(tab,n)<<endl;
  cout<<"Twoja srednia z indeksow podzielnych przez 3 to: "<<srednia_podz(tab,n)<<endl;

  usun(tab);
  
  return 0;
}
