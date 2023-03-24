#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string szyfrowanie(string src,char klucz){
    size_t n=src.size(),i=0;
    for(i=0;i<n;i++){
        src[i]=src[i]^klucz;
    }
    return src;
}

int main(int argc,char *argv[]){
    if(argc!=3){
        cerr<<"Podana ilosc argumentów jest błędna (3)\n";
        cout<<"Poprawna zapis to ./nazwa zdanie klucz\n";
        return 1;
    }

    string zaszyfrowane=szyfrowanie(argv[1],argv[2][0]);
    cout<<"Zdanie po zaszyfrowaniu: "<<zaszyfrowane<<endl;
    zaszyfrowane=szyfrowanie(zaszyfrowane,argv[2][0]);
    cout<<"Zdanie po odszyfrowaniu: "<<zaszyfrowane<<endl;

    return 0;
}