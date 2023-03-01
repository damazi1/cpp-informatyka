#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

long int silniarek(int a){
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

int fib_rek(int n){
    if(n<3){
        return 1;
    }
    return fib_rek(n-2)+fib_rek(n-1);
}
void fib_iter(int n){
    int a=0,b=1;
    for (int i=0;i<n-1;i++){
        b+=a;
        a=b-a;
    }
    cout<<"\n"<<b;
}
int pot_naturalne_iter(int x,int y){
    int z=1;
    while(y>0){
        if(y%2==1){
            z*=x;
        }
        y/=2;
        x*=x;
    }
    return z;
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

int main(){
    int a;
    cout<<"podaj liczbę silni: ";
    cin>>a;
    int n;
    cout<<"\nPodaj liczbę n: ";
    cin>>n;
    cout<<silniarek(a)<<endl<<silniaiter(a)<<endl;
    cout<<n<<" wyraz ciągu ma wartość "<<fib_rek(n);
    fib_iter(n);
    int x,y;
    cout<<"\npodaj liczbę i potęgę: ";
    cin>>x>>y;
    cout<<pot_naturalne_iter(x,y);
    cout<<"\n"<<pot_naturalne_rek(x,y);
    return 0;
}