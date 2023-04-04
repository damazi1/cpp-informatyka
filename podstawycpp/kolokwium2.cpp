#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>

using namespace std;

int *utworz(const unsigned int n){
    int *tab=new int [n];
    int a,b;
    cout<<"Podaj wielkosc tablicy od a do b <a, b> :";
    cin>>a>>b;
    for(unsigned int i=0;i<n;i++){
        tab[i]=rand()%(b-a)+a;
    }
    return tab;
}

void wypisz (int *tab,const unsigned int n){
    for (unsigned int i=0;i<n;i++){
        cout<<tab[i]<<"\t";
    }
}

void usun(int* tab){
    if(tab){
        delete [] tab;
        tab=nullptr;
    }
}

void wypisz(ifstream &fin, ofstream &fout){
    if(fin.good()){
        string wyraz,slowo;
        while(getline(fin,wyraz)){
            istringstream iss(wyraz);
            while (iss >> slowo){
                size_t n =slowo.size();
                for(size_t i=0;i<n;i++){
                    if(slowo[i]=='@'){
                        fout<<slowo<<";\n";
                    }
                }
            }
        }
    }
}

int main (int argc, char* argv[]){
    if(argc!=3){
        cerr<<"Podano bledna ilosc argumentow (3)"<<endl;
        cout<<"Poprawny zapis to ./nazwa"<<endl;
        return 1;
    }
    srand(time(NULL));
    unsigned int n;
    cout<<"Podaj Wielkosc tablicy: ";
    cin>>n;

    int *tab=utworz(n);
    wypisz(tab,n);

    usun(tab);

    ifstream fin;
    fin.open(argv[1]);
    ofstream fout;
    fout.open(argv[2]);

    wypisz(fin,fout);

    fin.close();
    fout.close();
    return 0;
}
