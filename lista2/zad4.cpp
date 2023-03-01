#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
void arg_wartosc(int a,int b){
    int pom=a;
    a=b;
    b=pom;
    cout<<"wartosc a po zamianie: "<<a<<" wartosc b: "<<b<<endl;
}
void arg_referencja(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}
void arg_wskaznik(int *a,int *b){
    int c=*a,d=*b;
    *b=c;
    *a=d;
}
int main(){
    int a=5,b=10;

    cout<<"wartosc a: "<<a<<" wartosc b: "<<b<<endl;
    arg_wartosc(a,b);
    cout<<"wartosc a: "<<a<<" wartosc b: "<<b<<endl;
    arg_referencja(a,b);
    cout<<"wartosc a po zamianie: "<<a<<" wartosc b: "<<b<<endl;
    
    cout<<"wartosc a: "<<a<<" wartosc b: "<<b<<endl;
    arg_wskaznik(&a,&b);
    cout<<"wartosc a po zamianie: "<<a<<" wartosc b: "<<b<<endl;
    
    return 0;
}