// ćwiczenia_w_grupie
#include <iostream>

using namespace std;
int suma_fib(int*t,const int n){
    int suma=0;
    for (int i=0;i<n;i++){
        suma+=t[i];
    }
    return suma;
}
int main(){
    const int n=7;
    int t[n]={1,1,2,3,5,8,13};
    int s=suma_fib(t,n);
    cout<<s<<endl;
    return 0;
}
