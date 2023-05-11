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

int main()
{
    SLista lista;
    ifstream fin;
    fin.open("in1.txt");
    if (!lista.wczytaj(fin))
    {
        if (!lista.wypisz())
        {
        }
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
        out << imie << " ";
        if (!out.good())
        {
            cerr << "błąd na strumieniu wyjscia (wypisz_imie)" << endl;
            out.clear();
            return false;
        }
        out << rok_urodzenia << " ";
        if (!out.good())
        {
            cerr << "błąd na strumieniu wyjscia (wypisz_rok)" << endl;
            out.clear();
            return false;
        }
        out << znak_zodiaku << " ";
        if (!out.good())
        {
            cerr << "błąd na strumieniu wyjscia (wypisz_znak)" << endl;
            out.clear();
            return false;
        }
        out << szczesliwa_liczba << endl;
        if (!out.good())
        {
            cerr << "błąd na strumieniu wyjscia (wypisz_liczba)" << endl;
            out.clear();
            return false;
        }
        return true;
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
        cerr << "Błąd na strumieniu wejścia (wczytaj_li)" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    if (fin.good())
    {
        fin >> nazwa;
        if (!fin.good())
        {
            cerr << "Błąd na strumieniu wejścia (wczytaj_li)" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> n;
        if (!fin.good())
        {
            cerr << "Błąd na strumieniu wejścia (wczytaj_li)" << endl;
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
                cerr << "Błąd na strumieniu wejścia (wczytaj_li)" << endl;
                fin.clear();
                fin.close();
                return false;
            }
            if (!fin.good())
            {
                cerr << "Błąd na strumieniu wejścia (wczytaj_li)" << endl;
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
        out << nazwa << " " << endl;
        if (!out.good())
        {
            cerr << "Błąd na strumieniu wyjscia (wypisz_pocz)" << endl;
            out.clear();
            return false;
        }
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
    if (!out.good())
    {
        cerr << "Błąd na strumieniu wyjscia (wypisz_pocz)" << endl;
        out.clear();
        return false;
    }
    return false;
}