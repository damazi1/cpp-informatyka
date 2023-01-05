#include <iostream>

using namespace std;

int main(){
    int n=7;
    int tab[n]={2,3,4,5,6,7,9};
    double suma;
    for (int i=0;i<n;i++){
        suma+=tab[i];
    }
    suma=suma/n;
    cout<<suma<<endl;
    return 0;
}