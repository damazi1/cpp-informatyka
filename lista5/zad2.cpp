#include<iostream>
#include<string>
#include<cstring>
#include <algorithm>


using namespace std;

int liczba_wyrazow(string src){
    int slowa=0;
    size_t n=src.size(),i=0;
    while(src=="  "){
        auto spacje=unique(src.begin(),src.end(),[](char const &lhs,char const &rhs){
        return(lhs==rhs)&&(lhs==' ');
    });
    src.erase(spacje,src.end());
}
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
    }
    cout<<"Twoja liczba wyrazów wynosi: "<<liczba_wyrazow(argv[1])<<endl;
    return 0;
}