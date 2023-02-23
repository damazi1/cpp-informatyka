#include <iostream>

using namespace std;
float arytm(int*t,const int n){
    float suma=0;
    for(int i=0;i<n;i++){
        suma+=t[i];
    return suma/n;
    }
}
int main(){
    const int n=7;
    int t[n]={1,2,3,4,5,6,7};
    cout<< arytm(t,n)<<endl;
    return 0;
}