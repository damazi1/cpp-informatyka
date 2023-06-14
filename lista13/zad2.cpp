#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct SStos
{
    int *dane;
    int n;
    int indeks;
};

int zainicjalizuj(SStos &s, int n)
{
    if (n < 1)
        return 1;
    s.dane = new int[n];
    s.n = n;
    s.indeks = 0;
    return 0;
}

int dodaj(SStos &s, int v)
{
    s.indeks++;
    if (s.indeks > s.n)
        return 1;
    s.dane[s.indeks] = v;
    return 0;
}

int usun(SStos &s, int &v)
{
    v=s.dane[s.indeks];
    s.dane[s.indeks]=0;
    s.indeks--;
    if(s.indeks<0)return 1;
    return 0;
}

int zniszcz(SStos& s){
    if(s.dane){
        delete [] s.dane;
        s.dane=nullptr;
    }
    s.n=0;
    s.indeks=0;
    return 0;
}

void wyswietl(SStos& s){
    cout<<"Wielkość stosu: "<<s.n<<"\nnajwiększy indeks stosu: "<<s.indeks<<endl;
    for (int i=1;i<=s.indeks;i++){
        cout<<s.dane[i]<<"\t";
    }
}

int dzialanie(int a,int b,char oper){
    int wynik=0;
    switch (oper)
    {
    case '+':
        wynik=a+b;
        return wynik;
        break;
    
    case '-':
        wynik=a-b;
        return wynik;
    case '*':
        wynik=a*b;
        return wynik;
    case '/':
        wynik=a/b;
        return wynik;
    default:
        cerr<<"Podano błędny operator (+,-,*,/)"<<endl;
        break;
    }
    return 0;
}

int obliczRPN(const char* wyrazenie){
    SStos stos;
    string wyr=wyrazenie;
    int n=strlen(wyrazenie);
    zainicjalizuj(stos,n);
    int temp=0;
    for (int i=0;i<n;i++){
        if(wyrazenie[i]>='0' && wyrazenie[i]<='9'){
            stos.indeks++;
            stos.dane[stos.indeks]=(wyrazenie[i]);
        }
        if( wyrazenie[i] == '+' || wyrazenie[i] == '-' || wyrazenie[i] == '*' || wyrazenie[i]== '/'){
            temp=dzialanie(stos.dane[stos.indeks-1],stos.dane[stos.indeks],wyrazenie[i]);
            stos.dane[stos.indeks]=0;
            stos.indeks--;
            stos.dane[stos.indeks]=temp;
        }
    }
    zniszcz(stos);
    return stos.dane[stos.indeks];
}

int main()
{
    obliczRPN("47-");
    return 0;
}