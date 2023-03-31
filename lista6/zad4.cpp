#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

int pomoc (string zdanie){
    int ile=0;
    string wyraz;
    size_t n=zdanie.size();
    size_t pos=0;
    for (size_t i=0;i<n;i++){
        size_t znajdz=zdanie.find("ch",pos);
        if(znajdz!=string::npos){
            pos=znajdz+1;
            ile++;
        }
    }
    return ile;
}

int zlicz (char *filein){
    int ile=0;
    ifstream fin;
    fin.open(filein);
    string zdanie;
    while(getline(fin,zdanie)){
        ile+=pomoc(zdanie);
    }
    return ile;
}

int filtr(char * plik_wej,char *plik_wyj,size_t n=2){
    int ile=0;
    ifstream fin;
    fin.open(plik_wej);
    ofstream fout;
    fout.open(plik_wyj);
    string zdanie;
    string wyraz;
    while(getline(fin,zdanie)){
        istringstream iss(zdanie);
        while(iss >> wyraz){
            if(pomoc(wyraz)==n){
                fout<<wyraz<<";\n";
                ile++;
            }
        }
    }
    fin.close();
    fout.close();
    return ile;
}

int main(int argc,char *argv[]){
    if(argc!=4){
        cerr<<"Podano bledna ilosc argumentow(4)"<<endl;
        cout<<"Poprawny zapis to ./nazwa plik_wej plik_wyj liczbach"<<endl;
        return 1;
    }

    size_t n=atoi(argv[3]);

    cout<<"ch wystepuje: "<<zlicz(argv[1])<<" razy."<<endl;

    cout<<"Istnieje "<<filtr(argv[1],argv[2],n)<<" wyrazow gdzie ch wystepuje "<<n<<" razy."<<endl;

    return 0;
}