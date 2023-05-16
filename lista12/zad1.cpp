#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct STransakcje
{
    double kwota;
    string opis_t;

    STransakcje()
    {
        kwota = 0;
        opis_t = "";
    }
    ~STransakcje()
    {
        kwota = 0;
        opis_t = "";
    }
};

struct SKonto
{
    string numer_konta;
    double saldo;
    int liczba_transakcji;
    STransakcje *transakcje;

    SKonto()
    {
        numer_konta = "";
        saldo = 0;
        liczba_transakcji = 0;
        transakcje = nullptr;
    }
    ~SKonto()
    {
        numer_konta = "";
        saldo = 0;
        liczba_transakcji = 0;
        if (transakcje)
        {
            delete[] transakcje;
            transakcje = nullptr;
        }
    }

    bool wczytaj_konto(istream &fin = cin);
    bool wyswietl_konto(bool pokaz_transakcje);
    bool dodaj_transakcje(double kwota, const string &opis);
};

struct SKlient
{
    string imie, nazwisko;
    SKonto *konto;

    SKlient()
    {
        imie = "";
        nazwisko = "";
        konto = nullptr;
    }

    ~SKlient()
    {
        imie = "";
        nazwisko = "";
        if (konto)
        {
            delete[] konto;
            konto = nullptr;
        }
    }
    bool wczytaj_dane_klienta(istream &fin = cin);
    bool wypisz_klienta(ostream &out = cout);
    bool wplata(double kwota);
    bool wyplata(double kwota);
};

struct SBank
{
    string nazwa_banku;
    int liczba_klientow;
    SKlient *klient;
    SBank()
    {
        nazwa_banku = "";
        liczba_klientow = 0;
        klient = nullptr;
    }
    ~SBank()
    {
        nazwa_banku = "";
        liczba_klientow = 0;
        if (klient)
        {
            delete[] klient;
            klient = nullptr;
        }
    }
    bool wczytaj_bank(istream &fin = cin);
    bool wyswietl_bank(ostream &out = cout);
    bool dodaj_konto(const string &nazwa_wlasciciela);
    bool losuj_nr_konta(string &wygenerowany_numer);
    bool usun_konto(const string &numer_konta);
    SKonto *znajdz_konto(const string &numer_konta);
};

int main()
{

    return 0;
}

bool SKonto::wczytaj_konto(istream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia w wczytaj_konto!";
        fin.clear();
        return false;
    }
    fin >> numer_konta;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia w wczytaj_konto!";
        fin.clear();
        return false;
    }
    fin >> saldo;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia w wczytaj_konto!";
        fin.clear();
        return false;
    }
    fin >> liczba_transakcji;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia w wczytaj_konto!";
        fin.clear();
        return false;
    }
    if (liczba_transakcji == 0)
    {
        cout << "Na tym koncie nie została dokonana żadna transakcja " << endl;
        return true;
    }
    else if (liczba_transakcji < 0)
    {
        cerr << "Błędna ilośc transakcji, wartość musi być większa od 0 !" << endl;
        return false;
    }
    else
    {
        transakcje = new STransakcje[liczba_transakcji];
        return true;
    }
    return false;
}

bool SKonto::wyswietl_konto(bool pokaz_tranzakcje)
{

    return false;
}

bool SKonto::dodaj_transakcje(double kwota, const string &opis)
{

    return false;
}