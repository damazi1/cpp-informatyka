#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

unsigned int *losowanie(const unsigned int n,unsigned int &a,unsigned int &b){
    cout<<"Podaj liczby do zakresu a i b <a,b>: ";
    cin>>a>>b;
    while(b-a<6){
        cout<<"podano za maly zakres, podaj nowy <a , b>: ";
        cin>>a>>b;
    }
    unsigned int *tab=new unsigned int [n];
    for(unsigned int i=0;i<n;i++){
        tab[i]=rand()%b+a;
         for(unsigned int j=0;j<i;j++){
            if(tab[i]==tab[j]){
                i=j-1;
                break;
            }
         }
    }
    return tab;
}

unsigned int *liczby_u(const unsigned int n,const unsigned int a,const unsigned int b){
    unsigned int *tab=new unsigned int [n];
    cout<<"Podaj Twoje 6 liczb z zakresu <"<<a<<" , "<<b<<">. \n";
    for(unsigned int i=0;i<n;i++){
        cout<<"Podaj liczbę "<< i+1<<" : ";
        cin>>tab[i];
            while (tab[i]<a||tab[i]>b){
                cout<<"Podales bledna liczbe poprawny zakres to <"<<a<<" , "<<b<<">\n Liczba ktora podales to : "<<tab[i]<<"\n Podaj poprawna liczbe : ";
                cin>>tab[i];
            }
        for(unsigned int j=0;j<i;j++){            
            while (tab[i]==tab[j]){
                cout<<"Podales ta sama liczbe. Poprawny zakres to <"<<a<<" , "<<b<<">\n Liczba ktora podales to : "<<tab[i]<<"\n Podaj nowa liczbe : ";
                cin>>tab[i];
                j=0;
            }
        } 
    }
    return tab;
}

bool czywygral(unsigned int *tab1,unsigned int *tab2,int &liczba_trafien,const unsigned int n){
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<=i;j++){
            if(tab1[i]==tab2[j]){
                liczba_trafien++;
            }
        }
    }
    if(liczba_trafien>3){
        return 1;   
    }
    return 0;
}

void usun(unsigned int *tab){
    if (tab){
        delete [] tab;
        tab=nullptr;
    }
}

int main (int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podana wartosc argumentow jest bledna (1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa"<<endl;
        return 1;
    }
    srand(time(NULL));
    unsigned int a,b,n=6;
    unsigned int * los=losowanie(n,a,b);

    for(unsigned int i=0;i<n;i++){
        cout<<los[i]<<endl;
    } 
    unsigned int *liczby=liczby_u(n,a,b);

    for(unsigned int i=0;i<n;i++){
            cout<<liczby[i]<<endl;
        }
        
    int ileliczb=0;
    bool wygrana=czywygral(los,liczby,ileliczb,n);
    cout<<"Trafiles "<<ileliczb<<" liczb.\n";
    if(wygrana){
        if(ileliczb==4)cout<<"Wygrales 10 zl"<<endl;
        if(ileliczb==5)cout<<"Wygrales 100 zl"<<endl;
        if(ileliczb==6)cout<<"Wygrales 1000 zl"<<endl;
    }
    else{
        cout<<"Sprobuj jeszcze raz :( "<<endl;
    }

    usun(los);
    usun(liczby);
    return 0;
}