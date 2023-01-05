#include <iostream>

using namespace std;
int main(){
    int n=9;
    int tab[n];
    for (int i=n-1;i>=0;i--){
        tab[i]=i;
    }
        for (int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}