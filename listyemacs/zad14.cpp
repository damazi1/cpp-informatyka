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
    int element,pom=0;
    cout<<"\nPodaj element ktory chcesz usunac(od 1 do " <<n-1<<" )";
    cin>>element;
    for(unsigned int i=0;i<n;i++){
        if(element==tab[i]){
            pom=i;
            break;
        }
    }
    for(unsigned int i=pom;i<n-1;i++){
        tab[i]=tab[i+1];
    }
    n--;
}

void usun(int *tab){
    if(tab){
        delete []tab;
        tab=0;
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

    kasuj(tab,n);
    wypisz(tab,n);


    usun(tab);
    usun(tab1);
    usun(tab2);
    return 0;
}