#include <iostream>

using namespace std;

void usun(int *tab){
    if(tab){
        delete [] tab;
        tab=nullptr;
    }

}

int main(int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podano bledna ilosc argumentow(1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa\n";
        return 1;
    }

    int *tab;
    int n,a,i=0;
    cout<<"Podaj stopien wielomianu: ";
    cin>>n;

    tab=new int [n+1];

    for(;i<=n;i++){
        cout<<"Podaj współczynnik stojący przy potędze "<<n-i<<": ";
        cin>>tab[i];
    }
    cout<<"Podaj argument: ";
    cin >>a;

    int wynik=tab[0];
    for(i=1;i<=n;i++){
        wynik=wynik*a+tab[i];
    }
    cout<<"Twoj wynik to: "<<wynik<<endl;

    usun(tab);

    return 0;
}