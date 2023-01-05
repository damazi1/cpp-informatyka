#include <iostream>

using namespace std;
int main(){
    int n=7;
    int tab[n];
    for (int i=n-1;i>=0;i--){
        if(i%2==0){
            tab[i]=2;
        }
        else{
            tab[i]=0;
        }
    }
     for (int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}