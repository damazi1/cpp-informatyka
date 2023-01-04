#include "fib.h"
#include <iostream>

using namespace std;

int nieparzyste(int*t,const int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(t[i]%2!=0){
            count++;
        }
    }
    return count;
}

int main(){
    const int n=5;
    int tab[n]={1,1};
    fib(tab,n);
    int s=nieparzyste(tab,n);
    cout<<s<<endl;
}