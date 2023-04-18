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


int main(){

    SOsoba Magda;
    SOsoba *wsk = &Magda;
    SOsoba &ref = Magda;

    Magda.imie="Magda";
    wsk->nazwisko="Gajek";
    ref.rok_urodzenia=2002;
    Magda.miejsce_zamieszkania="Poraj";
    ref.wojewodztwo="Slaskie";

    wypisz(Magda);

    return 0;
}