#include <iostream>

using namespace std;

int main(int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podano bledna ilosc argumentow(1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa\n";
        return 1;
    }
    bool *tab;
    int n;
    cout<<"Podaj ostatnia liczbe z przedzialu <2...n>: ";
    cin>>n;

    tab =new bool [n+1];
    for(int i=2; i<=n;i++){
        tab[i]=0;
    }
    for(int i=2;i*i<=n;i++){
        if(!tab[i]){
            for (int j=i*i;j<=n;j+=i){
                tab[j]=1;
            }
        }
    }
    cout <<"Kolejne liczby pierwsze z przedziału [2.."<<n<<"]: \n";
    for(int i=2;i<=n;i++){
        if(!tab[i]){
            cout<<i<<" , ";
        }
    }
 
    if(tab){
        delete []tab;
        tab=nullptr;
    }

    return 0;
}