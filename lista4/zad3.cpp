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
        if(src[i]!=src[j]){
            return false;
        }
    }
    return true;
}

int main(int argc,char*argv[]){
    cout<<"\n"<<palindrom(argv[1])<<endl;
    return 0;
}