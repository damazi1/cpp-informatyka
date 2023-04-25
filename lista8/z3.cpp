#include <iostream>
#include <string>
#include <fstream>
    
using namespace std;

struct SOsoba {
    string imie;
    string nazwisko;
    int rok_urodzenia;
    string miejsce_zamieszkania;
    string wojewodztwo;
};

string selektor(SOsoba osoba){
    if(2023-osoba.rok_urodzenia>=18){
        return "Osoba Pełnoletnia\n";
    }
    
    return "Osoba Niepełnoletnia\n";
}

string selektor1(SOsoba* osoba){
    if(2023-osoba->rok_urodzenia>=18){
        return "Osoba Pełnoletnia\n";
    }
    
    return "Osoba Niepełnoletnia\n";
}

ifstream otworzwej(string nazwa){
    ifstream fin;
    fin.open(nazwa);    
    return fin;
}


ofstream otworzwyj(string nazwa){
    ofstream fout;
    fout.open(nazwa , ios::app);    
    return fout;
}

void zamknij(ifstream& fin){
    fin.close();
}

void zamknij(ofstream& fout){
    fout.close();
}

void sprawdz(ifstream& fin){
    if(!fin.good()){
        cerr<<"Wejscie do pliku nie powiodlo sie\n";
        fin.clear();
        fin.close();
        exit(0);
    }
}

void sprawdz(ofstream& fout){
    if(!fout.good()){
        cerr<<"Wejscie do pliku nie powiodlo sie\n";
        fout.clear();
        fout.close();
        exit(0);
    }
}

void uzupelnij(SOsoba& osoba){
    ifstream fin=otworzwej("dane.txt");
    sprawdz(fin);
    if(fin.good()){
        fin>>osoba.imie;
        sprawdz(fin);
        fin>>osoba.nazwisko;
        sprawdz(fin);
        fin>>osoba.rok_urodzenia;
        sprawdz(fin);
        fin>>osoba.miejsce_zamieszkania;
        sprawdz(fin);
        fin>>osoba.wojewodztwo;
    }
    zamknij(fin);
}
SOsoba uzupelnij(){
    SOsoba osoba;
    ifstream fin=otworzwej("dane.txt");
    sprawdz(fin);
    if(fin.good()){
        fin>>osoba.imie;
        sprawdz(fin);
        fin>>osoba.nazwisko;
        sprawdz(fin);
        fin>>osoba.rok_urodzenia;
        sprawdz(fin);
        fin>>osoba.miejsce_zamieszkania;
        sprawdz(fin);
        fin>>osoba.wojewodztwo;
    }
    zamknij(fin);
    return osoba;
}


void uzupelnij1(SOsoba* osoba){
    ifstream fin=otworzwej("dane.txt");
    sprawdz(fin);
    if(fin.good()){
        fin>>osoba->imie;
        sprawdz(fin);
        fin>>osoba->nazwisko;
        sprawdz(fin);
        fin>>osoba->rok_urodzenia;
        sprawdz(fin);
        fin>>osoba->miejsce_zamieszkania;
        sprawdz(fin);
        fin>>osoba->wojewodztwo;
    }
    zamknij(fin);
}


void wypelnij(SOsoba& osoba){
    ofstream fout=otworzwyj("dane_wyj.txt");
    sprawdz(fout);
    if(fout.good()){
        fout<<"Wypełnienie przy pomocy refeerncji na strukture \n";
        sprawdz(fout);
        fout<<selektor(osoba);
        sprawdz(fout);
        fout<<osoba.imie<<'\t';
        sprawdz(fout);
        fout<<osoba.nazwisko<<'\t';
        sprawdz(fout);
        fout<<2023-osoba.rok_urodzenia<<'\t';
        sprawdz(fout);
        fout<<osoba.miejsce_zamieszkania<<'\t';
        sprawdz(fout);
        fout<<osoba.wojewodztwo<<'\t';
        
    }
    zamknij(fout);
}

void wypelnij1(SOsoba* osoba){
    ofstream fout=otworzwyj("dane_wyj.txt");
    sprawdz(fout);
    if(fout.good()){
        fout<<"\nWypełnienie przy pomocy wskaznika na strukture \n";
        sprawdz(fout);
        fout<<selektor1(osoba);
        sprawdz(fout);
        fout<<osoba->imie<<'\t';
        sprawdz(fout);
        fout<<osoba->nazwisko<<'\t';
        sprawdz(fout);
        fout<<2023-osoba->rok_urodzenia<<'\t';
        sprawdz(fout);
        fout<<osoba->miejsce_zamieszkania<<'\t';
        sprawdz(fout);
        fout<<osoba->wojewodztwo<<'\t';
        
    }
    zamknij(fout);
}
void wypelnij2(SOsoba osoba){
    ofstream fout=otworzwyj("dane_wyj.txt");
    sprawdz(fout);
    if(fout.good()){
        fout<<"\nWypełnienie przy zwykłej struktury \n";
        sprawdz(fout);
        fout<<selektor(osoba);
        sprawdz(fout);
        fout<<osoba.imie<<'\t';
        sprawdz(fout);
        fout<<osoba.nazwisko<<'\t';
        sprawdz(fout);
        fout<<2023-osoba.rok_urodzenia<<'\t';
        sprawdz(fout);
        fout<<osoba.miejsce_zamieszkania<<'\t';
        sprawdz(fout);
        fout<<osoba.wojewodztwo<<'\t';
    }
    zamknij(fout);
}

int main(){

    SOsoba osoba;
    SOsoba &os=osoba;
    SOsoba *os1=&osoba;

    uzupelnij(os);
    uzupelnij(osoba);
    uzupelnij1(os1);

    wypelnij(os);
    wypelnij1(os1);
    wypelnij2(osoba);

    return 0;
}