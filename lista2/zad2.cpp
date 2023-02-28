#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

void wypelnij(int *t, const int n){
    for (int i=0;i<n;i++){
        t[i]=rand()%10000;
    }
}

int piv(int *tab, int lewy, int prawy){
    int pv=tab[prawy];
    int i=lewy-1;
    for (int j=lewy;j<=prawy-1;j++){
        if (tab[j]<pv){
            i++;
            swap(tab[i],tab[j]);
        }
    }
    swap(tab[i+1],tab[prawy]);
    return (i+1);
}
void dzielizwyciezaj(int *tab,int lewyindeks,int prawyindeks){
    if(lewyindeks<prawyindeks){
        int pi=piv(tab,lewyindeks,prawyindeks);
        dzielizwyciezaj(tab,lewyindeks,pi-1);
        dzielizwyciezaj(tab,pi+1,prawyindeks);
    }
}


int main(){
srand(time(NULL));
  int n;
  cin >>n;
  cout<<endl;
  int*tab=new int[n];
  wypelnij(tab,n);
  dzielizwyciezaj(tab,0,n-1);
  int min=tab[0];
  int max=tab[n-1];
  for (int i=0;i<n;i++){
    cout<<tab[i]<<endl;
  }
  cout<<min<<" oraz "<<max;
    if(tab){
    delete[] tab;
    tab=0;
    }
  
  return 0;
}