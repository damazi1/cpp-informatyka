#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int *losowanie(int n){
    unsigned int a,b;
    cout<<"Podaj liczby do zakresu a i b <a,b>: ";
    cin>>a>>b;
    int *tab=new int [n];
    for(int i=0;i<n;i++){
        tab[i]=rand()%b+a;
    }
    return tab;
}

void usun(int *tab){
    if (tab){
        delete [] tab;
        tab=nullptr;
    }
}

int main (int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podana wartosc argumentow jest bledna (1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa"<<endl;
        return 1;
    }
    int n=6;
    int * los=losowanie(n);

    for(int i=0;i<n;i++){
        cout<<los[i]<<endl;
    }

    usun(los);
    return 0;
}