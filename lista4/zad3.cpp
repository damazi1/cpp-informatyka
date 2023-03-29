#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>

using namespace std;

void palindrom(char*src){
    size_t n=strlen(src);
    size_t i=0,j=n,k=0;
    char *palin=new char[n+1];
    for (;i<j;i++){
        if((src[i] >=65 && src[i] <= 90 )|| (src[i] >= 97 && src[i] <= 122)){
            palin[k]=toupper(src[i]);
            k++;
        }
    }
    palin[k]='\0';
    size_t l=strlen(palin);
    bool result=1;
    for(i=0,j=l-1;i<j;i++,j--){
        if(palin[i]!=palin[j]){
            cout<<"\nTwoje zdanie nie jest palindromem\n";
            result=0;
            break;
        }
    }

    if(result)cout<<"\nTwoje zdanie jest palindromem"<<endl;

    if(palin){
        delete [] palin;
        palin=nullptr;
    }
}

int main(int argc,char*argv[]){
    if(argc!=2){
        cerr<<"Nieprawidłowa ilośc przekazanych argumentów(2)!"<<endl;
        cout<<"Wymagane argumenty to: ./nazwa,zdanie"<<endl;
        return 1;
    }
    palindrom(argv[1]);
    // palindrom ("Ala mam Ala");
    return 0;
}