#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

void wypelnij(int *t, const int n){
    for (int i=0;i<n;i++){
        t[i]=rand()%100;
    }
}

void min_max(int *t,const int n,int niska,int wysoka,int &min,int &max){
    int max1,min1,mid;
    if(niska==wysoka){
        max=min=t[niska];
        }
        else{
            if(niska==wysoka-1){
                if(t[niska]<t[wysoka]){
                    max=t[wysoka];
                    min=t[niska];
                }
                else {
                    max=t[niska];
                    min=t[wysoka];
                }
            }
            else{
                mid=(niska+wysoka)/2;
                min_max(t,n,niska,mid,min,max);
                max1=max; min1=min;
                min_max(t,n,mid+1,wysoka,min,max);
                if(max<max1){
                    max=max1;
                }
                if(min>min1){
                    min=min1;
                }
            }
        }
}

int main(){
srand(time(NULL));
  int n;
  cout<<"podaj n: ";
  cin >>n;
  cout<<endl;
  int*tab=new int[n];
  int min;
  int max;
  wypelnij(tab,n);
  min_max(tab,n,0,n-1,min,max);
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