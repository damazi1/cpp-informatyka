#include<iostream>
#include<string>
#include<cstring>
#include <algorithm>


using namespace std;

int liczba_wyrazow(string src){
    int slowa=0;
    size_t n=src.size(),i=0;
    for(;i<n;i++){
        if(isspace(src[i+1])){
            if(isspace(src[i])){
                src.erase(i,1);
                i--;
            }
        }
    }
    i=0;
        for(;i<n;i++){
        if((src[i+1])==','){
            if(isspace(src[i])){
                src.erase(i,1);
                i--;
            }
        }
        }
    i=0;
    for (;i<n;i++){
        if(src[i]==' '){
            slowa++;
        }
    }
    return slowa+1;
}

int main(int argc,char *argv[]){
    if(argc!=2){
        cerr<<"Błędna ilośc argumentów (2)"<<endl;
        cout<<"Poprawna budowa to ./nazwa zdanie"<<endl;
        return 1;
    }
    cout<<"Twoja liczba wyrazów wynosi: "<<liczba_wyrazow(argv[1])<<endl;
    return 0;
}