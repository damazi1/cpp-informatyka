#include <iostream>

using namespace std;
int suma(int *tab,const int n){
    int s;
    for(int i = 0;i<n;i++){
        s+=tab[i];
    }
    return s;
}
int main(){
    const int n=7;
    int tab[n]={1,1,2,3,5,8,13};
    cout<<suma(tab,n)<<endl;
    return 0;
}