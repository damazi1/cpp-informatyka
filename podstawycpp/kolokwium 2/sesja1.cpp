#include <iostream>
#include <cstring>

using namespace std;

char* wstaw(const char* zrodlo, char symbol){
    size_t n=strlen(zrodlo)+strlen(zrodlo)/3+2;
    char* dest=new char [n];
    for(int i=0,j=0;i<n;i++){
        if(i%4==0){
            dest[i]=symbol;
        }
        else{
            dest[i]=zrodlo[j];
            j++;
        }
    }
    return dest;
}

int szukaj(const char* zrodlo,char symbol){
    size_t n =strlen(zrodlo);
    int wynik=0;
    for (int i=0;i<n;i++){
        if(zrodlo[i]==symbol){
            wynik++;
        }
    }
    return wynik;
}

char* tou(const char* zrodlo){
    size_t n=strlen(zrodlo);
    char* dest=new char [n];
    for (int i=0;i<n;i++){
        dest[i]=toupper(zrodlo[i]);
    }
    return dest;
}

int main(){
    char* zrodlo={"Ala ma male kotki"};
    char symbol='X';
    char* dest=wstaw(zrodlo,symbol);
    cout<<dest<<endl;
    cout<<szukaj(zrodlo,'e')<<endl;
    cout<<tou(zrodlo)<<endl;
    return 0;
}