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

SOsoba utworz(const string imie,const string nazwisko,const unsigned int rok, const string miasto, const string wojewodztwo){
    SOsoba Dane;
    
    Dane.imie=imie;
    Dane.nazwisko=nazwisko;
    Dane.rok_urodzenia=rok;
    Dane.miejsce_zamieszkania=miasto;
    Dane.wojewodztwo=wojewodztwo;

    return Dane;
}

void utworz1(SOsoba& Dane,const string imie,const string nazwisko,const unsigned int rok, const string miasto, const string wojewodztwo){
    
    Dane.imie=imie;
    Dane.nazwisko=nazwisko;
    Dane.rok_urodzenia=rok;
    Dane.miejsce_zamieszkania=miasto;
    Dane.wojewodztwo=wojewodztwo;

}

void utworz1(SOsoba* Dane,const string imie,const string nazwisko,const unsigned int rok, const string miasto, const string wojewodztwo){
    
    Dane->imie=imie;
    Dane->nazwisko=nazwisko;
    Dane->rok_urodzenia=rok;
    Dane->miejsce_zamieszkania=miasto;
    Dane->wojewodztwo=wojewodztwo;

}

void wypisz (SOsoba Dane){
    cout<<"Imię to: "<<Dane.imie<<endl;
    cout<<"Nazwisko to: "<<Dane.nazwisko<<endl;
    cout<<"rok urodzenia to: "<<Dane.rok_urodzenia<<endl;
    cout<<"miejsce zamieszkania to: "<<Dane.miejsce_zamieszkania<<endl;
    cout<<"Wojewodztwo to: "<<Dane.wojewodztwo<<endl;
}


int main (){

    SOsoba Osoba1=wczytaj(&utworz);

    cout <<endl;

    wypisz(Osoba1);

    cout <<endl;

    SOsoba &Os = Osoba1;
    wczytaj(Os, &utworz1);

    cout <<endl;

    wypisz(Osoba1);

    cout <<endl;

    SOsoba *Os1=&Osoba1;
    wczytaj1(Os1, &utworz1);

    cout <<endl;

    wypisz(Osoba1);

    cout <<endl;

    return 0;
}

