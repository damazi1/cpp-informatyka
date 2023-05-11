#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct SOsoba
{
    int id;
    string email;
    int rok_urodzenia;
    string imie;

    SOsoba()
    {
        id = 0;
        email = "";
        rok_urodzenia = 0;
        imie = "";
    }
    ~SOsoba()
    {
        id = 0;
        email = "";
        rok_urodzenia = 0;
        imie = "";
    }

    SOsoba wczytaj(ifstream &);
    bool wypisz(ostream &out = cout);
};

bool sprawdz1(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu Wejściowym !!";
        fin.clear();
        fin.close();
        return 1;
    }
    return 0;
}
bool sprawdz(ofstream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu Wyjściowym!!";
        fin.clear();
        fin.close();
        return 1;
    }
    return 0;
}

bool sprawdz(ostream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu konsoli !!";
        fin.clear();
        return 1;
    }
    return 0;
}

SOsoba SOsoba::wczytaj(ifstream &fin)
{
    SOsoba osoba;
    if (sprawdz1(fin))
        return SOsoba();
    if (fin.good())
    {
        fin >> id;
        if (sprawdz1(fin))
        {
            return SOsoba();
        }
        fin >> email;
        if (sprawdz1(fin))
        {
            return SOsoba();
        }
        fin >> rok_urodzenia;
        if (sprawdz1(fin))
        {
            return SOsoba();
        }
        fin >> imie;
        if (sprawdz1(fin))
        {
            return SOsoba();
        }
        return osoba;
    }
    return SOsoba();
}

bool SOsoba::wypisz(ostream &out)
{
    if (sprawdz(out))
        return false;
    if (id != 0)
    {
        out << id << ' ';
        if (sprawdz(out))
            return false;
        if (email != "")
        {
            out << email << ' ';
            if (sprawdz(out))
                return false;
            if (rok_urodzenia != 0)
            {
                out << rok_urodzenia << ' ';
                if (sprawdz(out))
                    return false;
                if (imie != "")
                {
                    out << imie << endl;
                    if (sprawdz(out))
                        return false;
                    return true;
                }
            }
        }
    }
    if (sprawdz(out))
        return false;
    return false;
}

struct SLista
{
    string nazwa;
    int n;
    SOsoba *osoba;

    SLista()
    {
        nazwa = "";
        n = 0;
        osoba = nullptr;
    }

    ~SLista()
    {
        nazwa = "";
        n = 0;
        if (osoba)
        {
            delete[] osoba;
            osoba = nullptr;
        }
    }

    bool wczytaj(ifstream &);
    bool wypisz(ostream &out = cout);
    SOsoba szukaj(const unsigned int);
    void podziel(ofstream &, ofstream &);
};

bool SLista::wczytaj(ifstream &fin)
{ // usun
    if (sprawdz1(fin))
        return false;
    if (fin.good())
    {
        fin >> nazwa;
        if (sprawdz1(fin))
            return false;
        fin >> n;
        if (sprawdz1(fin))
            return false;
        if (n > 0 && n < 1000)
        {
            osoba = new SOsoba[n];

            for (int i = 0; i < n; i++)
            {
                osoba[i] = osoba[i].wczytaj(fin);
            }
            return true;
        }
    }
    SOsoba();
    if (sprawdz1(fin))
        return false;
    return false;
}

bool SLista::wypisz(ostream &out)
{
    if (sprawdz(out))
        return false;
    if (nazwa != "")
    {
        out << nazwa << endl;
        if (sprawdz(out))
            return false;
        if (n != 0)
        {
            out << n << endl;

            for (int i = 0; i < n; i++)
            {
                if (sprawdz(out))
                    return false;
                osoba[i].wypisz(out);
            }
            return true;
        }
    }
    if (sprawdz(out))
        return false;
    return false;
}

SOsoba SLista::szukaj(const unsigned int id)
{
    int m = id;
    for (int i = 0; i < n; i++)
    {
        if (osoba[i].id == m)
        {
            return osoba[i];
        }
    }
    return SOsoba();
}

void SLista::podziel(ofstream &foutM, ofstream &foutK)
{
    if (sprawdz(foutM))
        return;
    if (sprawdz(foutK))
        return;
    for (int i = 0; i < n; i++)
    {
        int n = size(osoba[i].imie);
        if (osoba[i].imie[n - 1] == 'a')
        {
            if (sprawdz(foutK))
                return;
            osoba[i].wypisz(foutK);
        }
        else
        {
            if (sprawdz(foutM))
                return;
            osoba[i].wypisz(foutM);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        cerr << "Podano bledna ilosc argumentow(5)" << endl;
        cout << "Poprawny zapis to ./nazwa plik_wej plik_wyj_M plik_wyj_K id_szukane" << endl;
        return -1;
    }
    ifstream fin;
    ofstream foutM, foutK;
    fin.open(argv[1]);
    foutM.open(argv[2]);
    foutK.open(argv[3]);
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejściowym!!";
        fin.clear();
        fin.close();
        foutM.clear();
        foutM.close();
        foutK.clear();
        foutK.close();
        return 1;
    }
    if (!foutK.good())
    {
        cerr << "Błąd na strumieniu Wyjściowym!!";
        fin.clear();
        fin.close();
        foutM.clear();
        foutM.close();
        foutK.clear();
        foutK.close();
        return 1;
    }
    if (!foutM.good())
    {
        cerr << "Błąd na strumieniu Wyjściowym!!";
        fin.clear();
        fin.close();
        foutM.clear();
        foutM.close();
        foutK.clear();
        foutK.close();
        return 1;
    }

    SLista lista;
    lista.wczytaj(fin);
    lista.wypisz();
    SOsoba osoba = lista.szukaj(atoi(argv[4]));
    osoba.wypisz();
    lista.podziel(foutM, foutK);
    foutM.close();
    foutK.close();
    fin.close();

    return 0;
}