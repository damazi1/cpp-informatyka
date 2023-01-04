#include <iostream>

using namespace std;

int main(){
    int n=7;
    int tab[n]={1,115,4,2,6,8,9};
    int max=tab[0];
    for(int i=1;i<n;i++){
        if(max<tab[i]){
            max=tab[i];
        }
    }
    cout<<max<<endl;
    return 0;
}