#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

void wypelnij(int* tab,const int n){
  for (int i=0;i<n;i++){
    tab[i]=rand()%100;
      }
}
void wypisz(const int* tab,const int n){
  for (int i=0;i<n;i++){
    cout<<tab[i]<<endl;
  }
}

int maksymalna(int *tab,const int n){
    int max=tab[0];
    for(int i=1;i<n;i++){
      if(max<tab[i]){
	max=tab[i];
      }
    }
    return max;
}

int pozycja(const int* tab,const int n){
  int poz=0;
  for (int i=0;i<n;i++){
    if(tab[poz]<tab[i]){
      poz=i;
    }
  }
  return poz;
}
int main(){
  srand(time(NULL));
  int n;
  cin >>n;
  cout<<endl;
  int*tab=new int[n];
  wypelnij(tab,n);
  wypisz(tab,n);
  maksymalna(tab,n);
  int poz=pozycja(tab,n);
  cout << "liczba maksymalna to "<<maksymalna(tab,n)<<" a jej pozycja to: "<<poz<<endl;
    if(tab){
      delete[] tab;
      tab=0;
    }
  
  return 0;
}
