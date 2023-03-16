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
    // for(;i<n;i++){
    //     if(src[i]=='?'||'.'||','||'-'||'!'||'('||')'){
            
    // }
    for (;i<j;i++,j--){
        if(src[i]==' '||'?'||'.'||','||'-'||'!'||'('||')'){
            i++;
        }
        if(src[j]==' '||'?'||'.'||','||'-'||'!'||'('||')'){
            j--;
        }
        if(src[i]!=src[j]){
            return false;
    }
    }
    cout<<"Twoje zdanie jest palindromem"<<endl;
    return true;
}

int main(int argc,char*argv[]){
    cout<<"\n"<<palindrom("a!?la ala")<<endl;
    return 0;
}