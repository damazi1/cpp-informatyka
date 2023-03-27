#include<iostream>
#include<cstring>
#include<string>

using namespace std;

void palindrom(string src){
    size_t n=src.size(),i=0,j=0;
    string zdanie=src;
    for(i=0;i<n;i++){
        src[i]=toupper(src[i]);
    }
    for(i=0;i<n;i++){
        if((int)src[i]<65){
            src.erase(i,1);
            n--;
            i--;
        }
        if((int)src[i]>90){
            src.erase(i,1);
            n--;
            i--;
        }
    }
    for(i=0,j=n-1;i<j;i++,j--){
        if(src[i]!=src[j]){
            cout<<"Twoje zdanie nie jest palindromem\n";
            return;
        }
    }
    cout<<"Twoje zdanie : "<<zdanie<<" Jest Palindromem.\n";
    cout<<"Twoje zdanie (po przeksztalceniu) : "<<src<<" Jest Palindromem.\n";
}

int main(int argc,char *argv[]){
    if(argc!=2){
        cerr<<"Podano bledna ilosc argumentow (2)"<<endl;
        cout<<"Poprawny zapis to ./nazwa zdanie"<<endl;
        return 1;
    }

    palindrom(argv[1]);

    return 0;
}