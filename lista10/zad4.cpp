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
        return prost;
    }
    return nullptr;
}

float pole(const SProstopadloscian* p)
{
    float pole = 2*p->dlugosc*p->szerokosc+2*p->dlugosc*p->wysokosc+2*p->szerokosc*p->wysokosc;
    return pole;
}

int znajdz_pole(const SProstopadloscian *p, const int n)
{
    int k=0;
    float pol=0;
    for (int i=0;i<n;i++){
        pol=pole(&p[i]);
        if(pol<pole(&p[i+1])){
            pol=pole(&p[i+1]);
            k=i+1;
        }
    }
    return k;
}

float objetosc(const SProstopadloscian &p)
{
    return 0;
}

float znajdz_objetosc(const SProstopadloscian *p, const int n)
{
    return 0;
}

bool wysokosc(const SProstopadloscian &p1, const SProstopadloscian &p2)
{
    return false;
}

void sortuj(SProstopadloscian *p, const int n, bool (*wfun)(const SProstopadloscian &, const SProstopadloscian &))
{
}

void wypisz(const SProstopadloscian *p)
{
}

void wypisz(const SProstopadloscian *p, const int n)
{
}

bool wypisz(const SProstopadloscian &p, ofstream &fout)
{
    return false;
}

bool wypisz(const SProstopadloscian *p, const int n, const string &plik_wyj)
{
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