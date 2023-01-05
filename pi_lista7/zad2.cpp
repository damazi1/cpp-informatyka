#include <iostream>

using namespace std;
int fibn(int *tab,const int n){
    int niepa;
    for(int i=0;i<n;i++){
        if(tab[i]%2!=0){
            niepa++;
        }
    }
    return niepa;
}
int main(){
    const int n=7;
    int tab[n]={1,1,2,3,5,8,13};
    cout<<fibn(tab,n)<<endl;
    return 0;
}