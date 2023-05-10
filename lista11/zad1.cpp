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
bool sprawdz(ofstream &fin)
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

bool sprawdz(ostream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu !!";
        fin.clear();
        return 1;
    }
    return 0;
}

void czysc(SOsoba &osoba)
{
    osoba.id = 0;
    osoba.email = "";
    osoba.rok_urodzenia = 0;
    osoba.imie = "";
}

SOsoba SOsoba::wczytaj(ifstream &fin)
{
    SOsoba osoba;
    if (sprawdz(fin))
        return osoba;
    if (fin.good())
    {
        fin >> osoba.id;
        if (sprawdz(fin))
        {
            czysc(osoba);
            return osoba;
        }
        fin >> osoba.email;
        if (sprawdz(fin))
        {
            czysc(osoba);
            return osoba;
        }
        fin >> osoba.rok_urodzenia;
        if (sprawdz(fin))
        {
            czysc(osoba);
            return osoba;
        }
        fin >> osoba.imie;
        return osoba;
    }
    SOsoba();
    return osoba;
}

bool SOsoba::wypisz(ostream &out)
{
    if (sprawdz(out))
        return false;
    if (id)
    {
        out << id << ' ';
        if (sprawdz(out))
            return false;
        if (email != "")
        {
            out << email << ' ';
            if (sprawdz(out))
                return false;
            if (rok_urodzenia)
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
    if (sprawdz(fin))
        return false;
    if (fin.good())
    {
        fin >> nazwa;
        if (sprawdz(fin))
            return false;
        fin >> n;
        if (sprawdz(fin))
            return false;
        if (n > 0)
        {
            osoba = new SOsoba[n];

            for (int i = 0; i < n; i++)
            {
                osoba[i] = osoba[i].wczytaj(fin);
            }
        }
        return true;
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
        if (n!=0){
            out<<n<<endl;
        
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
    SOsoba os
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
            osoba[i].wypisz(osoba[i], foutK);
        }
        else
        {
            if (sprawdz(foutM))
                return;
            osoba[i].wypisz(osoba[i], foutM);
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
    lista.wczytaj(lista, fin);
    lista.wypisz(lista);
    SOsoba osoba = lista.szukaj(lista, atoi(argv[4]));
    osoba.wypisz(osoba);
    lista.podziel(lista, foutM, foutK);
    foutM.close();
    foutK.close();
    fin.close();

    return 0;
}