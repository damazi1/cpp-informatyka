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
float dzielizwyciezaj()
void min_max(int *t,const int n,int lewyindeks,int prawyindeks, int &min,int &max){
    if(lewyindeks==prawyindeks){
        min = t[lewyindeks];
        max = t[lewyindeks];
    }
    int sr = (lewyindeks+prawyindeks)/2;
    for (int i=0; i<n;i++){
        if (min>t[i]){
            min=t[i];
        }
        if (max)
    }
}

int main(){
srand(time(NULL));
  int n;
  cin >>n;
  cout<<endl;
  int min=0;
  int max=0;
  int*tab=new int[n];
  wypelnij(tab,n);
    if(tab){
    delete[] tab;
    tab=0;
    }
  
  return 0;
}