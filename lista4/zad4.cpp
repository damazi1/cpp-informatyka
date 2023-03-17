#include<iostream>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cstdio>

using namespace std;

char* szyfruj(const char*tab,const char*key)
{
    size_t g=strlen(tab);
    int *n=new int[g];
	size_t i=0;
    for(;i<g;i++){
        n[i]=(int)tab[i];
        // cout<<n[i]<<endl;
    }
    int kk=0;
    for(size_t i=0;i<g;i++){
        kk+=(int)key[i];
    }
    for(size_t i=0;i<g;i++){
        int klucz=kk;
        if(n[i]>=65&&n[i]<=90)
        while(klucz>0){
            if(n[i]>90){
                n[i]=65;
            }
            n[i]=n[i]+1;
            klucz--;
        }
    }
        for(size_t i=0;i<g;i++){
            int klucz=kk;
            if(n[i]>=97&&n[i]<=122)
            while(klucz>0){
                if(n[i]>122){
                    n[i]=97;
                }
                n[i]=n[i]+1;
                klucz=klucz-1;
            }
        }
    // for(size_t i=0;i<g;i++){
    //     cout<<n[i]<<endl;
    // }
    char*szyfr=new char [g];
    for(size_t i=0;i<g;i++){
        szyfr[i]=(char)n[i];
    }
    return szyfr;
}
char* rozszyfruj(const char*tab,const char*key)
{
    size_t g=strlen(tab);
    int *n=new int[g];
	size_t i=0;
    for(;i<g;i++){
        n[i]=(int)tab[i];
        // cout<<n[i]<<endl;
    }
    int kk=0;
    for(size_t i=0;i<g;i++){
        kk+=(int)key[i];
    }
    for(size_t i=0;i<g;i++){
        int klucz=kk;
        if(n[i]>=65&&n[i]<=90)
        while(klucz>0){
            if(n[i]<65){
                n[i]=90;
            }
            n[i]=n[i]-1;
            klucz--;
        }
    }
        for(size_t i=0;i<g;i++){
            int klucz=kk;
            if(n[i]>=97&&n[i]<=122)
            while(klucz>0){
                if(n[i]<97){
                    n[i]=122;
                }
                n[i]=n[i]-1;
                klucz=klucz-1;
            }
        }
    // for(size_t i=0;i<g;i++){
    //     cout<<n[i]<<endl;
    // }
    char *szyfr=new char[g];
    for(size_t i=0;i<g;i++){
        szyfr[i]=(char)n[i];
    }
    return szyfr;
}
int main(int argc,char*argv[]){
    cout<<szyfruj(argv[1],argv[2])<<endl;
    cout<<rozszyfruj(szyfruj(argv[1],argv[2]),argv[2])<<endl;
    return 0;
}