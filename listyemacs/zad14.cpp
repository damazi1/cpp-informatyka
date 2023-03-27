#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;


void wypisz(const int *tab,const unsigned int n){
    for(unsigned int i=0;i<n;i++){
        cout<<tab[i]<<"\t";
    }
}

int *utworz(const unsigned int n){
    int *tab=new int [n];
    unsigned int i=0;
    for(;i<n;i++){
        tab[i]=0;
    }
    return tab;
}

void utworz(int*& tab,const unsigned int n){
    tab=new int [n];
    for(unsigned int i=0;i<n;i++){
        tab[i]=0;
    }
}

void utworz1(int* tab,const unsigned int n){
    for(unsigned int i=0;i<n;i++){
        tab[i]=0;
    }
}

void wypelnij(int *tab,const unsigned int n){
    for(unsigned int i=0;i<n;i++){
        if(i%2==0){
            tab[i]=rand()%20-25;
        }
        else{
            tab[i]=rand()%20+5;
        }
    }
}

void kasuj(int *tab,unsigned int &n){
    unsigned int element,pom=0;
    cout<<"\nPodaj element ktory chcesz usunac(od 0 do " <<n-1<<" )";
    cin>>element;
    for(unsigned int i=0;i<n;i++){
        if(element==i){
            pom=i;
            break;
        }
    }
    if(pom==element){
        for(unsigned int i=pom;i<n-1;i++){
            tab[i]=tab[i+1];
        }
        n--;
    }
}

void dodaj(int *tab,unsigned int &n){
    int element;
    cout<<"\nPodaj element ktory chcesz dodac: ";
    cin>>element;
    n++;
    tab[n-1]=element;
}

int *suma(const int* t1,const int* t2,const unsigned int n){
    int *wynik=new int [n];
    for(unsigned int i=0;i<n;i++){
        wynik[i]=t1[i]+t2[i];
    }
    return wynik; 
}

void suma(const int *t1,const int *t2,int *& t3,const unsigned int n){
    t3=new int [n];
    for (unsigned int i=0;i<n;i++){
        t3[i]=t1[i]+t2[i];
    }
}

void suma1(const int *t1,const int *t2,int * t3,const unsigned int n){
    for (unsigned int i=0;i<n;i++){
        t3[i]=t1[i]+t2[i];
    }
}

void usun(int *tab){
    if(tab){
        delete []tab;
        tab=0;
    }
}

void tabliczka_mnozenia(){
    int i=1,j=1;
    for(;i<=10;i++){
        for(j=0;j<=10;j++){
            cout<<i*j<<"\t";
        }
        cout<<"\n";
    }
    int a,b;
    cout<<"\nPodaj 2 Liczby ktore chcesz pomnozyc z zakresu od <1,10>";
    cin>>a>>b;
    if(a>=1&&a<=10&&b>=1&&b<=10){
        cout<<"Twoj wynik wynosi: "<<a*b<<endl;
    }
    else{
        cout<<"Twoje liczby wykraczaja poza zakres \n";
    }
}

int main(int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podano bledna ilosc argumentow(1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa\n";
        return 1;
    }
    srand(time(NULL));
    unsigned int n;
    cout<<"Podaj wielkosc tablicy: ";
    cin>>n;
    int*tab=new int [n];
    int *tab1=utworz(n);
    int *tab2;

    cout<<"Tworzenie tablicy nr 1: \n";
    utworz1(tab,n);
    wypisz(tab,n);

    cout<<"\nTworzenie tablicy nr 2: "<<endl;

    wypisz(tab1,n);

    cout<<"\nTworzenie tablicy nr 3: "<<endl;

    utworz(tab2,n);
    wypisz(tab2,n);

    cout<<"\n Wypelnienie tablicy :\n";
    
    wypelnij(tab,n);
    wypisz (tab,n);

    wypelnij(tab1,n);
    wypelnij(tab2,n);

    kasuj(tab,n);
    wypisz(tab,n);

    dodaj(tab,n);
    wypisz (tab,n);

    int *tab3=suma(tab1,tab2,n);
    cout<<endl;
    wypisz(tab3,n);

    cout<<endl;

    int *tab4;
    suma(tab1,tab2,tab4,n);
    wypisz(tab4,n);

    cout<<endl;

    int *tab5=new int [n];
    suma1(tab1,tab2,tab5,n);
    wypisz(tab5,n);

    usun(tab);
    usun(tab1);
    usun(tab2);
    usun(tab3);
    usun(tab4);
    usun(tab5);

    cout<<endl;
    
    tabliczka_mnozenia();

    return 0;
}