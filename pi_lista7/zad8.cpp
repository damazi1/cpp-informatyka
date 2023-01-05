#include <iostream>

using namespace std;
double sr(int *tab,const int n){
    double suma;
    for (int i=0;i<n;i++){
        suma+=tab[i];
    }
    return suma/n;
}
int main(){
    const int n=7;
    int tab[n]={1,5,10,2,3,4,1};
    cout<<sr(tab,n)<<endl;
    return 0;
}