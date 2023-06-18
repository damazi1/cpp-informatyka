#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct SOsoba {
    string imie,znak_ur;
    int rok,liczba;
    SOsoba(){
        imie="";
        znak_ur="";
        rok=0;
        liczba=0;
    }
    ~SOsoba(){
        imie="";
        znak_ur="";
        rok=0;
        liczba=0;
    }

    bool wczytaj(ifstream&);
    bool wypisz(ostream& out=cout);
};

struct SLista{
    string nazwa;
    int liczba_os;
    SOsoba* osoba;

    SLista(){
        nazwa="";
        liczba_os=0;
        osoba=nullptr;
    }
    ~SLista(){
        nazwa="";
        liczba_os=0;
        if(osoba){
            delete [] osoba;
            osoba=nullptr;
        }
    }
    bool wczytaj(ifstream&);
    bool wypisz(ostream& out=cout);
    SOsoba szukaj(const string);
    void podzial(ostream&,ostream&);
    void podzial();
};

int main(int argc,char**argv){
    if(argc!=4){
        cerr<<"Niepoprawna ilosc argumentów"<<endl;
        cout<<"Poprawny zapis to ./nazwa plik_wej plik_wyjM plike_wyjK"<<endl;
        return -1;
    }
    ifstream fin;
    fin.open(argv[1]);
    if(!fin.good()){
        cerr<<"Plik nie został poprawnie otwarty"<<endl;
        fin.clear();
        fin.close();
        return -1;
    }
    ofstream outM,outK;
    outM.open(argv[2]);
    outK.open(argv[3]);
    if(!outM.good()||!outK.good()){
        cerr<<"Błąd podczas otwierania plikow wyjsciowych w funkcji main";
        outM.clear();
        outK.clear();
        return -1;
    }
    SLista lista;
    if(!lista.wczytaj(fin)){
        cerr<<"Błąd podczas wywoływania funkcji wczytaj";
        fin.clear();
        fin.close();
        return 1;
    }
    if(!lista.wypisz()){
        cerr<<"Błąd podczas wywoływania funkcji wypisz";
        fin.clear();
        fin.close();
        return 1;
    }
    SOsoba osoba=lista.szukaj("Waga");
    if(!osoba.wypisz()){
        cerr<<"Błąd podczas wywoływania funkcji wypisz";
        fin.clear();
        fin.close();
        return 1;
    }
    lista.podzial(outM,outK);
    lista.podzial();
    fin.close();
    return 0;
}

bool SOsoba::wczytaj(ifstream& fin){
    if(!fin.good()){
        cerr<<"błąd na strumieniu wejscia w SOsoba wczytaj"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin>>imie;
    if(!fin.good()){
        cerr<<"błąd na strumieniu wejscia w SOsoba wczytaj"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin>>rok;
    if(!fin.good()){
        cerr<<"błąd na strumieniu wejscia w SOsoba wczytaj"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin>>znak_ur;
    if(!fin.good()){
        cerr<<"błąd na strumieniu wejscia w SOsoba wczytaj"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin>>liczba;
    if(!fin.good()){
        cerr<<"błąd na strumieniu wejscia w SOsoba wczytaj"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    return true;
}

bool SOsoba::wypisz(ostream& out){
    if(!out.good()){
        cerr<<"Błąd na strumieniu wyjścia w SOsoba wypisz"<<endl;
        out.clear();
        return false;
    }
    out<<imie<<"\t"<<rok<<'\t'<<znak_ur<<'\t'<<liczba<<endl;
    if(!out.good()){
        cerr<<"Błąd na strumieniu wyjścia w SOsoba wypisz"<<endl;
        out.clear();
        return false;
    }
    return true;
}

bool SLista::wczytaj(ifstream& fin){
    if(!fin.good()){
        cerr<<"Błąd na strumieniu wejścia w SLista wczytaj"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin>>nazwa;
    if(!fin.good()){
        cerr<<"Błąd na strumieniu wejścia w SLista wczytaj"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin>>liczba_os;
    if(!fin.good()){
        cerr<<"Błąd na strumieniu wejścia w SLista wczytaj"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    if(liczba_os==0){
        osoba=nullptr;
        return true;
    }
    if(liczba_os<0){
        cout<<"Niepoprawna ilosc osób"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    else{
        osoba=new SOsoba [liczba_os];
        for (int i=0;i<liczba_os;i++){
            osoba[i].wczytaj(fin);
        }
    }
    return true;
}

bool SLista::wypisz(ostream& out){
    if(!out.good()){
        cerr<<"Błąd na strumieniu wyjścia w SLista wypisz"<<endl;
        out.clear();
        return false;
    }
    out<<nazwa<<'\n'<<liczba_os<<'\n';
    if(!out.good()){
        cerr<<"Błąd na strumieniu wyjścia w SLista wypisz"<<endl;
        out.clear();
        return false;
    }
    for(int i=0;i<liczba_os;i++){
        osoba[i].wypisz(out);
    }
    return true;
}

SOsoba SLista::szukaj(const string src){
    for(int i=0;i<liczba_os;i++){
        if(osoba[i].znak_ur==src)return osoba[i];
    }
    return SOsoba();
}

void SLista::podzial(ostream& outM,ostream& outK){
    if(!outM.good()||!outK.good()){
        cerr<<"Błąd podczas otwierania plikow wyjsciowych w funkcji podzial";
        outM.clear();
        outK.clear();
        return;
    }
    for (int i=0;i<liczba_os;i++){
        int n=osoba[i].imie.size();
        if(osoba[i].imie[n-1]=='a'){
            osoba[i].wypisz(outK);
        }
        else{
            osoba[i].wypisz(outM);
        }
    }
}

void SLista::podzial(){
    for (int i=0;i<liczba_os;i++){
        if(osoba[i].liczba%2==0){
            osoba[i].wypisz();
        }
    }
}