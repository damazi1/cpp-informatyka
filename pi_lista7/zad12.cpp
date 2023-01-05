#include <iostream>

using namespace std;
void suw(int*tab,const int n){
    int pam=tab[n-1];
    for (int i=n-2;i>=0;i--){
        tab[i+1]=tab[i];
    }
    tab[0]=pam;
}
int main(){
    const int n=7;
    int tab[n]={1,2,3,4,5,6,7};
    suw(tab,n);
    for (int i=0;i<n;i++){
        cout<<tab[i]<<", ";
    }
    cout<<endl;
    return 0;
}