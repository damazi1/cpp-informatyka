#include <iostream>

using namespace std;

class adres
{
    string miasto, ulica;
    int nr;

public:
    adres()
    {
        miasto = "brak";
        ulica = "brak";
        nr = 0;
    }
    adres(const string &a1, const string &a2, int a3)
    {
        miasto = a1;
        ulica = a2;
        nr = a3;
    }

    ostream &view(ostream &out) const
    {
        return out << miasto << ", " << ulica << ", " << nr << '\n';
    }
    friend ostream &operator<<(ostream &out, const adres &r);
};
ostream &operator<<(ostream &out, const adres &r)
{
    return r.view(out);
}

class osoba
{
    string imie;
    int wiek;
    adres *adr;

public:
    osoba()
    {
        imie = "";
        wiek = 0;
        adr = nullptr;
    }
    osoba(const string &a1, int a2, const adres &a3) : imie(a1), wiek(a2), adr(new adres(a3)) {}
    osoba(const osoba &a1) : imie(a1.imie), wiek(a1.wiek), adr(new adres(*a1.adr)) {}

    ~osoba()
    {
        if (adr)
        {
            delete adr;
            adr = nullptr;
        }
    }

    ostream &view(ostream &out) const
    {
        return out << imie << ", " << wiek << ", " << *adr << '\n';
    }

    friend ostream &operator<<(ostream &out, const osoba &r);
};

ostream &operator<<(ostream &out, const osoba &r)
{
    return r.view(out);
}

int main()
{
    adres *wsk = new adres("Częstochowa", "Dąbrowskiego", 73);
    cout << wsk << '\n';
    cout << *wsk << '\n';

    adres a1(*wsk);
    if (wsk)
    {
        delete wsk;
        wsk = nullptr;
    }

    const adres *wsk1 = new adres("Łódź", "Piotrkowska", 33);

    cout << a1 << '\n';
    cout << *wsk1 << '\n';

    adres a2;
    cout << a2 << '\n';
    a2 = a1;
    cout << a2 << '\n';

    osoba os1("Ala", 25, *wsk1);
    if (wsk1)
    {
        delete wsk1;
        wsk1 = nullptr;
    }
    cout << os1 << '\n';

    osoba os2(os1);

    cout << os2 << '\n';

    osoba os3;
    // cout << os3 << '\n';
    os3 = os2;
    return 0;
}