#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

void wypisz(int**tab,const unsigned int n,const unsigned int m){
    for (unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int **utworz(const unsigned int n,const unsigned int m){
    int **tab=new int *[n];
    for (unsigned int i=0;i<n;i++){
        tab[i]=new int[m];
    }
    return tab;
}

void utworz(int**& tab,const unsigned int n,const unsigned int m){
    tab=new int *[n];
    for(unsigned int i=0;i<n;i++){
        tab[i]=new int[m];
    }
}
void utworz1(int**tab,const unsigned int n,const unsigned int m){
    for (unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            tab[i][j]=0;
        }
    }
}
int * utworz1(const unsigned int m){
    int *tab=new int [m];
    for (unsigned int i=0;i<m;i++){
            tab[i]=0;
    }
    return tab;
}
void usun(int**tab,const unsigned int n,const unsigned int m){
    for (unsigned int i=0;i<n;i++){
            delete [] tab[i];
        }
        delete []tab;
}
void wypelnij(int**tab,const unsigned int n,const unsigned int m){
        for (unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            tab[i][j]=rand()%10;
        }
    }
}
int **suma(int**tab1,int**tab2,const unsigned int n,const unsigned int m){
    int **tabc;
    utworz(tabc,n,m);
    for (unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            tabc[i][j]=tab1[i][j]+tab2[i][j];
        }
    }
    return tabc;
}
int **roznica(int**tab1,int**tab2,const unsigned int n,const unsigned int m){
    int **tabc;
    utworz(tabc,n,m);
    for (unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            tabc[i][j]=tab1[i][j]-tab2[i][j];
        }
    }
    return tabc;
}
int **iloczyn(int**tab1,int**tab2,const unsigned int n,const unsigned int m,const unsigned int p,const unsigned int r){
int **tabc;
    if(m==p){
    utworz(tabc,n,r);
    for (unsigned int i=0;i<n;i++){
        for(unsigned int s=0;s<r;s++){
            for(unsigned int j=0;j<p;j++){
               tabc[i][s]+=tab1[i][j]*tab2[j][s];
            }
        }
    }
    return tabc;
    }
    else{
        return 0;
    }
}
int **transpose(int **tab,const unsigned int n,const unsigned int m){
    int **tabt;
    utworz(tabt,m,n);
    for(unsigned int i=0;i<n;i++){
        for (unsigned int j=0;j<m;j++){
            tabt[j][i]=tab[i][j];
        }
    }
    return tabt;
}
void tabliczka(){
    int a,b;
    cout<<"podaj Liczby z których chcesz uzyskac tabliczke mnozenia a i b: ";
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            cout<<i*j<<"\t";
        }
        cout<<"\n";
    }
}

int main(){
    srand(time(NULL));
    int n=0,m=0;
    cout<<"Podaj wielkość tablicy (X na Y): ";
    cin>>n>>m;
    int **tab; 
    int p=0,r=0;
    cout<<"Podaj wielkość tablicy nr 2 {potrzebne do mnozenia macierzy} (X na Y): ";
    cin>>p>>r;
    int **tab1;
    utworz(n,m);
    cout<<"1. \n";
    wypisz(utworz(n,m),n,m); // Tworzenie pustej macierzy (1 wyświetlana rzecz)
    cout<<endl<<"2.\n";
    utworz(tab,n,m);
    utworz1(tab,n,m); // Zerowanie Macierzy
    wypelnij(tab,n,m); // Wypełnianie macierzy losowymi liczbami z zakresu <0,9> (2 wyświetlana rzecz)
    wypisz(tab,n,m); 
    cout<<endl<<"3.\n";
    wypisz(suma(tab,tab,n,m),n,m); // Dodawanie macierzy (3 wyświetlana rzecz)
    cout<<endl<<"4.\n";
    wypisz(roznica(tab,tab,n,m),n,m); // Odejmowanie macierzy (4 wyświetlana rzecz){W tym przypadku akurat odejmujemy od siebie identyczne macierze dlatego się zeruje}
    cout<<endl<<"5.\n";
    utworz(tab1,p,r); 
    wypelnij(tab1,p,r); // Tworzenie macierzy do mnożenia 
    wypisz(tab1,p,r); // Wyświetlanie nowo utworzonej macieży (5 wyświetlana rzecz)
    cout<<endl<<"6.\n";
    wypisz(iloczyn(tab,tab1,n,m,p,r),n,r); // Wyświetlanie wyniku mnożenia (6 wyświetlana rzecz)
    cout<<endl<<"7.\n";
    wypisz(transpose(tab,n,m),m,n); //Wyświetla macierz transponowaną (7 wyświetlana rzecz)
    cout<<endl;
    usun(tab,n,m);
    usun(tab1,p,r); // Usuwa tabele
    cout<<"8.\n";
    tabliczka(); // Wyświetla tabliczkę mnożenia z zakresu NxM  N(1,a)xM(1,b)(8 wyświetlana rzecz)

    return 0;
}