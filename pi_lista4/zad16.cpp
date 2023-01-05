#include <iostream>

using namespace std;
int main(){
    int n=7;
    int tab[n]={2,7,3,3,5,4,1};
    int lider=tab[0];
    int licz;
    for (int i=0;i<n;i++){
        if (licz==0){
            lider=tab[i];
        }
        if(lider==tab[i]){
            licz++;
        }
        else{
            licz--;
        }
    }
    if (licz>=1){
        cout<<"lider to "<<lider<<endl;
    }
    else{
        cout<<"brak lidera"<<endl;
    }
    return 0;
}