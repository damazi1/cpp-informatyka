#include <iostream>
#include <cmath>

using namespace std;

void pobierz(int &a,int &b,int &c){
    cout<<"Podaj boki trojkata a, b, c: ";
    cin>>a>>b>>c;
}
bool sprawdz(const int a,const int b,const int c){
    if(a+b>c){
        if(a+c>b){
            if(b+c>a)return 1;
        }
    }
    return 0;
}

float pole(int &a,int &b, int &c){
    int i=sprawdz(a,b,c);
    if(i==1){
        float p=(a+b+c)/2;
        return sqrt((p*(p-a)*(p-b)*(p-c)));
    }
    return 0;
}

int main(int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podano bledna ilosc argumentow(1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa"<<endl;
        return 1;
    }
    int a,b,c;
    pobierz(a,b,c);
    cout<<"Twoje pole wynosi: "<<pole(a,b,c)<<endl;

    return 0;
}