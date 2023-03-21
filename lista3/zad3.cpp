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
        while(tab[i]==tab[i-1]||tab[i]==tab[i-2]||tab[i]==tab[i-3]||tab[i]==tab[i-4]||tab[i]==tab[i-5]){
            tab[i]=rand()%b+a;
        }
        cout<<tab[i]<<"\t";
    }
    return tab;
}
int **liczbyu(const int kupony){
    int **tab=new int *[5];
    for (int i=0;i<kupony;i++){
        tab[i]=new int[kupony];
    }

    cout<<"Podaj swoje liczby: ";
    for(int i=0;i<kupony;i++){
        cout<<"Podaj liczby swojego "<< i << "Kuponu :";
        for(int j=0;j<5;j++){
            cin>>tab[i][j];
        }
    }
    return tab;
}
void czywygral(int *tab1,int**tab2,const int kupony){
    int liczba=0;
    for(int i=0;i<kupony;i++){
        for(int j=0;j<5;j++){
            if(tab2[i][j]==tab1[0]||tab2[i][j]==tab1[1]||tab2[i][j]==tab1[2]||tab2[i][j]==tab1[3]||tab2[i][j]==tab1[4]){
                liczba++;
            }
        }
    cout<<"Kupon nr "<<i<<"to : \t";
    if (liczba==5){
        cout<<"\t\twygrales glowna nagrode !!!JACKPOT!!!\t\t";
    }
    if (liczba==4){
        cout<<"\t\twygrales 4 liczby. średnia nagroda !\t\t";
    }
    if (liczba==3){
        cout<<"\t\twygrales 3 liczby. Mała nagroda\t\t";
    }
    else{
        cout<<"Przegrałeś ... Trafiłeś "<<liczba<<" razy\t\t";
    }
    liczba=0;
    }
}

int main(){
    srand(time(NULL));
    int kupony=0;
    cout<<"Ile kuponów chcesz kupic: ";
    cin>>kupony;

    czywygral(totolotek(),liczbyu(kupony),kupony);

    return 0;
}