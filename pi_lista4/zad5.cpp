#include <iostream>

using namespace std;

int main(){
    int n=11;
    int tab[n];
    for (int i=0;i<n;i++){
        if(i%2==0){
            tab[i]=i*2;
        }
        else{
            tab[i]=i%3;
        }
    }
    for(int i=0;i<n;i++){
        cout<<tab[i]<<endl;
    }
}