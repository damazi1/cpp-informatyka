#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>

using namespace std;

int liczba_wyr(const char*src){
    int liczba_w=0;
    size_t srclen=strlen(src),i=0;
    for(;i<srclen;i++){
        if(src[i]==' '){
            liczba_w++;
        }
    }
    liczba_w++;
    return liczba_w;
}

int main(int argc,char*argv[]){
    cout<<"Liczba wyrazów w podanym zdaniu to: "<<liczba_wyr(argv[1])<<endl;
    return 0;
}