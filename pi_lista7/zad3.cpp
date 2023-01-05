#include <iostream>

using namespace std;
void szesc(int *tab,const int n){
    for (int i=0;i<n;i++){
        tab[i]=i*i*i;
    }
}

int main(){
    const int n=7;
    int tab[n];
    szesc(tab,n);
    for (int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}