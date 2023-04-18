#include <iostream>
#include <string>


using namespace std;

struct SOsoba {
    string imie;
    string nazwisko;
    int rok_urodzenia;
    string miejsce_zamieszkania;
    string wojewodztwo;
};

void wypisz (SOsoba Dane){
    cout<<"Imię to: "<<Dane.imie<<endl;
    cout<<"Nazwisko to: "<<Dane.nazwisko<<endl;
    cout<<"rok urodzenia to: "<<Dane.rok_urodzenia<<endl;
    cout<<"miejsce zamieszkania to: "<<Dane.miejsce_zamieszkania<<endl;
    cout<<"Wojewodztwo to: "<<Dane.wojewodztwo<<endl;
}

SOsoba inicjuj (const string imie,const string nazwisko,const unsigned int rok, const string miasto, const string wojewodztwo){
    SOsoba Dane;
    
    Dane.imie=imie;
    Dane.nazwisko=nazwisko;
    Dane.rok_urodzenia=rok;
    Dane.miejsce_zamieszkania=miasto;
    Dane.wojewodztwo=wojewodztwo;

    return Dane;
}

void inicjuj (SOsoba& osoba, const string imie,const string nazwisko,const unsigned int rok, const string miasto, const string wojewodztwo){
    osoba.imie=imie;
    osoba.nazwisko=nazwisko;
    osoba.rok_urodzenia=rok;
    osoba.miejsce_zamieszkania=miasto;
    osoba.wojewodztwo=wojewodztwo;
}

void inicjuj1 (SOsoba* osoba, const string imie,const string nazwisko,const unsigned int rok, const string miasto, const string wojewodztwo){
    osoba->imie=imie;
    osoba->nazwisko=nazwisko;
    osoba->rok_urodzenia=rok;
    osoba->miejsce_zamieszkania=miasto;
    osoba->wojewodztwo=wojewodztwo;
}

int main(){

    SOsoba Osoba1=inicjuj("Dawid","Ziora",2002,"Czestochowa","Slaskie");

    SOsoba Osoba2;
    SOsoba &Os=Osoba2;

    inicjuj(Os,"Agnieszka","Pala",1999,"lodz","lodzkie");
    
    SOsoba Osoba3;
    SOsoba *Os1=&Osoba3;
    inicjuj1(Os1,"Kacper","Sztok",2012,"Myszkow","Slaskie"); 

    wypisz(Osoba1);
    cout<<endl;
    wypisz(Osoba2);
    cout<<endl;
    wypisz(Osoba3);
    cout<<endl;

    return 0;
}