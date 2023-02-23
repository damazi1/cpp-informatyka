#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

void wypelnij(int *t,const int n){
  t[0]=2;
  t[1]=3;
  for(int i=2;i<n;i++){
    t[i]=t[i-1]+t[i-2];
  }
}
void wypisz(int *t,const int n){
  for (int i=0;i<n;i++){
    cout<<t[i]<<endl;
  }
}
int suma_fib(int*t, const int n){
  int suma=0;
  for (int i=0;i<n;i++){
    suma+=t[i];
  }
  return suma;
}
int liczba_fib(int *t,const int n){
  int liczba=0;
  for (int i=0; i<n;i++){
    if (t[i]%2==1){
      liczba++;
	}
  }
  return liczba;
}
int main(){
  int n;
  cin>>n;
  int*t=new int [n];
  wypelnij(t,n);
  wypisz(t,n);
  cout<<"suma to: "<<suma_fib(t,n)<<" liczba nieparzystych "<< liczba_fib(t,n)<<endl;
  if(t){
    delete[]t;
    t=0;
  }

  return 0;
}
