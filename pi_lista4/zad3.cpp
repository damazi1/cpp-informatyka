#include <iostream>

using namespace std;
int main(){
    int n=4;
    int tab[n];
    for (int i = 1; i < n; i++){
        tab[i]=i*i*i;
    }
    for (int i=1;i<n;i++){
        cout<<tab[i]<<endl;
    }
    return 0;
    
}