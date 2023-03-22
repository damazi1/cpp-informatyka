#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>

using namespace std;

void palindrom(char*src){
    size_t n=strlen(src);
    size_t i=0,j=n;
    char *palin=new char[n];
    for (;i<j;i++){
        palin[i]=toupper(src[i]);
        cout<<palin[i];
    }
    i=0;
    j=n;
    cout<<endl;
    int *tab=new int [n];
    for(;i<j;i++){
        tab[i]=(int)palin[i];
    }
    i=0;
    for(;i<j;i++){
        if(tab[i]>=65){
            palin[i].replace('')
        }
        if(tab[i]<=90){
            src[i]=palin[i];
        }
    }
    cout<<endl;
    for(i=0;i<j;i++){
        cout<<src[i];
    }
    i=0;
    j=n-1;
    for(;i<j;i++,j--){
        if(src[i]!=src[j]){
            return;
        }
    }
    cout<<"\nTwoje zdanie jest palindromem"<<endl;
}

int main(int argc,char*argv[]){
    // if(argc!=2){
    //     cerr<<"Nieprawidłowa ilośc przekazanych argumentów(2)!"<<endl;
    //     cout<<"Wymagane argumenty to: ./nazwa,zdanie"<<endl;
    //     return 1;
    // }
    palindrom("Ala mam AlA");
    return 0;
}