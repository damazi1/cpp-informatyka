#include <iostream>

using namespace std;

//Totolotek dla kilku kuponów !!

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


unsigned int **liczby_u(const unsigned int n,unsigned int &kupony,const unsigned int a,const unsigned int b){
    cout<<"Podaj ilosc kuponow ktore chcesz zakupic :";
    cin>>kupony;
    if(kupony<1){
        cout<<"Podano za malo kuponow. Podaj odpowiednia ilosc (kupony>0): ";
        cin>>kupony;
    }
    unsigned int **tab=new unsigned int *[kupony];
    for(unsigned int i=0;i<kupony;i++){
        tab[i]=new unsigned int [n];
    }
    for(unsigned int i=0;i<kupony;i++){
        cout<<"\nKupon nr "<<i+1<<". \n"<<"Podaj Twoje 6 liczb z zakresu <"<<a<<" , "<<b<<">. \n";
        for(unsigned int j=0;j<n;j++){
            cout<<"Podaj liczbe "<<j+1<<". ";
            cin>>tab[i][j];
            while (tab[i][j]<a||tab[i][j]>b){
                cout<<"Podales bledna liczbe poprawny zakres to <"<<a<<" , "<<b<<">\n Liczba ktora podales to : "<<tab[i][j]<<"\n Podaj poprawna liczbe : ";
                cin>>tab[i][j];    
            }
            for(unsigned int s=0;s<j;s++){
                while (tab[i][j]==tab[i][s]){
                    cout<<"Podales ta sama liczbe. Poprawny zakres to <"<<a<<" , "<<b<<">\n Liczba ktora podales to : "<<tab[i][j]<<"\n Podaj nowa liczbe : ";
                    cin>>tab[i][j];
                    s=0;
                }
            }
        } 
    }
    return tab;
}

bool sprawdz(unsigned int *tab,unsigned  int**tab1,const unsigned int n,const unsigned int m,unsigned int &w4,unsigned int &w5,unsigned int &w6){
    int liczba=0;
    for(unsigned int i=0;i<m;i++){
        liczba=0;
        for(unsigned int j=0;j<n;j++){
            for(unsigned int k=0;k<n;k++){
                if(tab[j]==tab1[i][k]){
                    liczba++;
                }
            }
        }
        if(liczba==4)w4++;
        if(liczba==5)w5++;
        if(liczba==6)w6++;
    }
    if(w4+w5+w6!=0){
        cout<<"Wygrales "<<w4+w5+w6 << " razy."<<endl;
        return 1;
    }
    return 0;
}


void usun(unsigned int **tab,const unsigned int n){
    if(tab){
        for(unsigned int i=0;i<n;i++){
            delete [] tab[i];
            tab[i]=nullptr;
        }
        delete []tab;
        tab=nullptr;
    }
}

void usun(unsigned int *tab){
    if(tab){
        delete [] tab;
        tab=nullptr;
    }
}



int main(int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podana bledna ilosc argumentow(1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa"<<endl;
        return 1;
    }
    unsigned int n=6,m,a,b,w4=0,w5=0,w6=0;
    unsigned int *tab=losowanie(n,a,b);

 
    for(unsigned int i=0;i<n;i++){
        cout<<tab[i]<<endl;
    }   

    unsigned int **liczby=liczby_u(n,m,a,b);

    bool wygrana=sprawdz(tab,liczby,n,m,w4,w5,w6);

    if(wygrana){
        if(w4){
            cout<<"wygrales 100zl "<<w4<<" razy."<<endl;
        }
        if(w5){
            cout<<"wygrales 1000zl "<<w5<<" razy"<<endl;
        }
        if(w6){
            cout<<"wygrales 10000zl "<<w6<<" razy"<<endl;
        }
    }
    else{
        cout<<"Nic nie wygrales :(\n sprobuj jeszcze raz... \n";
    }

    usun(tab);
    usun(liczby,m);
    return 0;
}