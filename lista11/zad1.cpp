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
    bool wypisz(SOsoba &, ostream &out = cout);
};

bool sprawdz(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu !!";
        fin.clear();
        fin.close();
        return 1;
    }
    return 0;
}
void sprawdz(ofstream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu !!";
        fin.clear();
        fin.close();
        exit(0);
    }
}

void sprawdz(ostream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu !!";
        fin.clear();
        exit(0);
    }
}

SOsoba SOsoba::wczytaj(ifstream &fin)
{
    SOsoba osoba;
    sprawdz(fin);
    if (fin.good())
    {
        fin >> osoba.id;
        if (sprawdz(fin))
        {
        };
        fin >> osoba.email;
        sprawdz(fin);
        fin >> osoba.rok_urodzenia;
        sprawdz(fin);
        fin >> osoba.imie;
        return osoba;
    }
    osoba.id = 0;
    osoba.email = "";
    osoba.rok_urodzenia = 0;
    osoba.imie = "";
    return osoba;
}

bool SOsoba::wypisz(SOsoba &osoba, ostream &out)
{
    if (osoba.id)
    {
        out << osoba.id << ' ';
        if (osoba.email.empty())
        {
            out << osoba.email << ' ';
            if (osoba.rok_urodzenia)
            {
                out << osoba.rok_urodzenia << ' ';
                if (osoba.imie != "")
                {
                    out << osoba.imie << endl;
                    return true;
                }
            }
        }
    }
    if (!out.good())
    {
        cerr << "Błąd na domyślnym strumieniu wyjściowym !!";
        out.clear();
        return false;
    }
    return false;
}

struct SLista
{
    string nazwa;
    int n;
    SOsoba *osoba;
    bool wczytaj(SLista &, ifstream &);
    bool wypisz(SLista &, ostream &out = cout);
    SOsoba szukaj(SLista &, const unsigned int);
    void podziel(SLista &, ofstream &, ofstream &);
};

bool SLista::wczytaj(SLista &lista, ifstream &fin)
{
    sprawdz(fin);
    if (fin.good())
    {
        fin >> lista.nazwa;
        sprawdz(fin);
        fin >> lista.n;
        sprawdz(fin);
        if (lista.n > 0)
        {
            lista.osoba = new SOsoba[lista.n];
        }
        for (int i = 0; i < lista.n; i++)
        {
            lista.osoba[i] = lista.osoba[i].wczytaj(fin);
        }
        return true;
    }
    return false;
}

bool SLista::wypisz(SLista &lista, ostream &out)
{
    if (lista.nazwa != "")
    {
        out << lista.nazwa << endl;
        for (int i = 0; i < lista.n; i++)
        {
            lista.osoba[i].wypisz(lista.osoba[i], out);
        }
    }
    if (!out.good())
    {
        cerr << "Błąd na domyślnym strumieniu wyjściowym !!";
        out.clear();
        return false;
    }
    return false;
}

SOsoba SLista::szukaj(SLista &lista, const unsigned int id)
{
    SOsoba osoba;
    int n = id;
    for (int i = 0; i < lista.n; i++)
    {
        if (lista.osoba[i].id == n)
        {
            osoba = lista.osoba[i];
            return osoba;
        }
    }
    osoba.id = 0;
    osoba.email = "";
    osoba.rok_urodzenia = 0;
    osoba.imie = "";
    return osoba;
}

void SLista::podziel(SLista &lista, ofstream &foutM, ofstream &foutK)
{
    for (int i = 0; i < lista.n; i++)
    {
        int n = size(lista.osoba[i].imie);
        if (lista.osoba[i].imie[n - 1] == 'a')
        {
            sprawdz(foutK);
            lista.osoba[i].wypisz(lista.osoba[i], foutK);
        }
        else
        {
            sprawdz(foutM);
            lista.osoba[i].wypisz(lista.osoba[i], foutM);
        }
    }
}

void usun(SLista lista)
{
    if (lista.osoba)
    {
        delete[] lista.osoba;
        lista.osoba = nullptr;
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
    lista.wczytaj(lista, fin);
    lista.wypisz(lista);
    SOsoba osoba = lista.szukaj(lista, atoi(argv[4]));
    osoba.wypisz(osoba);
    lista.podziel(lista, foutM, foutK);
    foutM.close();
    foutK.close();
    fin.close();

    usun(lista);
    return 0;
}