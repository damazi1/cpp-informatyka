#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

void wypelnij(float *t,const int n,const int pierwsza){
    t[0]=pierwsza;
    for (int i=1;i<n;i++){
        t[i]=t[i-1]+sqrt(float(t[0]));
    }

}
void wypisz(float *t,const int n){
    for (int i=0;i<n;i++){
    cout<<t[i]<<endl;
  }
}
void przesun(float *t,const int n){
    float ostatnia=t[n-1];
    for (int i=n;i>0;i--){
        t[i]=t[i-1];
    }
    t[0]=ostatnia;
}
int main(){
    int n;
    cout<<"podaj liczbę n: ";
    cin>>n;
    int pierwsza;
    cout <<endl<<"podaj liczbę pierwszą: ";
    cin>>pierwsza;
    float*t=new float [n];
    wypelnij(t,n,pierwsza);
    wypisz(t,n);
    cout <<"przesunieta tablica: "<<endl;
    przesun(t,n);
    wypisz(t,n);
    if(t){
        delete[]t;
        t=0;
    }
    return 0;
}