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

int suma_fib(int *tab,unsigned int n){
  int suma=0;
  unsigned int i=0;
  for (;i<n;i++){
    suma+=tab[i];
  }
  return suma;
}

int liczba_fib(int *tab,unsigned int n){
  int liczba=0;
  unsigned int i=0;
  for(;i<n;i++){
    if(tab[i]%2!=0){
      liczba++;
    }
  }
  return liczba;
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

  cout<<"Suma "<<n<<" pierwszych wyrazow ciagu to: "<<suma_fib(tab,n)<<endl;
  cout<<"Liczba nieparzystych wyrazow "<<liczba_fib(tab,n)<<endl;
  
  usun(tab);

  return 0;
}
