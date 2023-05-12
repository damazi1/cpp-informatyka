#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct SOsoba
{
    string imie;
    int rok_urodzenia;
    string znak_zodiaku;
    int szczesliwa_liczba;

    SOsoba()
    {
        imie = "";
        rok_urodzenia = 0;
        znak_zodiaku = "";
        szczesliwa_liczba = 0;
    }
    ~SOsoba()
    {
        imie = "";
        rok_urodzenia = 0;
        znak_zodiaku = "";
        szczesliwa_liczba = 0;
    }

    bool wczytaj(ifstream &);
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
    SOsoba szukaj(const string);
    void podziel(ofstream &, ofstream &);
    void podziel();
};

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        cerr << "Błędna ilosc argumentow (5)" << endl;
        cout << "Poprawny zapis to ./nazwa plik_wejsciowy plik_wyjsicowy_M plik_wyjsciowy_k znak_zodiaku" << endl;
        return -1;
    }
    SLista lista;
    ifstream fin;
    fin.open(argv[1]);
    if (lista.wczytaj(fin))
    {
        if (lista.wypisz())
        {
            SOsoba osoba = lista.szukaj(argv[4]);
            if (!osoba.wypisz())
            {
                cerr << "Nie ma takiego znaku w pliku" << endl;
            }
            ofstream foutM, foutK;
            foutM.open(argv[2]);
            foutK.open(argv[3]);
            lista.podziel(foutM, foutK);
            foutM.close();
            foutK.close();
            lista.podziel();
        }

        else
        {
            cerr << "Blad podczas Wypisywania danych z pliku" << endl;
            fin.clear();
            fin.close();
            return 1;
        }
    }
    else
    {
        cerr << "Blad podczas wczytywania danych z pliku" << endl;
        fin.clear();
        fin.close();
        return 1;
    }
    fin.close();

    return 0;
}

bool SOsoba::wczytaj(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd podczas wczytywania danych z pliku (1)" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    if (fin.good())
    {
        fin >> imie;
        if (!fin.good())
        {
            cerr << "Błąd podczas wczytywania danych z pliku (imie)" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> rok_urodzenia;
        if (!fin.good())
        {
            cerr << "Błąd podczas wczytywania danych z pliku (rok)" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> znak_zodiaku;
        if (!fin.good())
        {
            cerr << "Błąd podczas wczytywania danych z pliku (znak_zodiaku)" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> szczesliwa_liczba;
        if (!fin.good())
        {
            cerr << "Błąd podczas wczytywania danych z pliku (liczba)" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        return true;
    }
    if (!fin.good())
    {
        cerr << "blad podczas wczytywania danych z pliku (gdzies poza)" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    return false;
}

bool SOsoba::wypisz(ostream &out)
{
    if (!out.good())
    {
        cerr << "błąd na strumieniu wyjscia (wypisz_start)" << endl;
        out.clear();
        return false;
    }
    if (out.good())
    {
        if (imie != "")
        {
            out << imie << " ";
            if (!out.good())
            {
                cerr << "błąd na strumieniu wyjscia (wypisz_imie)" << endl;
                out.clear();
                return false;
            }
            if (rok_urodzenia != 0)
            {
                out << rok_urodzenia << " ";
                if (!out.good())
                {
                    cerr << "błąd na strumieniu wyjscia (wypisz_rok)" << endl;
                    out.clear();
                    return false;
                }
                if (znak_zodiaku != "")
                {
                    out << znak_zodiaku << " ";
                    if (!out.good())
                    {
                        cerr << "błąd na strumieniu wyjscia (wypisz_znak)" << endl;
                        out.clear();
                        return false;
                    }
                    if (szczesliwa_liczba != 0)
                    {
                        out << szczesliwa_liczba << endl;
                        if (!out.good())
                        {
                            cerr << "błąd na strumieniu wyjscia (wypisz_liczba)" << endl;
                            out.clear();
                            return false;
                        }
                        return true;
                    }
                }
            }
        }
    }
    if (!out.good())
    {
        cerr << "błąd na strumieniu wyjscia (wypisz_koniec)" << endl;
        out.clear();
        return false;
    }
    return false;
}

bool SLista::wczytaj(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia (wczytaj_li_start)" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    if (fin.good())
    {
        fin >> nazwa;
        if (!fin.good())
        {
            cerr << "Błąd na strumieniu wejścia (wczytaj_li_nazwa)" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> n;
        if (!fin.good())
        {
            cerr << "Błąd na strumieniu wejścia (wczytaj_li_n)" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        if (n < 1 && n > 1000)
        {
            cerr << "Błędna wielkośc tablicy (1-1000)" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        osoba = new SOsoba[n];
        for (int i = 0; i < n; i++)
        {
            if (!osoba[i].wczytaj(fin))
            {
                cerr << "Błąd na strumieniu wejścia (wczytaj_li_osoba)" << endl;
                fin.clear();
                fin.close();
                return false;
            }
        }
        return true;
    }
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia (wczytaj_li)" << endl;
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
        cerr << "Błąd na strumieniu wyjscia (wypisz_pocz)" << endl;
        out.clear();
        return false;
    }
    if (out.good())
    {
        if (nazwa != "")
        {
            out << nazwa << " " << endl;
            if (!out.good())
            {
                cerr << "Błąd na strumieniu wyjscia (wypisz_pocz)" << endl;
                out.clear();
                return false;
            }
            if (n > 0)
            {
                out << n << endl;
                if (!out.good())
                {
                    cerr << "Błąd na strumieniu wyjscia (wypisz_pocz)" << endl;
                    out.clear();
                    return false;
                }
                for (int i = 0; i < n; i++)
                {
                    osoba[i].wypisz(out);
                    if (!out.good())
                    {
                        cerr << "Błąd na strumieniu wyjscia (wypisz_pocz)" << endl;
                        out.clear();
                        return false;
                    }
                }
                return true;
            }
        }
    }
    if (!out.good())
    {
        cerr << "Błąd na strumieniu wyjscia (wypisz_pocz)" << endl;
        out.clear();
        return false;
    }
    return false;
}

SOsoba SLista::szukaj(const string str)
{
    for (int i = 0; i < n; i++)
    {
        if (osoba[i].znak_zodiaku == str)
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
        cerr << "blad na strumieniu wyjscia do pliku dla Mężczyzn" << endl;
        foutM.clear();
        foutM.close();
        return;
    }
    if (!foutK.good())
    {
        cerr << "blad na strumieniu wyjscia do pliku dla Kobiet" << endl;
        foutK.clear();
        foutK.close();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int m = size(osoba[i].znak_zodiaku);
        if (osoba[i].znak_zodiaku[m - 1] == 'a')
        {
            osoba[i].wypisz(foutK);

            if (!foutK.good())
            {
                cerr << "blad na strumieniu wyjscia do pliku dla Kobiet" << endl;
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
                cerr << "blad na strumieniu wyjscia do pliku dla Mężczyzn" << endl;
                foutM.clear();
                foutM.close();
                return;
            }
        }
    }
}

void SLista::podziel()
{
    for (int i = 0; i < n; i++)
    {
        if (osoba[i].szczesliwa_liczba % 2 == 0)
        {
            osoba[i].wypisz();
        }
    }
}