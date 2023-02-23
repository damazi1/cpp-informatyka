#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;
void sito(bool *t,const int n){
    for(int i=2;i*i<=n;i++){
        if(!t[i]){
            for(int j=i*i;j<=n;j+=i){
                t[j]=1;
            }
        }
    }
}

int main(){
    int n;
    cout<<"podaj liczbe n: ";
    cin>>n;
    bool*t=new bool [n+1];
    for(int i=2;i<=n;i++){
        t[i]=0;
    }
    sito(t,n);
    for(int i=2;i<=n;i++){
        if(!t[i]){
            cout<<i<<" ";
        }
    }
    if(t){
        delete [] t;
        t=0;
    }
    return 0;
}