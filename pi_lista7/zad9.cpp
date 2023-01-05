#include <iostream>

using namespace std;
double sr(int*tab,const int n){
    double suma;
    int ile;
    for(int i=0;i<n;i++){
        if(tab[i]%2==0){
            suma+=tab[i];
            ile++;
        }
    }
    return suma/ile;
}
int main(){
    const int n=7;
    int tab[n]={1,3,4,6,1,8,16};
    cout<<sr(tab,n)<<endl;
    return 0;
}