#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

void losowanie(int *t){
    cout<<"wylosowane liczby to:\t";
    for (int i=0;i<6;i++){
        t[i]=(rand()%49)+1;
    cout <<t[i]<<"\t";
    }
}

int sprawdz(int *t){
    int liczba=0;
    int tablica[5];
    for (int i=0;i<6;i++){
        cout<<"podaj liczbę nr "<<i+1<<":  ";
        cin>>tablica[i];
    }
    for (int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(tablica[i]==t[j]){
                liczba++;
            }
        }
    }
    if (liczba==4){
        cout<<"Wygrales 100 zl  ";
        return liczba;
    }
    else if (liczba==5){
        cout<<"Wygrales 10000 zl  ";
        return liczba;
    }
    else if (liczba==6){
        cout<<"Wygrales 100000000 zl  ";
        return liczba;
    }
    else {
    cout<<"Nic nie wygrałeś ;(  ";
    return liczba;
    }
    }

int main(){
    srand(time(NULL));
    int *tab=new int [5];
    losowanie(tab);
    cout<<"\n"<<sprawdz(tab)<<" Poprawnych odpowiedzi";
    if (tab){
        delete[]tab;
        tab=0;
    }
    return 0;
}