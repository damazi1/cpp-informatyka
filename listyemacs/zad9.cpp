#include <iostream>
#include <cmath>
using namespace std;

void miejscazero(int a,int b,int c){
    cout<<"Podaj a,b,c  (ax²+bx+c): ";
    cin>>a>>b>>c;
    int delta=pow(b,2)-4*a*c;
    if (delta<0){
        cout<<"brak rozwiazan";
        return;
    }
    if (delta==0){
        cout<<"Posiada jedno miejsce zerowe: "<<-b/2*a;
    }
    if(delta>0){
        cout<<"Posiada 2 miejsca zerowe, x1= "<<(-b-sqrt(delta))/(2*a)<<" \n oraz x2= "<<-(b/a)-(-b-sqrt(delta))/(2*a)<<endl;
    }
}

int main(int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podano bledna ilosc argumentow(1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa"<<endl;
        return 1;
    }
    int a,b,c;
    miejscazero(a,b,c);
    return 0;
}