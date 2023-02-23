#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

int nwd(int a,int b){
    int nwd;
    while(a!=b){
        if(a>b){
            a-=b;
        }
        else{
            b-=a;
        }
    }
    return a;
}

int main(){
    int a,b;
    cout<<"podaj liczbę a i b: ";
    cin>>a>>b;
    cout<<"największy wspólny dzielnik: "<< nwd(a,b)<<endl;
    return 0;

}