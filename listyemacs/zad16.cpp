#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void wypisz(int **tab,const unsigned int n,const unsigned int m){
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void wypisz(int *tab,const unsigned int m){
    for (unsigned int i=0;i<m;i++){
        cout<<tab[i]<<"\t";
    }
}

int ** utworz(const unsigned int n,const unsigned int m){
    int **tab=new int *[n];
    for(unsigned int i=0;i<n;i++){
        tab[i]=new int [m]; 
    }
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            tab[i][j]=0;
        }
    }

    return tab;
}

void utworz(int **&tab,const unsigned int n, const unsigned int m){
    tab=new int *[n];
    for(unsigned int i=0;i<n;i++){
        tab[i]=new int [m];
    }
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            tab[i][j]=0;
        }
    }
}

void utworz1(int **tab,const unsigned int n,const unsigned int m){
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            tab[i][j]=0;
        }
    }
}
int *utworz1(const unsigned int m){
    int *tab=new int [m];
    for(unsigned int i=0;i<m;i++){
        tab[i]=0;
    }
    return tab;
}

void usun(int ** tab,const unsigned int n){
    if(tab){
        for(unsigned int i=0;i<n;i++){
            delete [] tab[i];
            tab[i]=nullptr;
        }
        delete []tab;
        tab=nullptr;
    }
}

void wypelnij(int **tab,const unsigned int n,const unsigned int m){
    int a,b;
    cout<<"Podaj zakres liczbowy w tablicy od <a ..b> :";
    cin>>a>>b;
    while (a>b){
        cout<<"liczba a musi byc wieksza od liczby b\nPodaj liczby jeszcze raz: ";
        cin>>a>>b;
    }
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            tab[i][j]=rand()%(b-a)+a;
        }
    }
}

void suma(int **tab1,int **tab2,int **tab3,const unsigned int n,const unsigned int m){
    cout<<"Wynik dodawania wynosi: \n";
    if(n!=m)return;
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            tab3[i][j]=tab1[i][j]+tab2[i][j];
        }
    }
}

void roznica(int **tab1,int **tab2,int **tab3,const unsigned int n,const unsigned int m){
    cout<<"Wynik odejmowania wynosi: \n";
    if(n!=m)return;
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            tab3[i][j]=tab1[i][j]-tab2[i][j];
        }
    }
}

void iloczyn(int**tab1,int**tab2,int**tab3,const unsigned int n,const unsigned int m){
    cout<<"Wynik mnozenia wynosi: \n";
    if(n!=m)return;
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            for(unsigned int k=0;k<n;k++)
                tab3[i][j]+=tab1[i][k]*tab2[k][j];
        }
    }
}

int **transponowanie(int **tab,const unsigned int n,const unsigned int m){
    int**tab5;
    utworz(tab5,m,n);
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            tab5[j][i]=tab[i][j];
        }
    }
    return tab5;
}

void usun(int*tab){
    if(tab){
        delete []tab;
        tab=nullptr;
    }
}

void tabliczka(){
    unsigned int a,b;
    cout<<"Podaj wartosci tabliczki mnozenia (<1 ..a> oraz <1 ..b>): ";
    cin>>a>>b;
    for(unsigned int i=1;i<=a;i++){
        for(unsigned int j=1;j<=b;j++){
            cout<<i*j<<"\t";
        }
        cout<<endl;
    }
}

int main(int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podano bledna ilosc argumentow(1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa"<<endl;
        return 1;
    }
    srand(time(NULL));
    unsigned int n,m;
    cout<<"Podaj wielkosc tablicy wielowymiarowej (n , m): ";
    cin>>n>>m;
    
    int**tab1=utworz(n,m);  //Tworzenie tablicy Dwuwymiarowej
    wypisz(tab1,n,m);       //Przy pomocy funkcji int**fun()

    cout<<endl;

    int**tab2;
    utworz(tab2,n,m);       //Tworzenie tablicy Dwuwymiarowej
    wypisz(tab2,n,m);       //Przy pomocy void fun(int**&)

    cout<<endl;

    int **tab3=new int*[n];
    for(unsigned int i=0;i<n;i++){
        tab3[i]=new int [m];
    }
    utworz1(tab3,n,m);      //Tworzenie tablicy Dwuwymiarowej
    wypisz(tab3,n,m);       //Przy pomocy void fun(int**)

    cout<<endl;

    int*tab4=utworz1(m);    //Tworzenie tablicy jednowymiarowej
    wypisz(tab4,m);         //przy pomocy funkcji int *fun()

    cout<<endl;

    wypelnij(tab1,n,m);     //Wypelnianie Tablicy wartosciami Pseudolosowymi
    wypisz(tab1,n,m);       //Oraz wypisywanie wypelnionej tabeli

    cout<<endl;

    wypelnij(tab2,n,m);     //Wypelnianie Tablicy wartosciami Pseudolosowymi
    wypisz(tab2,n,m);

    cout<<endl;

    suma(tab1,tab2,tab3,n,m);       //dodawanie macierzy
    wypisz(tab3,n,m);

    cout<<endl;

    utworz1(tab3,n,m);              //odejmowanie macierzy
    roznica(tab1,tab2,tab3,n,m);
    wypisz(tab3,n,m);

    cout<<endl;

    utworz1(tab3,n,m);              //mnozenie macierzy
    iloczyn(tab1,tab2,tab3,n,m);
    wypisz(tab3,n,m);

    cout<<endl;

    int **tab5=transponowanie(tab1,n,m);        //Transponowanie macierzy
    
    cout<<"Macierz do Transponowania: "<<endl;
    wypisz(tab1,n,m);
    cout<<"\nMacierz Transponowana: "<<endl;
    wypisz(tab5,m,n);

    usun(tab1,n);           //usuwanie tablic
    usun(tab2,n);
    usun(tab3,n);
    usun(tab4);
    usun(tab5,m);

    tabliczka();

    return 0;
}