#include <iostream>

using namespace std;
int main(){
    int n=7;
    int tab[n]={1,115,4,2,6,8,1119};
    int poz=0;
    for(int i=1;i<n;i++){
        if(tab[i]>tab[poz]){
            poz=i;
        }
    }
    cout<<"pozycja maksymalnej liczby od zera to "<<poz<<endl; 
    return 0;
}