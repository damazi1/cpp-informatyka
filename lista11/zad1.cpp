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
    if (!out.good())
    {
        cerr << "blad na strumieniu wyjsciowym wypisz 1" << endl;
        out.clear();
        return false;
    }
    if (id != 0)
    {
        out << id << ' ';

        if (!out.good())
        {
            cerr << "blad na strumieniu wyjsciowym wypisz 2" << endl;
            out.clear();
            return false;
        }
        if (email != "")
        {
            out << email << ' ';

            if (!out.good())
            {
                cerr << "blad na strumieniu wyjsciowym wypisz 3" << endl;
                out.clear();
                return false;
            }
            if (rok_urodzenia != 0)
            {
                out << rok_urodzenia << ' ';

                if (!out.good())
                {
                    cerr << "blad na strumieniu wyjsciowym wypisz 4" << endl;
                    out.clear();
                    return false;
                }
                if (imie != "")
                {
                    out << imie << endl;

                    if (!out.good())
                    {
                        cerr << "blad na strumieniu wyjsciowym wypisz 5" << endl;
                        out.clear();
                        return false;
                    }
                    return true;
                }
            }
        }
    }

    if (!out.good())
    {
        cerr << "blad na strumieniu wyjsciowym wypisz 6" << endl;
        out.clear();
        return false;
    }
    return false;
}

bool SLista::wczytaj(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "błąd wczytaj 1" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    if (fin.good())
    {
        fin >> nazwa;
        if (!fin.good())
        {
            cerr << "błąd wczytaj 2" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> n;
        if (!fin.good())
        {
            cerr << "błąd wczytaj 3" << endl;
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
    if (!fin.good())
    {
        cerr << "błąd wczytaj 4" << endl;
        fin.clear();
        fin.close();
        return false;
    }

    return false;
}

bool SLista::wypisz(ostream &out)
{
    if (!out.good())
    {
        cerr << "blad na strumieniu wyjsciowym wypisz 5" << endl;
        out.clear();
        return false;
    }
    if (nazwa != "")
    {
        out << nazwa << endl;
        if (!out.good())
        {
            cerr << "blad na strumieniu wyjsciowym wypisz 5" << endl;
            out.clear();
            return false;
        }
        if (n != 0)
        {
            out << n << endl;

            for (int i = 0; i < n; i++)
            {
                if (!out.good())
                {
                    cerr << "blad na strumieniu wyjsciowym wypisz 5" << endl;
                    out.clear();
                    return false;
                }

                osoba[i].wypisz();
            }
            return true;
        }
    }
    if (!out.good())
    {
        cerr << "blad na strumieniu wyjsciowym wypisz 5" << endl;
        out.clear();
        return false;
    }
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
    if (!foutM.good())
    {
        cerr << "błąd foutM 1" << endl;
        foutM.clear();
        foutM.close();
        return;
    }
    if (!foutK.good())
    {
        cerr << "błąd foutM 1" << endl;
        foutK.clear();
        foutK.close();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int n = size(osoba[i].imie);
        if (osoba[i].imie[n - 1] == 'a')
        {
            osoba[i].wypisz(foutK);
            if (!foutK.good())
            {
                cerr << "błąd foutM 1" << endl;
                foutK.clear();
                foutK.close();
                return;
            }
        }
        else
        {

            osoba[i].wypisz(foutM);
            if (!foutM.good())
            {
                cerr << "błąd foutM 1" << endl;
                foutM.clear();
                foutM.close();
                return;
            }
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
    fin.open(argv[1]);
    SLista lista;
    if (lista.wczytaj(fin))
    {
        if (lista.wypisz())
        {
            SOsoba osoba = lista.szukaj(atoi(argv[4]));
            if (osoba.wypisz())
            {
                ofstream foutM;
                ofstream foutK;
                foutM.open(argv[2]);
                foutK.open(argv[3]);
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

