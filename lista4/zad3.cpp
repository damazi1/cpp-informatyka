#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>

using namespace std;

bool palindrom(const char*src){
    size_t n=strlen(src);
    size_t i=0,j=n-1;
    for (;i<j;i++,j--){
        while(src[i]==' ')i++;
        while(src[j]==' ')j--;
        // while(src[i]=='?')i++;
        // while(src[j]=='?')j--;
        while(src[i]=='!')i++;
        while(src[j]=='!')j--;
        // while(src[i]=='.')i++;
        // while(src[j]=='.')j--;
        while(src[i]==',')i++;
        while(src[j]==',')j--;        //usunąć znaki białe od <a i większe niż z>
        if(src[i]!=src[j]){
            return false;
    }
    }
    cout<<"Twoje zdanie jest palindromem"<<endl;
    return true;
}

int main(int argc,char*argv[]){
    if(argc!=2){
        cerr<<"Nieprawidłowa ilośc przekazanych argumentów(2)!"<<endl;
        cout<<"Wymagane argumenty to: ./nazwa,zdanie"<<endl;
        return 1;
    }
    cout<<"\n"<<palindrom(argv[1])<<endl;
    return 0;
}