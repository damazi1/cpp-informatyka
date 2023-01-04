#include <iostream>

using namespace std;
void wyp(int*t, const int n){
    for(int i=n-1;i>=0;i--){
        if(i%2==0) {
            t[i]=0;
        }
        else{
            t[i]=2;
        }
    }
}

int main(){
    const int n=8;
    int t[n];
    wyp(t,n);
    for(int i=0;i<n;i++){
        cout<<t[i]<<endl;
    }
    return 0;
}