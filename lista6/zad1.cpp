#include <iostream>
#include <cstring>

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

bool sprawdz(int (*fun)(int a, int b),int a,int b){
    if(fun(a,b)>=0)return true;
    return false;
}

int main(int argc,char*argv[]){
    if(argc!=3){
        cerr<<"Podano bledna ilosc argumentow (3)"<<endl;
        cout<<"Poprawny zapis to ./nazwa liczba a, liczba b."<<endl;
        return 1;
    }
    size_t a=atoi(argv[1]),b=atoi(argv[2]);

    if(sprawdz(suma,a,b)){
        cout << "Suma jest wieksza lub rowna 0" << endl;
    }
    else{
        cout << "Suma jest mniejsza od 0" << endl;
    }
    
    if(sprawdz(roznica, a, b))
        cout << "Roznica jest wieksza lub rowna 0" << endl;
    else
        cout << "Roznica jest mniejsza od 0" << endl;
    if(sprawdz(iloczyn, a, b))
        cout << "Iloczyn jest wiekszy lub rowna 0" << endl;
    else
        cout << "Iloczyn jest mniejszy od 0" << endl;
    if(sprawdz(iloraz, a, b))
        cout << "Iloraz jest wiekszy lub rowna 0" << endl;
    else
        cout << "Iloraz jest mniejszy od 0" << endl;
        
    return 0;
}