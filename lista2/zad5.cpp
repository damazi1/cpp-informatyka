#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

void wypisz(const int* t,const unsigned int n){
    for (int i=0;i<n;i++){
        cout<<i<<" elemnet tablicy to: "<<t[i]<<endl;
    }
}
int* utworz(const unsigned int n){
    int*t=new int [n];
    return t;
}

void utworz(int*& t,const unsigned int n){
    t=new int [n];
    // cout<<t<<endl;
}
void utworz1(int*t,const unsigned int n){
    t=new int [n];
    cout<<t;
}
void wypelnij(int *t,const unsigned int n){
    for (int i=0;i<n;i++){
        if(i%2==0){
            t[i]=(rand()%20)-25;
        }
        else{
            t[i]=(rand()%20)+5;
        }
    }
}
void usuwanie(int*t,unsigned int &n){
    int x;
    int pom;
    cout<<"podaj element który chcesz usunąć: ";
    cin>>x;
    for (int i=0;i<n;i++){
        if(t[i]==x){
            pom=i;
            break;
        }
    }
    for (int i=pom;i<n;i++){
        t[i]=t[i+1];
    }
    n--;
}
void dodaj(int*t,unsigned int &n){
    int x;
    cout<<"podaj element który chcesz dodać: ";
    cin>>x;
    n++;
    t[n-1]=x;
}

int*suma(const int *t1,const int *t2,const unsigned int n){
    int *t3=new int[n];
    for (int i=0;i<n;i++){
        t3[i]=t1[i]+t2[i];
    }
    return t3;
}
void suma(const int*t1,const int*t2,int*& t3, const unsigned int n){
    for (int i=0;i<n;i++){
        cout<<t1[i]<<"+"<<t2[i];
        t3[i]=t1[i]+t2[i];
        cout<<"="<<t3[i]<<endl;
    }

}
void suma1(const int *t1,const int*t2,int*t3,const unsigned int n){
    for(int i=0;i<n;i++){
        cout<<t1[i]<<"+"<<t2[i];
        t3[i]=t1[i]+t2[i];
        cout<<"="<<t3[i]<<endl;
    }
}
void tabliczka_mnozenia(){
    int tab[99];
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cout<<i*j<<"\t";
        }
        cout<<"\n";
    }
    int a,b;
    cout<<"Podaj 2 liczby z zakresu od <1,10>:  ";
    cin>>a>>b;
    if (a>1|a<10|b>1|b<10){
        cout<<"Odpowiedź to: "<<a*b;
    }
    else{
        cout<<"liczby nie są z zakresu 1-10";
        return;
    }
}

void usun(int *tab){
    if(tab){
        delete []tab;
        tab=0;
    }
}

int main(){
    srand(time(NULL));
    cout<<"podaj wielkośc tablicy: ";
    unsigned int n;
    cin>>n;
    int *t;
    utworz(t,n);
    cout<<"\n";
    cout << endl<<t<<endl;
    wypelnij(t,n);
    wypisz(t,n);
    usuwanie(t,n);
    wypisz(t,n);
    dodaj(t,n);
    wypisz(t,n);

    int *t1,*t2,*t3;    
    utworz(t1,n);
    wypelnij(t1,n);
    utworz(t2,n);
    wypelnij(t2,n);
    utworz(t3,n);
    cout<<suma(t1,t2,n)<<endl;
    suma(t1,t2,t3,n);
    wypisz(t3,n);
    suma1(t1,t2,t3,n);
    wypisz(t3,n);
    tabliczka_mnozenia();
    usun(t);
    usun(t1);
    usun(t2);
    usun(t3);
}