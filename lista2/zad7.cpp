#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

float suma(int a,int b){
    return a+b;
}
float roznica(int a,int b){
    return a-b;
}
float iloczyn(int a,int b){
    return a*b;
}
float iloraz(int a,int b){
    return a/b;
}
float kwadrat(int a){
    return a*a;
}
float szescian(int a){
    return a*a*a;
}

float wartosc_wyrazenia(int x){
    return (10*(szescian(x))+3.1415*(kwadrat(x)))*((x/3)-(1/kwadrat(x)));
}
float obwod(float a,float b,float c){
    if(a+b>c||a+c>b||b+c>a){
        return a+b+c;
    }
    else{
        cout<<"taki trójkąt nie istnieje";
        return false;
    }
}
float pole(float a,float b,float c){
    float polea;
    if(a+b>c||a+c>b||b+c>a){
        polea=obwod(a,b,c)/2;
        return polea;
    }
    else{
        return 0;
    }
}
float poleherona(float a,float b, float c){
    float poleherona;
    if(a+b>c||a+c>b||b+c>a){
        poleherona=sqrt(pole(a,b,c)*(pole(a,b,c)-a)*(pole(a,b,c)-b)*(pole(a,b,c)-c));
        return poleherona;
    }
    else{
        return 0;
    }
}

void menu(){ 
 int wybor=0;
    cout<<"\nWybierz jakie działanie chcesz wykonać \n1.Dodawanie \n2.Odejmowanie\n3.mnozenie\n4.dzielenie\n5.do potegi 2\n6.do potegi 3\n7.obliczenie wartosci wyrazenia: (10*(x*x*x)+3.1415*(x*x))*((x/3)-(1/x*x))\n8.obwod trojkanta\n9.pole trojkonta\n0.Wyjdź ";
    cin>>wybor;
    float a,b,c;
    switch(wybor){
        case 1:
        cout<<"podaj 2 liczby którę chcesz dodać ";
        cin>>a>>b;
        cout<<suma(a,b);
        break;
        case 2:
        cout<<"podaj 2 liczby którę chcesz odjąć ";
        cin>>a>>b;
        cout<<roznica(a,b);
        break;
        case 3: 
        cout<<"podaj 2 liczby którę chcesz pomnożyć ";
        cin>>a>>b;
        cout<<iloczyn(a,b);
         break;
        case 4:
        cout<<"podaj 2 liczby którę chcesz podzielic ";
        cin>>a>>b;
        cout<<iloraz(a,b);
        break;
        case 5:
        cout<<"podaj liczbę którą chcesz podniesc do kwadratu:  ";
        cin>>a;
        cout<<kwadrat(a);
        break;
        case 6:
        cout<<"podaj liczbę którą chcesz podniesc do szescianu:  ";
        cin>>a;
        cout<<szescian(a);
        break;
        case 7:
        cout<<"podaj liczbę dla której chcesz aby zostało roziązane wyrażenie  ";
        cin>>a;
        cout<<wartosc_wyrazenia(a);
        break;   
        case 8:
        cout<<"podaj boki trójkąta: ";
        cin>>a>>b>>c;
        cout<<obwod(a,b,c);
        break;
        case 9:
        cout<<"Podaj boki trójkąta a,b,c: ";
        cin>>a>>b>>c;
        cout<<poleherona(a,b,c);
        break;
        case 0:
        exit(0);
    }
}

int main(){
    bool powtorz=true;
    while(powtorz=true) {  
    menu();
    }
    return 0;
}