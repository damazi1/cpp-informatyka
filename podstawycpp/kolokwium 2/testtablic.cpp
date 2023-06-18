#include <iostream>

using namespace std;

void utworz(int*& tab, const unsigned int n){
    tab=new int [n];
}

void wypelnij (int *tab, const unsigned int n){
    for(int i=0;i<n;i++){
        tab[i]=i;
    }
}

void wypisz (int *tab, const unsigned int n){
    for(int i=0;i<n;i++){
        cout<<tab[i]<<endl;
    }
}

void usun(int *tab){
    if(tab){
        delete [] tab;
        tab=nullptr;
    }
}

int main(){
    int*tab= nullptr;
    utworz(tab,5);
    wypelnij(tab,5);
    wypisz(tab,5);
    usun(tab);
    return 0;
}