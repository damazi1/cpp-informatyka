#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>

using namespace std;

char*wstaw(const char* zrodlo,char symbol){
    size_t dlugosc=strlen(zrodlo)+strlen(zrodlo)/3+2;
    char *dane=new char[dlugosc];
    size_t i=0,j=0;
    for (;j<dlugosc&&zrodlo[i];j++){
        if(j%4==0){
            dane[j]=symbol;
        }
        else{
            dane[j]=zrodlo[i];
            i++;
        }
    }
    dane[j]=0;
    return dane;
}
void wstaw(char* cel,const char* zrodlo,char symbol){
    size_t n=strlen(zrodlo)+strlen(zrodlo)/3+2;
    size_t i=0,j=0;
    for (;j<n&&zrodlo[i];j++){
        if(j%4==0){
            cel[j]=symbol;
        }
        else{
            cel[j]=zrodlo[i];
            i++;
        }   
    }
    cel[j]=0;
}
void wstaw1(char*& cel,const char *zrodlo,char symbol){
    size_t dlugosc=strlen(zrodlo)+strlen(zrodlo)/3+2;
    cel=new char [dlugosc];
    size_t i=0,j=0;
    for (;j<dlugosc&&zrodlo[i];j++){
        if(j%4==0){
            cel[j]=symbol;
        }
        else{
            cel[j]=zrodlo[i];
            i++;
        }        
    }
    cel[j]=0;
    
}
int szukaj(const char*zrodlo,char symbol){
    int liczba=0;
    size_t n=strlen(zrodlo),i=0;
    for(;i<=n;i++){
        if(zrodlo[i]==symbol){
            liczba++;
        }
    }    
    return liczba;
}
char *kopiuj(const char*zrodlo){
    char *nowa=new char[strlen(zrodlo)];
    size_t n=strlen(zrodlo),i=0;
    for(;i<=n;i++){
        if(islower(zrodlo[i])){
            nowa[i]=toupper(zrodlo[i]);
        }
        else{
            nowa[i]=zrodlo[i];
        }
    }
    return nowa;
}

void usun(char *t){
    if(t){
        delete []t;
        t=0;
    }
}


int main(int argc,char *argv[]){
    if(argc!=3){
        cerr<<"Nieprawidłowa ilośc przekazanych argumentów(3)!"<<endl;
        cout<<"Wymagane argumenty to: ./nazwa,napis,symbol"<<endl;
        return 1;
    }
    char*a=wstaw(argv[1],argv[2][0]);
    cout<<a<<endl;
    size_t dlugosc=strlen(argv[1])+strlen(argv[1])/3+2;
    char *b=new char[dlugosc];
    char *c=nullptr;
    wstaw(b,argv[1],argv[2][0]);
    wstaw1(c,argv[1],argv[2][0]);
    cout<<"\n\t"<<b<<"\n\t"<<c<<endl;

    cout<<szukaj(a,'m')<<endl;
    a=kopiuj(argv[1]);
    cout<<a<<endl;

    usun(a);
    usun(b);
    usun(c);
    return 0;
}