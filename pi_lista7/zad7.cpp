#include <iostream>

using namespace std;
int szuk(int *tab,const int n){
    int szuka=0;
    for (int i=0;i<n;i++){
        if(tab[szuka]<tab[i]){
            szuka=i;
        }
    }
    return szuka;
}
int main(){
    const int n=7;
    int tab[n]={1,2,3,9,8,3,5};
    cout<<"Maksymanlna liczba ma indeks "<<szuk(tab,n)<<endl;
    return 0;
}