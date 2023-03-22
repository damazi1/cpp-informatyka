#include<iostream>
#include<cstring>
#include<string>

using namespace std;

void kopiuj(const string src,char*& dest){
    
    const size_t n=src.size();
    dest=new char [n+1];
    strcpy(dest,src.c_str());
}

string wstaw(const string src,const char s,size_t p){
    string dest=src;
    size_t n=1;
    dest.insert(p,n,s);
    return dest;
}

string wstaw(const string src,const string s,size_t p){
    string dest=src;
    dest.insert(p,s);
    return dest;
}

string wytnij(const string src,size_t n){
    string dest=src;
    dest.erase(0,n);
    return dest;
}

int szukaj(const string src, const char s){
    int poz=0;
    poz=src.find(s);
    return poz;
}

int szukaj(const string src,const char*s){
    int poz=0;
    poz=src.find(s);
    return poz;
}

int porownaj(const string s1, const string s2){
    size_t n=s1.size();
    size_t m=s2.size();
    if(n==m)return 0;
    if(n<m)return -1;
    else{
        return 1;
    }
}

void usun(char*t){
    if(t){
        delete [] t;
        t=nullptr;
    }
}


int main(int argc, char*argv[]){
    if(argc!=3){
        cerr<<"Zla ilosc argumentow (3)"<<endl;
        cout<<"Prawidłowy zapis funkcji to ./nazwa zdanie1 zdanie2"<<endl;
    }
    // size_t n=strlen(argv[1]);
    char *dest=nullptr;

    kopiuj(argv[1],dest);
    cout<<dest<<endl;

    cout<<wstaw(argv[1],'X',3)<<endl;

    cout<<wstaw(argv[1]," i grzegorz",3)<<endl;

    cout<<wytnij(argv[1],4)<<endl;

    cout<<"a znajduje się na "<<szukaj(argv[1],'a')<<" indeksie tego zdania"<<endl;

    cout<<"słowo ala zaczyna się na "<<szukaj(argv[1],"ala")<<" indeksie tego zdania"<<endl;

    cout<<"Porównanie: "<<porownaj(argv[1],argv[2])<<endl;

    usun(dest);

    return 0;
}