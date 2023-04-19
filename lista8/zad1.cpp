#include <iostream>
#include <string>
#include <sstream>

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

void wypelnij (SOsoba Dane){

}

int main(){

    SOsoba Magda={"Magda","Gajek",2002,"Poraj","Śląskie"};

    SOsoba Twoja;

    cout<<"Podaj imie : "<<endl;
    getline(cin, Twoja.imie);
    cout<<"Podaj nazwisko : "<<endl;
    getline(cin, Twoja.nazwisko);
    cout<<"Podaj rok urodzenia : "<<endl;
    string str;
    getline(cin, str);
    stringstream(str)>>Twoja.rok_urodzenia;
    cout<<"Podaj miejsce zamieszkania : "<<endl;
    getline(cin, Twoja.miejsce_zamieszkania);
    cout<<"Podaj wojewodztwo : "<<endl;
    getline(cin, Twoja.wojewodztwo);

    cout<<"Dane nr 1: "<<endl;

    wypisz(Magda);

    cout<<"Dane nr 2: "<<endl;

    wypisz(Twoja);

    return 0;
}