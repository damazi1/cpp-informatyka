#include <iostream>

using namespace std;
int max(int *tab,const int n){
    int max=tab[0];
    for (int i=0;i<n;i++){
        if(max<tab[i]){
            max=tab[i];
        }
    }
    return max;
}
int main(){
    const int n=7;
    int tab[n]={222,4,115,8,9,2,1};
    cout<<max(tab,n)<<endl;
    return 0;
}