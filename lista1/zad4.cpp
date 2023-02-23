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
int srednia(int *t,const int n){
  int sr=0;
  int ile=0;
  for (int i=0;i<n;i++){
    sr+=t[i];
    ile++;
  }
  return sr/ile;
}
int srednia_parz(int*t,const int n){
  int sr=0;
  int ile=0;
  for (int i=0;i<n;i++){
    if(t[i]%2==0){
      
