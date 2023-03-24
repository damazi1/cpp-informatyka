#include <iostream>
#include <cstring>
#include <string>
#include <array>
#include <cmath>
#include <cstdlib>

using namespace std;

void Dane(string*&dane,size_t&n){
    size_t i=0;
    cout<<"Podaj liczbe danych które chcesz wporwadzic: "<<endl;
    cin>>n;
    dane=new string [n];
    cout<<"Podaj dane\n";
    for(;i<n;i++){
        cin>>dane[i];
        cout<<endl;
    }
}

void szukaj(const string*dane,string *mails,const size_t n){
    size_t i=0,j=0,k=0;
    for(;i<n;i++){
        size_t m=dane[i].size();
        for(j=0;j<m;j++){
            if(dane[i][j]=='@'){
                mails[k]=dane[i];
                k++;
            }
        }
    }
}

void usun(string *wyr){
    if(wyr){
        delete [] wyr;
        wyr=nullptr;
    }
}

int main(int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podano błędną ilośc argumentów(1)"<<endl;
        cout<<"Poprawna forma to ./nazwa"<<endl;
        return 1;
    }
    string *dane,*maile;
    size_t n=0;
    Dane(dane,n);
    maile=new string [n];
    szukaj(dane,maile,n);
    size_t i=0;
    cout<<"Uzyskane maile to: \n";  
    for(i=0;i<n;i++){
        cout<<i<<". "<<maile[i]<<endl;
    }

    usun(dane);
    usun(maile);

    return 0;
}