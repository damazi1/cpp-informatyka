#include <iostream>

using namespace std;
void fib(int*tab,const int n){
    tab[0]=1;
    tab[1]=1;
    for(int i=2;i<n;i++){
        tab[i]=tab[i-1]+tab[i-2];
    }
}
int main(){
    const int n=7;
    int tab[n];
    fib(tab,n);
    for (int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}