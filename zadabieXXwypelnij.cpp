#include <iostream>

using namespace std;
void wypelnij(int*t,const int n){
    for (int i=n-1;i>=0;i--){
        t[i]=i;
    }
}
int main(){
    const int n=7;
    int t[n];
    wypelnij(t,n);
    for (int i=0;i<n;i++){
        cout<<t[i]<<endl;
    }
    return 0;
}