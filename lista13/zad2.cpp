#include <iostream>
#include <string>

using namespace std;

struct SStos{
    string* dane;
    int n;
    int indeks;
};

int zainicjalizuj(SStos& s, int n){
    s.dane=new string [n];
    s.n=n;
    s.indeks=0;
    return 0;
}

int main(){

    return 0;
}