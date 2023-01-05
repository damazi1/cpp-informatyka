#include <iostream>

using namespace std;
void wyp(int *tab,const int n){
    for(int i=0;i<n;i++){
        tab[i]=5+i;
    }
}
int main(){
    const int n=7;
    int tab[n];
    wyp(tab,n);
    for(int i=1;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}