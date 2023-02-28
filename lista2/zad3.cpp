#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

long int silniarek(int a){
    long int silnia;
    if(a<2){
        return 1;
    }
    return a*silniarek(a-1);
}
long int silniaiter(int a){
    int liczba=a;
    int silnia=1;
    while(liczba>0){
        silnia*=liczba;
        liczba--;
    }
    return silnia;
}

int fib_rek(int a){

}

int main(){
    int a;
    cout<<"podaj liczbę silni: ";
    cin>>a;
    cout<<silniarek(a)<<endl<<silniaiter(a)<<endl;

    return 0;
}