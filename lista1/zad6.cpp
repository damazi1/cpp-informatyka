#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

void wypelnij(int* t,const int n){
    for (int i=n-1;i>=0;i--){
        if(i>n/2){
            t[i]=i;
        }
        else{
            t[i]=pow(i,2);
        }
    }
}
void wypisz(int*t,const int n){
    for(int i=0;i<n;i++){
        cout<<t[i]<<endl;
    }
}
void zamien(int*t,const int n,const int liczba){
    for (int i=0;i<n;i++){
        if(t[i]%2==0){
            t[i]+=liczba;
        }
        else{
            t[i]-=liczba;
        }
    }
}
int main(){
    int n;
  cout<<"podaj n: ";
  cin>>n;
  int liczba;
  cout<<endl<<"podaj liczbę: ";
  cin>>liczba;
  int*t=new int [n];
  wypelnij(t,n);
  wypisz(t,n);
  cout<<"zamienione liczby: "<<endl;
  zamien(t,n,liczba);
  wypisz(t,n);
  if(t){
    delete[]t;
    t=0;
  }
  return 0;


}