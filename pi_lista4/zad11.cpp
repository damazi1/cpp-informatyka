#include <iostream>

using namespace std;
int main(){
    int n=7;
    int tab[n]={1,1};
    for (int i=2;i<n;i++){
        tab[i]=tab[i-1]+tab[i-2];
    }
    for (int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}