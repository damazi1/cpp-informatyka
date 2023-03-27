#include <iostream>

using namespace std;

int silnia_rek(int a){
    if(a<2){
        return 1;
    }
    return a*silnia_rek(a-1);
}

int silnia_iter(int a){
    int i=1,wynik=1;
    for (;i<=a;i++){
        wynik=wynik*i;
    }
    return wynik;
}

int fib_rek(int n){
    if(n<3){
        return 1;
    }
    return fib_rek(n-2)+fib_rek(n-1);
}

int fib_iter(int n){
    int i=0,a=1,b=1;
    for(;i<n-1;i++){
        a+=b;
        b=a-b;
    }
    return b;
}

int pot_naturalne_rek(int x,int y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        return pot_naturalne_rek(x,y/2)*pot_naturalne_rek(x,y/2);
    }
    return pot_naturalne_rek(x,y/2)*pot_naturalne_rek(x,y/2)*x;
}

int pot_naturalne_iter(int x,int y){
    int wynik=1;
    while(y>0){
        if(y%2==1){
            wynik*=x;
        }
        y/=2;
        x*=x;
    }
    return wynik;
}


int main(int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podano bledna ilosc argumentow(1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa\n";
        return 1;
    }
    // Liczenie silni 

    int a;
    cout <<"Podaj liczbe do silni: ";
    cin>>a;
    
    cout<<"Wartosc twojej silni rekurencyjnie wynosi: "<<silnia_rek(a)<<endl;
    cout<<"Wartosc twojej silni iteracyjnie wynosi: "<<silnia_iter(a)<<endl;

    // Liczenie ciągu Fibbonaciego

    int n;
    cout <<"Podaj liczbe z ciagu Fibbonaciego ktory chcesz znalezc: ";
    cin>>n;

    cout<<"Twoj "<<n<<" wyraz ciagu Fibbbonaciego Rekurencyjnie to: "<<fib_rek(n)<<endl;
    cout<<"Twoj "<<n<<" wyraz ciagu Fibbbonaciego Iteracyjnie to: "<<fib_iter(n)<<endl;

    // Potęgowanie Binarne

    int x,y;
    cout <<"Podaj liczbe oraz potege: ";
    cin>>x>>y;

    cout<<"Liczba "<< x<<" Do potegi "<< y<<" metoda rekurencyjna jest rowna: "<<pot_naturalne_rek(x,y)<<endl;
    cout<<"Liczba "<< x<<" Do potegi "<< y<<" metoda iteracyjna jest rowna: "<<pot_naturalne_iter(x,y)<<endl;

    return 0;
}