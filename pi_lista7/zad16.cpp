#include <iostream>

using namespace std;
void silnia(int*tab,const int n){
    tab[0]=1;
    tab[1]=2;
    for (int i=2;i<n;i++){
        tab[i]=tab[i-1]*tab[i-2];
    }
}
void silnia2(int *tab,const int n){
    tab[0]=1;
    tab[1]=2;
}
int main(){
    const int n=6;
    int tab[n];
    silnia(tab,n);
    
}