#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

string szyfruj(string src,size_t klucz){
    size_t n=src.size(),i=0,j=0;
    for(i=0;i<n;i++){
        src[i]=toupper(src[i]);
    }
    for(i=0;i<n;i++){
        if(!isspace(src[i])){
            for(j=0;j<klucz;j++){
                src[i]=src[i]+1;
                if(src[i]>90)src[i]=65;
            }
        }
    }
    return src;
}

string rozszyfruj(string src,size_t klucz){
    size_t n=src.size(),i=0,j=0;
    for(i=0;i<n;i++){
        if(!isspace(src[i])){
            for(j=0;j<klucz;j++){
                src[i]=src[i]-1;
                if(src[i]<65)src[i]=90;
            }
        }
    }
    return src;
}

int main(int argc, char* argv[]){
    if (argc!=3){
        cerr<<"Podana błędną ilość argumentów(3)\n";
        cout<<"Poprawny zapis to ./nazwa zdanie klucz(liczba <1,25>)";
        return 1;
    }
    size_t n=atoi(argv[2]);
    string zaszyfrowana=szyfruj(argv[1],n);
    cout<< zaszyfrowana<<endl;
    cout<<rozszyfruj(zaszyfrowana,n);

    return 0;
}