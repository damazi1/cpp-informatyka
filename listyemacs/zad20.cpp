#include<iostream>
#include<cstring>

using namespace std;

void szyfruj(char *src,size_t key){
    size_t n=strlen(src);
    for(size_t i=0;i<n;i++){
        src[i]=toupper(src[i]);
    }
    size_t klucz=key;
    for(size_t i=0;i<n;i++){
        if(!isspace(src[i])){
            while(klucz>0){
                src[i]++;
                if(src[i]>90){
                    src[i]=65;
                }
                klucz--;
            }
        }
        klucz=key;
    }
}

void odszyfruj(char *src,size_t key){
    size_t n=strlen(src);
    size_t klucz=key;
    for(size_t i=0;i<n;i++){
        if(!isspace(src[i])){
            while(klucz>0){
                src[i]--;
                if(src[i]<65){
                    src[i]=90;
                }
                klucz--;
            }
        }
        klucz=key;
    }
}

int main(int argc,char*argv[]){
    if(argc!=3){
        cerr<<"Podana ilosc argumentow jest bledna(3)"<<endl;
        cout<<"Poprawny zapis to ./nazwa zdanie klucz(liczba od<1,25>)"<<endl;
        return 1;
    }
    size_t n=atoi(argv[2]);
    
    szyfruj(argv[1],n);
    cout<<"Zdanie zaszyfrowane: "<<argv[1]<<endl;
    
    odszyfruj(argv[1],n);
    cout<<"Zdanie odszyfrowane: "<<argv[1]<<endl;
    return 0;
}