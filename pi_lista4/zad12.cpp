#include <iostream>

using namespace std;
int main(){
    int n=7;
    int tab[n]={1,2,3,4,5,6};
    for (int i=n-1;i>=0;i--){
        tab[i]=tab[i-1];
    }
    for (int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}