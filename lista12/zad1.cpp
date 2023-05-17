#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <sstream>

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
    SKonto konto;

    SKlient()
    {
        imie = "";
        nazwisko = "";
        konto = SKonto();
    }

    ~SKlient()
    {
        imie = "";
        nazwisko = "";
        konto = SKonto();
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
    srand(time(NULL));
    ifstream fin;
    fin.open("in.txt");
    if (!fin.good())
    {
        cerr << "Błąd wczytania Pliku !" << endl;
        fin.clear();
        fin.close();
        return 1;
    }
    SBank konto;
    if (konto.wczytaj_bank(fin))
    {
        if (konto.wyswietl_bank())
        {
            konto.dodaj_konto("Piotr Nowak");
            konto.wyswietl_bank();
        }
    }
    for (int i = 0; i < konto.liczba_klientow; i++)
    {
        if (konto.klient[i].konto.transakcje)
        {
            delete[] konto.klient[i].konto.transakcje;
            konto.klient[i].konto.transakcje = nullptr;
        }
    }
    fin.close();
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
        transakcje = nullptr;
        return false;
    }
    else if (liczba_transakcji < 0)
    {
        cerr << "Błędna ilośc transakcji, wartość musi być większa od 0 !" << endl;
        return false;
    }
    else
    {
        transakcje = new STransakcje[liczba_transakcji];
        for (int i = 0; i < liczba_transakcji; i++)
        {
            fin >> transakcje[i].kwota;
            if (!fin.good())
            {
                cerr << "Błąd na strumieniu wejścia w wczytaj_konto!";
                fin.clear();
                return false;
            }
            fin >> transakcje[i].opis_t;
            if (!fin.good())
            {
                cerr << "Błąd na strumieniu wejścia w wczytaj_konto!";
                fin.clear();
                return false;
            }
        }
        return true;
    }
    return false;
}

bool SKonto::wyswietl_konto(bool pokaz_tranzakcje)
{
    if (pokaz_tranzakcje)
    {
        cout << numer_konta << " " << saldo << " " << liczba_transakcji << "\n";
        for (int i = 0; i < liczba_transakcji; i++)
        {
            cout << transakcje[i].kwota << " " << transakcje[i].opis_t << "\n";
        }
        return true;
    }
    return false;
}

bool SKonto::dodaj_transakcje(double kwota, const string &opis)
{
    STransakcje *trans;
    trans = new STransakcje[liczba_transakcji];
    for (int i = 0; i < liczba_transakcji; i++)
    {
        trans[i].kwota = transakcje[i].kwota;
        trans[i].opis_t = transakcje[i].opis_t;
    }
    if (transakcje)
    {
        delete[] transakcje;
        transakcje = nullptr;
    }
    liczba_transakcji++;
    transakcje = new STransakcje[liczba_transakcji];
    for (int i = 0; i < liczba_transakcji - 1; i++)
    {
        transakcje[i].kwota = trans[i].kwota;
        transakcje[i].opis_t = trans[i].opis_t;
    }
    transakcje[liczba_transakcji - 1].kwota = kwota;
    transakcje[liczba_transakcji - 1].opis_t = opis;

    if (trans)
    {
        delete[] trans;
        trans = nullptr;
    }
    return true;
}

bool SKlient::wczytaj_dane_klienta(istream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia w Wczytaj_dane_klienta" << endl;
        fin.clear();
        return false;
    }
    fin >> imie;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia w Wczytaj_dane_klienta" << endl;
        fin.clear();
        return false;
    }
    fin >> nazwisko;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia w Wczytaj_dane_klienta" << endl;
        fin.clear();
        return false;
    }
    konto.wczytaj_konto(fin);
    return true;
}

bool SKlient::wypisz_klienta(ostream &out)
{
    out << imie << " " << nazwisko << '\n';
    konto.wyswietl_konto(true);
    return true;
}

bool SKlient::wplata(double kwota)
{
    konto.saldo += kwota;
    konto.dodaj_transakcje(kwota, "wplata");
    return true;
}

bool SKlient::wyplata(double kwota)
{
    konto.saldo -= kwota;
    konto.dodaj_transakcje(kwota, "wyplata");
    return true;
}

bool SBank::wczytaj_bank(istream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia Wczytaj_bank" << endl;
        fin.clear();
        return false;
    }
    fin >> nazwa_banku;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia Wczytaj_bank" << endl;
        fin.clear();
        return false;
    }
    fin >> liczba_klientow;
    if (liczba_klientow == 0)
    {
        klient = nullptr;
        cout << "Bank nie posiada klientów " << endl;
        return false;
    }
    if (liczba_klientow < 0)
    {
        klient = nullptr;
        cerr << "Podano błędną ilość klientów" << endl;
        return false;
    }
    else
    {
        klient = new SKlient[liczba_klientow];
        for (int i = 0; i < liczba_klientow; i++)
        {
            klient[i].wczytaj_dane_klienta(fin);
        }
    }
    return true;
}

bool SBank::wyswietl_bank(ostream &out)
{
    if (!out.good())
    {
        cerr << "Błąd podczas wypisywania wyswietl_bank" << endl;
        out.clear();
        return false;
    }
    out << nazwa_banku << " " << liczba_klientow << endl;
    for (int i = 0; i < liczba_klientow; i++)
    {
        klient[i].wypisz_klienta(out);
    }
    return true;
}

bool SBank::losuj_nr_konta(string &wygenerowny_numer)
{
    for (int i = 0; i < 3; i++)
    {
        wygenerowny_numer += rand() % 10+48;
    }
    return true;
}

bool SBank::dodaj_konto(const string &nazwa_wlasciciela)
{
    SKlient*kl;
    kl=new SKlient[liczba_klientow];
    for(int i = 0;i<liczba_klientow;i++){
        kl[i].imie=klient[i].imie;
        kl[i].nazwisko=klient[i].nazwisko;
        kl[i].konto=klient[i].konto;
    }
    liczba_klientow++;
    if(klient){
        delete [] klient;
        klient = nullptr;
    }
    klient = new SKlient [liczba_klientow];
    for(int i = 0;i<liczba_klientow-1;i++){
        klient[i].imie=kl[i].imie;
        klient[i].nazwisko=kl[i].nazwisko;
        klient[i].konto=kl[i].konto;
    }
    stringstream ss(nazwa_wlasciciela);
    string imie;
    string nazwisko;
    string numerkonta="konto";
    losuj_nr_konta(numerkonta);
    ss>>imie;
    ss>>nazwisko;
    klient[liczba_klientow-1].imie=imie;
    klient[liczba_klientow-1].nazwisko=nazwisko;
    klient[liczba_klientow-1].konto.numer_konta=numerkonta;
    klient[liczba_klientow-1].konto.saldo=0;
    klient[liczba_klientow-1].konto.liczba_transakcji=0;
    klient[liczba_klientow-1].konto.transakcje=nullptr;
    if (kl){
        delete [] kl;
        kl=nullptr;
    }
    return true;
}