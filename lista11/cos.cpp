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

bool sprawdz(ifstream &fin)
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
bool sprawdz(ofstream &fout)
{
    if (!fout.good())
    {
        cerr << "Błąd na strumieniu Wyjściowym!!";
        fout.clear();
        fout.close();
        return 1;
    }
    return 0;
}

bool sprawdz(ostream &out)
{
    if (!out.good())
    {
        cerr << "Błąd na strumieniu konsoli !!";
        out.clear();
        return 1;
    }
    return 0;
}

SOsoba SOsoba::wczytaj(ifstream &fin)
{
    SOsoba osoba;
    if (!fin.good())
    {
        cerr << "błąd 1" << endl;
        fin.clear();
        fin.close();
        return SOsoba();
    }
    if (fin.good())
    {
        fin >> osoba.id;
        if (!fin.good())
        {
            cerr << "błąd 2" << endl;
            fin.clear();
            fin.close();
            return SOsoba();
        }
        fin >> osoba.email;

        if (!fin.good())
        {
            cerr << "błąd 3" << endl;
            fin.clear();
            fin.close();
            return SOsoba();
        }
        fin >> osoba.rok_urodzenia;

        if (!fin.good())
        {
            cerr << "błąd 4" << endl;
            fin.clear();
            fin.close();
            return SOsoba();
        }
        fin >> osoba.imie;
        if (!fin.good())
        {
            cerr << "błąd 4" << endl;
            fin.clear();
            fin.close();
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

bool SLista::wczytaj(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "błąd 1" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    if (fin.good())
    {
        fin >> nazwa;
        if (!fin.good())
        {
            cerr << "błąd 2" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> n;
        if (!fin.good())
        {
            cerr << "błąd 3" << endl;
            fin.clear();
            fin.close();
            return false;
        }
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
    if (sprawdz(fin))
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
                osoba[i].wypisz();
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

int main()
{
    ifstream fin;
    fin.open("in.txt");
    SLista lista;
    if (lista.wczytaj(fin))
    {
        if (lista.wypisz())
        {
            SOsoba osoba = lista.szukaj(12098);
            if (osoba.wypisz())
            {
                ofstream foutM;
                ofstream foutK;
                foutM.open("outM.txt");
                foutK.open("outK.txt");
                lista.podziel(foutM, foutK);
                foutM.close();
                foutK.close();
            }
            else
            {
                cerr << "Wystąpił błąd wypisywania danych do pliku" << endl;
                fin.close();
                return 1;
            }
        }
    }
    else
    {
        cerr << "Wystopił błąd podczas wypisywania danych na standardowym wyjsciu" << endl;
        fin.close();
        return 1;
    }
}
else
{
    cerr << "Wystopił błąd podczas wczytywania danych z pliku " << endl;
    fin.close();
    return 1;
}
fin.close();
return 0;
}
