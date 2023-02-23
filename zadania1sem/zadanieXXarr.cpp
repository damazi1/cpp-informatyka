#include <iostream>

using namespace std;
void fill_arr(int*t,int n){
    for(int i=0;i<n;i++){
        t[i]=5+i;
    }
}
int main(){
    int n=10;
    int t[n];
    fill_arr(t,n);
    for(int i=0;i<n;i++){
        cout<<t[i]<<endl;
    }
    return 0;
}