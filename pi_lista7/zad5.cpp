#include <iostream>

using namespace std;
void wyp(int *tab,const int n){
    for(int i=0;i<n;i++){
        if(i%2==0){
            tab[i]=i*2;
        }
        else{
            tab[i]=i%3;
        }
    }
}
int main(){
    const int n=7;
    int tab[n];
    wyp(tab,n);
    for(int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}