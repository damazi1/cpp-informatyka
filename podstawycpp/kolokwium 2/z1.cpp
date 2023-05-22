#include <iostream>
#include <string>

using namespace std;

struct SOsoba
{
    string imie, nazwisko;
    int rok_ur;
    string miejsce_zamieszkania, wojewodzwto;
};

SOsoba inicjuj(const string imie, const string nazwisko, const unsigned int rok, const string miasto, const string wojewodztwo)
{
    SOsoba osoba;
    osoba.imie = imie;
    osoba.nazwisko = nazwisko;
    osoba.rok_ur = rok;
    osoba.miejsce_zamieszkania = miasto;
    osoba.wojewodzwto = wojewodztwo;
    return osoba;
}
void inicjuj(SOsoba &osoba, const string imie, const string nazwisko, const unsigned int rok, const string miasto, const string wojewodztwo)
{
    osoba.imie = imie;
    osoba.nazwisko = nazwisko;
    osoba.rok_ur = rok;
    osoba.miejsce_zamieszkania = miasto;
    osoba.wojewodzwto = wojewodztwo;
}
void inicjuj1(SOsoba *osoba, const string imie, const string nazwisko, const unsigned int rok, const string miasto, const string wojewodztwo)
{
    osoba->imie = imie;
    osoba->nazwisko = nazwisko;
    osoba->rok_ur = rok;
    osoba->miejsce_zamieszkania = miasto;
    osoba->wojewodzwto = wojewodztwo;
}

SOsoba wczytaj(SOsoba (*wfun)(const string, const string, const unsigned int, const string, const string))
{
    string imie, nazwisko, miasto, wojewodztwo;
    int rok;
    cout << "Podaj imie nazwisko rok miasto wojewodztwo: ";
    cin >> imie >> nazwisko >> rok >> miasto >> wojewodztwo;

    return wfun(imie, nazwisko, rok, miasto, wojewodztwo);
}

void wczytaj(SOsoba &osoba, void (*wfun)(SOsoba &, const string, const string, const unsigned int, const string, const string))
{
    string imie, nazwisko, miasto, wojewodztwo;
    int rok;
    cout << "Podaj imie nazwisko rok miasto wojewodztwo: ";
    cin >> imie >> nazwisko >> rok >> miasto >> wojewodztwo;

    wfun(osoba, imie, nazwisko, rok, miasto, wojewodztwo);
}

void wczytaj1(SOsoba *osoba, void (*wfun)(SOsoba *, const string, const string, const unsigned int, const string, const string))
{
    string imie, nazwisko, miasto, wojewodztwo;
    int rok;
    cout << "Podaj imie nazwisko rok miasto wojewodztwo: ";
    cin >> imie >> nazwisko >> rok >> miasto >> wojewodztwo;

    wfun(osoba, imie, nazwisko, rok, miasto, wojewodztwo);
}

void wyswietl(SOsoba osoba)
{
    cout << osoba.imie << "\t" << osoba.nazwisko << "\t" << osoba.rok_ur << "\t" << osoba.miejsce_zamieszkania << "\t" << osoba.wojewodzwto << "\t";
}

void wyswietl1(SOsoba *osoba)
{
    cout << osoba->imie << "\t" << osoba->nazwisko << "\t" << osoba->rok_ur << "\t" << osoba->miejsce_zamieszkania << "\t" << osoba->wojewodzwto << "\t";
}

void selektor(SOsoba &osoba)
{
    if (2023 - osoba.rok_ur >= 18)
    {
        wyswietl(osoba);
    }
    cout << "Nie jest pełnoletnia" << endl;
}
void selektor1(SOsoba *osoba)
{
    if (2023 - osoba->rok_ur >= 18)
    {
        wyswietl1(osoba);
    }
    else
    {
        cout << "Nie jest pełnoletnia" << endl;
    }
}

int main()
{
    SOsoba osoba1 = wczytaj(&inicjuj);
    wyswietl(osoba1);
    selektor(osoba1);
    SOsoba &osoba2 = osoba1;
    wczytaj(osoba2, &inicjuj);
    wyswietl(osoba2);
    selektor(osoba2);
    SOsoba *osoba3 = &osoba2;
    wczytaj1(osoba3, &inicjuj1);
    wyswietl1(osoba3);
    selektor1(osoba3);
    return 0;
}