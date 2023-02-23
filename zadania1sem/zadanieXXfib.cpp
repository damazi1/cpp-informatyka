#include <iostream>

using namespace std;

int count_fib(int*t,const int n){
    int count=0;
    for (int i=0;i<n;i++){
        if(t[i]%2!=0)
        count++;
    }
    return count;
}
int main(){
    const int n=7;
    int t[n]={1,1,2,3,5,8,13};
    cout<<count_fib(t,n)<<endl;
    return 0;
}