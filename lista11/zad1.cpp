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
};

void sprawdz(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu !!";
        fin.clear();
        fin.close();
        exit(0);
    }
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

SOsoba wczytaj(ifstream &fin)
{
    SOsoba osoba;
    sprawdz(fin);
    if (fin.good())
    {
        fin >> osoba.id;
        sprawdz(fin);
        fin >> osoba.email;
        sprawdz(fin);
        fin >> osoba.rok_urodzenia;
        sprawdz(fin);
        fin >> osoba.imie;
        return osoba;
    }
    exit(0);
}

bool wypisz(SOsoba &osoba, ostream &out = cout)
{
    if (&osoba) // Jak to ma działać ??
    {
        out << osoba.id << ' ' << osoba.email << ' ' << osoba.rok_urodzenia << ' ' << osoba.imie << endl;
        return true;
    }
    return false;
}

struct SLista
{
    string nazwa;
    SOsoba *osoba;
};

bool wczytaj(SLista &lista, ifstream &fin)
{
    sprawdz(fin);
    if (fin.good())
    {
        fin >> lista.nazwa;
        sprawdz(fin);
        int n = 0;
        fin >> n;
        sprawdz(fin);
        lista.osoba = new SOsoba[n];
        for (int i = 0; i < n; i++)
        {
            lista.osoba[i] = wczytaj(fin);
        }
        return true;
    }
    return false;
}

bool wypisz(SLista &lista, ostream &out = cout)
{
    if (&lista) // Jak to ma działać ??
    {
        out << lista.nazwa << endl;
        for (int i = 0; i < 4; i++)
        {
            wypisz(lista.osoba[i]);
        }
        return true;
    }
    return false;
}

SOsoba szukaj(SLista &lista, const unsigned int id)
{
    SOsoba osoba;
    for (int i = 0; i < 4; i++)
    {
        if (lista.osoba[i].id == id)
        {
            osoba = lista.osoba[i];
            return osoba;
        }
    }
    exit(0);
}

void podziel(SLista &lista, ofstream &foutM, ofstream &foutK)
{
    for (int i = 0; i < 4; i++)
    {
        int n = size(lista.osoba[i].imie);
        if (lista.osoba[i].imie[n - 1] == 'a')
        {
            sprawdz(foutK);
            foutK << lista.osoba[i].id << ' ' << lista.osoba[i].email << ' ' << lista.osoba[i].rok_urodzenia << ' ' << lista.osoba[i].imie << endl;
        }
        else
        {
            sprawdz(foutM);
            foutM << lista.osoba[i].id << ' ' << lista.osoba[i].email << ' ' << lista.osoba[i].rok_urodzenia << ' ' << lista.osoba[i].imie << endl;
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
    if (argc != 4)
    {
        cerr << "Podano bledna ilosc argumentow(4)" << endl;
        cout << "Poprawny zapis to ./nazwa plik_wej plik_wyj_M plik_wyj_K" << endl;
        return -1;
    }
    ifstream fin;
    ofstream foutM, foutK;
    fin.open(argv[1]);
    foutM.open(argv[2]);
    foutK.open(argv[3]);
    SLista lista;
    wczytaj(lista, fin);
    wypisz(lista);
    SOsoba osoba = szukaj(lista, 482694);
    wypisz(osoba);
    podziel(lista, foutM, foutK);
    foutM.close();
    foutK.close();
    fin.close();

    usun(lista);
    return 0;
}