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
\
void inicjuj (SOsoba& osoba, const string imie,const string nazwisko,const unsigned int rok, const string miasto, const string wojewodztwo){
    osoba.imie=imie;
    osoba.nazwisko=nazwisko;
    osoba.rok_urodzenia=rok;
    osoba.miejsce_zamieszkania=miasto;
    osoba.wojewodztwo=wojewodztwo;
}

void selektor (SOsoba osoba){
    if(2023-osoba.rok_urodzenia>=18){
        wypisz(osoba);
    }
    else cout<<"osoba jest niepelnoletnia\n";
}

int main(int argc,char* argv[1]){
    if(argc!=6){
        cerr<<"Podano bledna ilosc argumentow (6)"<<endl;
        cout<<"Poprawny zapis to ./nazwa imie nazwisko rok_urodzenia miejsce_zamieszkania wojewodztwo \n";
        return 1;
    }
    
    string imie=argv[1];
    string nazwisko=argv[2];
    int rok_urodzenia=atoi(argv[3]);
    string miejsce_zamieszkania=argv[4];
    string wojewodztwo=argv[5];

    SOsoba osoba;
    SOsoba &os=osoba;

    inicjuj(os,imie,nazwisko,rok_urodzenia,miejsce_zamieszkania,wojewodztwo);
    
    wypisz(osoba);

    cout <<endl;

    selektor(osoba);

    return 0;
}
