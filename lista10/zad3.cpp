#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

struct SKonto
{
    string numerkonta;
    string imie, nazwisko;
    int id;
    string data;
    double kwota;
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

bool wczytaj(const char *plik_wyj, SKonto *&konta, int &n) // o co chodzi z tym wskaźnikiem na konta ? 
{
    string plik_wej = plik_wyj;
    ifstream fin = otworz(plik_wej);
    sprawdz(fin);
    fin >> n;
    konta = new SKonto[n];
    sprawdz(fin);
    if (fin.good())
    {
        for (int i = 0; i < n; i++)
        {
            sprawdz(fin);
            fin >> konta[i].numerkonta;
            sprawdz(fin);
            fin >> konta[i].imie;
            sprawdz(fin);
            fin >> konta[i].nazwisko;
            sprawdz(fin);
            fin >>konta[i].id;
            sprawdz(fin);
            fin >> konta[i].data;
            sprawdz(fin);
            fin >> konta[i].kwota;
        }
        zamknij(fin);
        return true;
    }
    zamknij(fin);
    return false;
}

void dodajTransakcje(SKonto *konta, int &n, const string &nr_konta, const string &imie, const string &nazwisko, int id_transakcji, const string &data, double kwota)
{
    n++;
    konta[n-1].numerkonta=nr_konta;
    konta[n-1].imie=imie;
    konta[n-1].nazwisko=nazwisko;
    konta[n-1].id=id_transakcji;
    konta[n-1].data=data;
    konta[n-1].kwota=kwota;
    return &konta[n-1];
}

string losuj(int min = 0, int max = 9)
{
    return "Kox";
}

void wypisz(const SKonto *konta, const int n)
{
}

bool wypisz(const string plik_wyj, const SKonto *konta, const int n)
{
    return false;
}

bool wypisz(const char *plik_wyj, const SKonto *konta, const int n, const string nr_konta)
{
    return false;
}

void usun(SKonto *konto)
{
    if (konto)
    {
        delete[] konto;
        konto = nullptr;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Podano błędną ilość argumentów(3)" << endl;
        cout << "Poprawny zapis to ./nazwa plik_wej plik_wyj" << endl;
        return -1;
    }
    SKonto *konta = nullptr, *nowe_konto = nullptr;
    int n = 0;
    if (wczytaj(argv[1], konta, n))
    {
        wypisz(konta, n);
        string los = losuj();
        nowe_konto = dodajTransakcje(konta, n, los, "Kalina","Czerwiec", 1, "2023/02/20", 123000);
        wypisz(nowe_konto, n);
        wypisz(argv[2], nowe_konto, n);
        string nr_konta = "4556400001";
        wypisz(argv[2], nowe_konto, n, nr_konta);
        usun(konta);
        usun(nowe_konto);
    }
    return 0;
}