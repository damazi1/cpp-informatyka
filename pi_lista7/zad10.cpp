#include <iostream>

using namespace std;
void wyp(int*tab,const int n){
    for (int i=0;i<n;i++){
        if(i<(n/2)){
            tab[i]=i;
        }
        else{
            tab[i]=i*2;
        }
    }
}
int main(){
    const int n=8;
    int tab[n];
    wyp(tab,n);
    for(int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}