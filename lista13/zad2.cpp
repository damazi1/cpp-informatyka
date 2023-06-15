#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
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

bool czy_cyfra(char znak){
	return znak >= '0' && znak <= '9';
}
bool czy_oper(char znak){
	return znak == '+' || znak == '-' || znak == '*' || znak == '/'; 
}

int str_to_int(string a, int &poz) 
{
	int liczba = 0;
	while(poz < a.size() && czy_cyfra(a[poz]))
	{
		//schemat Hornera
		liczba = liczba * 10 + a[poz] - '0';
		++poz;
	}
	--poz;
	return liczba;
}

int obliczRPN(const char* wyrazenie){
    SStos stos;
    int n=strlen(wyrazenie);
    zainicjalizuj(stos,n);
    int wartosc=0;
    int a,b,temp=0;
    for (int i=0;i<n;i++){
        if(czy_cyfra(wyrazenie[i])){
            stos.indeks++;
            dodaj(stos,str_to_int(wyrazenie,i));
        }
        else{
            if(czy_oper(wyrazenie[i])){
                if(sizeof(stos.dane)<2){
                    cerr<<"Niepoprawna ilosć wyrażen";
                    return 1;
                }
                a=stos.dane[stos.indeks];
                usun(stos,temp);
                b=stos.dane[stos.indeks];
                usun(stos,temp);
                dodaj(stos,dzialanie(a,b,wyrazenie[i]));
            }
        }
    }
    wartosc=stos.dane[stos.indeks];
    return wartosc;
}

int main()
{
    cout<<obliczRPN("47-")<<endl;
    return 0;
}