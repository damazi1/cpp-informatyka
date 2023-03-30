#include <iostream>

using namespace std;

int suma(int a,int b){
    return a+b;
}

int roznica(int a,int b){
    return a-b;
}


int iloczyn(int a,int b){
    return a*b;
}


int iloraz(int a,int b){
    return a/b;
}

bool sprawdz(int (*fun)(int a, int b)){
    if(fun(a,b)>=0)return true;
    return false;
}

int main(int argc,char*argv[]){
    if(argc!=3){
        cerr<<"Podano bledna ilosc argumentow (3)"<<endl;
        cout<<"Poprawny zapis to ./nazwa liczba a, liczba b."<<endl;
        return 1;
    }

    if(sprawdz(suma, a, b)){
        cout << "Suma jest wieksza lub rowna 0" << endl;
    }
    else{
        cout << "Suma jest mniejsza od 0" << endl;
    }
    
    return 0;
}