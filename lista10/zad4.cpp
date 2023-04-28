#include <iostream>
#include <fstream>

using namespace std;

struct SProstopadloscian
{
    float dlugosc, szerokosc, wysokosc;
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

void sprawdz(ofstream &fout)
{
    if (!fout.good())
    {
        cerr << "Błąd na strumieniu !!";
        fout.clear();
        fout.close();
        exit(0);
    }
}

ifstream otworz(string plik_wej)
{
    ifstream fin;
    fin.open(plik_wej);
    return fin;
}
void zamknij(ifstream &fin)
{
    fin.close();
}

ofstream otworz1(string plik_wej)
{
    ofstream fout;
    fout.open(plik_wej, ios::app);
    return fout;
}
void zamknij(ofstream &fout)
{
    fout.close();
}

SProstopadloscian *wczytaj(const char *plik_wej, int &n)
{
    ifstream fin = otworz(plik_wej);
    sprawdz(fin);
    fin >> n;
    sprawdz(fin);
    SProstopadloscian *prost;
    prost = new SProstopadloscian[n];
    if (fin.good())
    {
        for (int i = 0; i < n; i++)
        {
            sprawdz(fin);
            fin >> prost[i].dlugosc;
            sprawdz(fin);
            fin >> prost[i].szerokosc;
            sprawdz(fin);
            fin >> prost[i].wysokosc;
        }
        zamknij(fin);
        return prost;
    }
    zamknij(fin);
    return nullptr;
}

float pole(const SProstopadloscian *p)
{
    float pole = 2 * p->dlugosc * p->szerokosc + 2 * p->dlugosc * p->wysokosc + 2 * p->szerokosc * p->wysokosc;
    return pole;
}

int znajdz_pole(const SProstopadloscian *p, const int n)
{
    int k = 0;
    float pol = pole(&p[0]);
    for (int i = 0; i < n; i++)
    {
        if (pol < pole(&p[i]))
        {
            pol = pole(&p[i]);
            k = i;
        }
    }
    return k;
}

float objetosc(const SProstopadloscian &p)
{
    float V = p.dlugosc * p.szerokosc * p.wysokosc;
    return V;
}

float znajdz_objetosc(const SProstopadloscian *p, const int n)
{
    float Vszuk = objetosc(p[0]);
    for (int i = 0; i < n; i++)
    {
        if (Vszuk < objetosc(p[i]))
        {
            Vszuk = objetosc(p[i]);
        }
    }
    return Vszuk;
}

bool wysokosc(const SProstopadloscian &p1, const SProstopadloscian &p2)
{
    if (p1.wysokosc > p2.wysokosc)
    {
        return true;
    }
    return false;
}

void sortuj(SProstopadloscian *p, const int n, bool (*wfun)(const SProstopadloscian &, const SProstopadloscian &))
{
    float dlugosc, szerokosc, wysokosc;
    for (int i = 0; i < n - 1; i++)
    {
        while (wfun(p[i], p[i + 1]))
        {
            dlugosc = p[i].dlugosc;
            szerokosc = p[i].szerokosc;
            wysokosc = p[i].wysokosc;
            p[i].dlugosc = p[i + 1].dlugosc;
            p[i].szerokosc = p[i + 1].szerokosc;
            p[i].wysokosc = p[i + 1].wysokosc;
            p[i + 1].dlugosc = dlugosc;
            p[i + 1].szerokosc = szerokosc;
            p[i + 1].wysokosc = wysokosc;
            i = 0;
        }
    }
}

void wypisz(const SProstopadloscian *p)
{
    cout << p->dlugosc << '\t' << p->szerokosc << '\t' << p->wysokosc << '\n';
}

void wypisz(const SProstopadloscian *p, const int n)
{
    for (int i = 0; i < n; i++)
    {
        wypisz(&p[i]);
    }
}

bool wypisz(const SProstopadloscian &p, ofstream &fout)
{
    sprawdz(fout);
    if (fout.good())
    {
        sprawdz(fout);
        fout << p.dlugosc << '\t';
        sprawdz(fout);
        fout << p.szerokosc << '\t';
        sprawdz(fout);
        fout << p.wysokosc << '\n';
        return true;
    }
    return false;
}

bool wypisz(const SProstopadloscian *p, const int n, const string &plik_wyj)
{
    ofstream fout = otworz1(plik_wyj);
    sprawdz(fout);
    if (fout.good())
    {
        for (int i = 0; i < n; i++)
        {
            wypisz(p[i], fout);
        }
        zamknij(fout);
        return true;
    }
    zamknij(fout);
    return false;
}

void usun(SProstopadloscian *p)
{
    if (p)
    {
        delete[] p;
        p = nullptr;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Podano błędną ilośc argumentow(3)" << endl;
        cout << "Poprawny zapis to ./nazwa plik_wej plik_wyj" << endl;
        return -1;
    }
    int n = 0;
    SProstopadloscian *p = wczytaj(argv[1], n);
    if (p)
    {
        wypisz(p, n);
        if (wypisz(p, n, argv[2]))
            cout << "Zapisano pomyslnie do pliku" << endl;
        else
            cout << "Cos poszlo nie tak!" << endl;
        cout << "Prostopadloscian o najwiekszym polu powierzchni "
             << "znajduje sie na pozycji: " << znajdz_pole(p, n) << endl;
        cout << "Najwieksza objetosc prostopadloscianu wynosi: " << znajdz_objetosc(p, n) << endl;
        sortuj(p, n, wysokosc);
        wypisz(p, n);
        if (wypisz(p, n, argv[2]))
            cout << "Zapisano pomyslnie do pliku" << endl;
        else
            cout << "Cos poszlo nie tak!" << endl;
    }
    usun(p);
    return 0;
}