#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct SCzas {
    int dzien,miesiac,rok,godzina,minuta,sekunda;
};

void sprawdz(ifstream& fin){
    if(!fin.good()){
        cerr<<"Błąd na strumieniu !!";
        fin.clear();
        fin.close();
        exit(0);
    }
}
ifstream otworz(string plik_wej){
    ifstream fin;
    fin.open(plik_wej);
    return fin;
}
void zamknij(ifstream& fin){
    fin.close();
}

bool wczytaj(SCzas*& daty,int* n, const char* plik_wej){
    string plik_w=plik_wej;
    ifstream fin=otworz(plik_w);
    sprawdz(fin);
    fin >>*n;
    sprawdz(fin);
    if(fin.good()){
        
    }
    zamknij(fin);
    return false;
}

int main(){

    return 0;
}