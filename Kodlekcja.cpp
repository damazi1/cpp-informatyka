#include <iostream>

using namespace std;

int main(){
const int n=10;
int T[n]={1,2,3,4,5,8,11,12,15,100};
int l=0;
int s=0;
int i=0;
while(i<n){
    if(i%3==0){
        s+=T[i];
    }
    if(T[i]%2==1){
        l++;
    }
i++;
}
cout << l;
return 0;
}