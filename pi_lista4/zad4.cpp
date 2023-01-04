#include <iostream>

using namespace std;

int main(){
    int n=6;
    int tab[n];
    for(int i=0;i<n;i++){
        tab[i]=5+i;
    }
    for(int i=0;i<n;i++){
        cout<<tab[i]<<endl;
    }
    return 0;
}