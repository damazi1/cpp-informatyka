#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool zapisz(char* plik_wyj,char* zawartosc, unsigned int ile=10){
    ofstream fout(plik_wyj, ios::app) ;
    if(fout.good()){
        for (unsigned int i=0;i<ile;i++){
            fout<< zawartosc <<endl;
        }
        fout.close();
        return true;
    }
    return false;
}

bool zapisz(ofstream& plik_wyj,char* zawartosc, unsigned int ile=10){
    if(plik_wyj.good()){
        for (unsigned int i=0;i<ile;i++){
            plik_wyj<< zawartosc <<endl;
        }
        plik_wyj.close();
        return true;
    }
    return false;
}

int main(int argc,char*argv[]){
    if(argc!=4){
        cerr<<"Podano bledna ilosc argumentow (4)"<<endl;
        cout<<"Poprawny zapis to ./nazwa nazwa_pliku zawartosc_pliku znaki_nowej_linii"<<endl;
        return 1;
    }

    size_t n=atoi(argv[3]);
    ofstream fout(argv[1], ios::app);
    
    if(!zapisz(argv[1],argv[2],n)){
        cerr<<"Nie udalo sie zapisac do piku!!\n";
        return 2;
    }
    else{
        cout<<"Udalo sie zapisac do pliku \n\n";
    }

    if(!zapisz(fout,argv[2],n)){
        cerr<<"Nie udalo sie zapisac do piku!!\n";
        return 2;
    }
    else{
        cout<<"Udalo sie zapisac do pliku \n";
    }

    return 0;
}