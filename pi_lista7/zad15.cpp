#include <iostream>

using namespace std;
void wyp(int*tab,const int n){
    for(int i=n-1;i>=0;i--){
        if(i%2==0){
            tab[i]=0;
        }
        else{
            tab[i]=2;
        }
    }
}
int main(){
    const int n=17;
    int tab[n];
    wyp(tab,n);
    for (int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}