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
    cout<<"Imię : "<<Dane.imie;
    cout<<"\tNazwisko : "<<Dane.nazwisko;
    cout<<"\twiek : "<<2023-Dane.rok_urodzenia;
    cout<<"\tmiejsce zamieszkania : "<<Dane.miejsce_zamieszkania;
    cout<<"\tWojewodztwo : "<<Dane.wojewodztwo;
}

SOsoba wczytaj(SOsoba (*wfun)(const string, const string, const unsigned int, const string, const string)){
    string imie, nazwisko , miejsce_zamieszkania, wojewodztwo;
    unsigned int rok_urodzenia;

    cout << "Podaj imię: ";
    cin>> imie;

    cout << "Podaj nazwisko: ";
    cin>> nazwisko;

    cout << "Podaj rok urodzenia: ";
    cin>> rok_urodzenia;

    cout << "Podaj miejsce zamieszkania: ";
    cin>> miejsce_zamieszkania;

    cout << "Podaj wojewodztwo: ";
    cin>> wojewodztwo;

    return wfun(imie, nazwisko, rok_urodzenia, miejsce_zamieszkania, wojewodztwo);
}

void wczytaj(SOsoba& osoba, void (*wfun)(SOsoba&, const string, const string, const unsigned int, const string, const string)){
    string imie, nazwisko , miejsce_zamieszkania, wojewodztwo;
    unsigned int rok_urodzenia;

    cout << "Podaj imię: ";
    cin>> imie;

    cout << "Podaj nazwisko: ";
    cin>> nazwisko;

    cout << "Podaj rok urodzenia: ";
    cin>> rok_urodzenia;

    cout << "Podaj miejsce zamieszkania: ";
    cin>> miejsce_zamieszkania;

    cout << "Podaj wojewodztwo: ";
    cin>> wojewodztwo;

    wfun(osoba, imie, nazwisko, rok_urodzenia, miejsce_zamieszkania, wojewodztwo);
}

void wczytaj1(SOsoba* osoba, void (*wfun)(SOsoba*, const string, const string, const unsigned int, const string, const string)){
    string imie, nazwisko , miejsce_zamieszkania, wojewodztwo;
    unsigned int rok_urodzenia;

    cout << "Podaj imię: ";
    cin>> imie;

    cout << "Podaj nazwisko: ";
    cin>> nazwisko;

    cout << "Podaj rok urodzenia: ";
    cin>> rok_urodzenia;

    cout << "Podaj miejsce zamieszkania: ";
    cin>> miejsce_zamieszkania;

    cout << "Podaj wojewodztwo: ";
    cin>> wojewodztwo;

    wfun(osoba, imie, nazwisko, rok_urodzenia, miejsce_zamieszkania, wojewodztwo);
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

void selektor(SOsoba osoba){
    if(2023-osoba.rok_urodzenia>=18){
        wypisz(osoba);
    }
    else cout<<"osoba jest niepelnoletnia\n";

}

int main(){

    SOsoba Osoba1=wczytaj(&inicjuj);

    cout <<endl;

    wypisz(Osoba1);

    cout <<endl;

    SOsoba &Os = Osoba1;
    wczytaj(Os, &inicjuj);

    cout <<endl;

    wypisz(Osoba1);

    cout <<endl;

    selektor(Osoba1);

    SOsoba *Os1=&Osoba1;
    wczytaj1(Os1, &inicjuj1);

    cout <<endl;

    wypisz(Osoba1);

    cout <<endl;

    selektor(Osoba1);
    
    
    return 0;
}
