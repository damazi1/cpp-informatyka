#include <iostream>
#include <cstring>

using namespace std;

int liczba_wyrazow(const char *src){
    size_t n=strlen(src);
    int liczba=0;
    char* tab=new char [n+1];
    for(size_t i=0;i<n;i++){
        tab[i]=toupper(src[i]);
    }
    
    size_t j=0;
    for(size_t i=0,j=0;i<n;i++){
        if(tab[i]>=65&&tab[i]<=90){
            tab[j]=tab[i];
            j++;
        }
        else{
            tab[j]=' ';
            j++;
        }
    }
    tab[j]='\0';
    
    for(size_t i=0;i<n;i++){
        if(isspace(tab[i])){
            if(!isspace(tab[i-1])){
                liczba++;
            }
        }
    }
    
    delete [] tab;

    return liczba+1;
}

int main(int argc,char *argv[]){
    if(argc!=2){
        cerr<<"Podano bledna ilosc argumentow()"<<endl;
        cout<<"Poprawny zapis to ./nazwa zdanie"<<endl;
        return 1;
    }

    cout<<liczba_wyrazow(argv[1])<<endl;

    return 0;
}