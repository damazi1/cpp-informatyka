#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

int *totolotek(){
    int a,b;
    cout<<"Podaj zakres liczb: <a,b>";
    cin>>a>>b;
    int *tab=new int [5];
    for(int i=0;i<5;i++){
        tab[i]=rand()%b+a;
        while(tab[i]==tab[i-1]|tab[i]==tab[i-2]|tab[i]==tab[i-3]|tab[i]==tab[i-4]|tab[i]==tab[i-5]){
            tab[i]=rand()%b+a;
        }
        cout<<tab[i]<<"\t";
    }
    return tab;
}
int *liczbyu(){
    int *tab=new int [5];
    cout<<"Podaj swoje liczby: ";
    for(int i=0;i<5;i++){
        cin>>tab[i];
    }
    return tab;
}
bool czywygral(int *tab1,int*tab2){
    int liczba=0;
    for(int i=0;i<5;i++){
        if(tab2[i]==tab1[0]|tab2[i]==tab1[1]|tab2[i]==tab1[2]|tab2[i]==tab1[3]|tab2[i]==tab1[4]){
            liczba++;
        }
    }
    if (liczba==5){
        cout<<"\t\twygrales glowna nagrode !!!JACKPOT!!!\t\t";
        return 1;
    }
    if (liczba==4){
        cout<<"\t\twygrales 4 liczby. średnia nagroda !\t\t";
        return 1;
    }
    if (liczba==3){
        cout<<"\t\twygrales 3 liczby. Mała nagroda\t\t";
        return 1;
    }
    else{
        cout<<"Przegrałeś ... Trafiłeś "<<liczba<<" razy\t\t";
        return 0;
    }
}
int main(){
    srand(time(NULL));
    czywygral(totolotek(),liczbyu());
    return 0;
}