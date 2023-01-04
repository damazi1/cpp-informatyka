#include "fib.h"
#include <iostream>

using namespace std;

int suma(int*t,const int k){
    int sumac=0;
    for(int i=0;i<k;i++){
        sumac+=t[i];
    }
    return sumac;
}
int main(){
    const int n=10;
    int tab[n]={1,1};
    fib(tab,n);
    for(int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    int k=6;
    int s=suma(tab,k);
    cout << endl << s <<endl;
    return 0;
}
