#include <iostream>

using namespace std;

int main(){
    int n=7;
    int tab[n]={6,2,8,5,7,6,9};
    double suma;
    int ile;
    for(int i=0;i<n;i++){
        if(tab[i]%2==0){
            suma+=tab[i];
            ile++;
        }
    }
    suma=suma/ile;
    cout<<suma<<endl;
    return 0;
}