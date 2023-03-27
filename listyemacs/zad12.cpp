#include <iostream>

using namespace std;


int main(int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podano bledna ilosc argumentow(1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa\n";
        return 1;
    }
    int a,b;
    cout<<"Podaj 2 liczby do wyznaczenia wspolnego dzielnika: ";
    cin>>a>>b;
    while(a!=b){
        if(a>b){
            a-=b;
            }
        else{
            b-=a;
        }
    }
    cout<<"Najwiekszy wspolny dzielnik z twoich liczb to: "<<a<<endl;

    return 0;
}