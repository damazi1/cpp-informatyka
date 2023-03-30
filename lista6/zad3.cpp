#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

bool pomoc(string mail){
    size_t n=mail.size(),i=0;
    for(i=0;i<n;i++){
        if(mail[i]=='@')
        {
            return true;
        }
    }
    return false;
}

void selektor(char* plik_wej, ofstream& plik_wyj){
    ifstream fin;
    fin.open(plik_wej);
    string zdanie;
    string slowo;
    while(getline(fin,zdanie)){
        istringstream iss(zdanie);
        while(iss>>slowo){
           if(pomoc(slowo)){
                plik_wyj<<slowo<<";\n";
            } 
        }
    }
    fin.close();
}

int main(int argc,char *argv[]){
    if(argc!=3){
        cerr<<"Podano bledna ilosc argumentow(3)"<<endl;
        cout<<"Poprawny zapis to ./nazwa plik_wejsciowy plik_wyjsciowy"<<endl;
        return 1;
    }

    ofstream fout;
    fout.open(argv[2]);

    selektor(argv[1],fout);

    fout.close();

    return 0;
}