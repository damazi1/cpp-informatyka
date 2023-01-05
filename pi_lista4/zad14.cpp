#include <iostream>

using namespace std;
int main(){
    int n=8;
    int tab[n];
    for (int i=n-1;i>=0;i--){
        if(i>(n/2)){
            tab[i]=i*i;
        }
        else{
            tab[i]=i;
        }
    }
        for (int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}