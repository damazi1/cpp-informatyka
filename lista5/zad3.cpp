#include <iostream>
#include <cstring>
#include <string>
#include <array>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

void Dane(string*&dane,size_t&n){
    size_t i=0;
    n=99;
    dane=new string [n];
    cout<<"Podaj dane osobowe\n: ";
    for(;i<n;i++){
        getline(cin,dane[i]);
        if(dane[i]=="END"||dane[i]=="end")break;
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
    size_t i=0,m=0;
    for(i=0;i<n;i++){
        if(!maile[i].empty())m++;
    }
    cout<<"Uzyskane maile to: \n";
    for(i=0;i<m;i++){
        cout<<i+1<<". "<<maile[i]<<endl;
    }

    ofstream outfile("maile.txt");

    for(i=0;i<m;i++){
        outfile<<maile[i]<<"; ";
    }
    outfile.close();
    
    usun(dane);
    usun(maile);

    return 0;
}