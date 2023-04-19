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
    fout.open(nazwa);    
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
    ofstream fout;
    fout.open("dane_wyj.txt",ios::app);

    if(fout.good()){
        fout<<"\nWypełnienie przy pomocy refeerncji na strukture \n";
        fout<<selektor(osoba);
        fout<<osoba.imie<<'\t';
        fout<<osoba.nazwisko<<'\t';
        fout<<2023-osoba.rok_urodzenia<<'\t';
        fout<<osoba.miejsce_zamieszkania<<'\t';
        fout<<osoba.wojewodztwo<<'\t';
        
    }
    fout.close();
}

void wypelnij1(SOsoba* osoba){
    ofstream fout;
    fout.open("dane_wyj.txt",ios::app);

    if(fout.good()){
        fout<<"\nWypełnienie przy pomocy wskaznika na strukture \n";
        fout<<selektor1(osoba);
        fout<<osoba->imie<<'\t';
        fout<<osoba->nazwisko<<'\t';
        fout<<2023-osoba->rok_urodzenia<<'\t';
        fout<<osoba->miejsce_zamieszkania<<'\t';
        fout<<osoba->wojewodztwo<<'\t';
        
    }
    fout.close();
}
void wypelnij2(SOsoba osoba){
    ofstream fout;
    fout.open("dane_wyj.txt",ios::app);

    if(fout.good()){
        fout<<"\nWypełnienie przy zwykłej struktury \n";
        fout<<selektor(osoba);
        fout<<osoba.imie<<'\t';
        fout<<osoba.nazwisko<<'\t';
        fout<<2023-osoba.rok_urodzenia<<'\t';
        fout<<osoba.miejsce_zamieszkania<<'\t';
        fout<<osoba.wojewodztwo<<'\t';
    }
    fout.close();
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