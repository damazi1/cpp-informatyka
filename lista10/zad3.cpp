#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <iomanip>

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
            fin >> konta[i].id;
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

SKonto *dodajTransakcje(SKonto *konta, int &n, const string &nr_konta, const string &imie, const string &nazwisko, int id_transakcji, const string &data, double kwota)
{

    SKonto *konto = new SKonto[n + 1];
    for (int i = 0; i < n; i++)
    {
        konto[i].numerkonta = konta[i].numerkonta;
        konto[i].imie = konta[i].imie;
        konto[i].nazwisko = konta[i].nazwisko;
        konto[i].id = konta[i].id;
        konto[i].data = konta[i].data;
        konto[i].kwota = konta[i].kwota;
    }
    konto[n].numerkonta = nr_konta;
    konto[n].imie = imie;
    konto[n].nazwisko = nazwisko;
    konto[n].id = id_transakcji;
    konto[n].data = data;
    konto[n].kwota = kwota;
    n++;
    return konto;
}

string losuj(int min = 0, int max = 9)
{
    int liczba = rand() % max + 1;
    string wylosowana = to_string(liczba);
    return wylosowana;
}

void wypisz(const SKonto *konta, const int n)
{
    if (konta)
    {
        for (int i = 0; i < n; i++)
        {
            cout << setw(10);
            cout << konta[i].numerkonta << '\t';
            cout << konta[i].imie << '\t';
            cout << konta[i].nazwisko << '\t';
            cout << konta[i].id << '\t';
            cout << konta[i].data << '\t';
            cout << setprecision(2);
            cout << fixed;
            cout << konta[i].kwota << '\n';
        }
    }
}

bool wypisz(const string plik_wyj, const SKonto *konta, const int n)
{
    ofstream fout = otworz1(plik_wyj);
    sprawdz(fout);
    if (fout.good())
    {
        for (int i = 0; i < n; i++)
        {
            sprawdz(fout);
            fout << konta[i].numerkonta << '\t';
            sprawdz(fout);
            fout << konta[i].imie << '\t';
            sprawdz(fout);
            fout << konta[i].nazwisko << '\t';
            sprawdz(fout);
            fout << konta[i].id << '\t';
            sprawdz(fout);
            fout << konta[i].data << '\t';
            sprawdz(fout);
            fout << konta[i].kwota << '\n';
        }

        return true;
    }
    zamknij(fout);
    return false;
}

bool wypisz(const char *plik_wyj, const SKonto *konta, const int n, const string nr_konta)
{
    ofstream fout = otworz1(plik_wyj);
    sprawdz(fout);
    if (fout.good())
    {
        for (int i = 0; i < n; i++)
        {
            if (konta[i].numerkonta == nr_konta)
            {
                sprawdz(fout);
                fout << konta[i].numerkonta << '\t';
                sprawdz(fout);
                fout << konta[i].imie << '\t';
                sprawdz(fout);
                fout << konta[i].nazwisko << '\t';
                sprawdz(fout);
                fout << konta[i].id << '\t';
                sprawdz(fout);
                fout << konta[i].data << '\t';
                sprawdz(fout);
                fout << konta[i].kwota << '\n';
                zamknij(fout);
                return true;
            }
        }
    }
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
    srand(time(NULL));
    SKonto *konta = nullptr, *nowe_konto = nullptr;
    int n = 0;
    if (wczytaj(argv[1], konta, n))
    {
        wypisz(konta, n);
        string los = losuj();
        nowe_konto = dodajTransakcje(konta, n, los, "Kalina", "Czerwiec", 1, "2023/02/20", 123000);
        wypisz(nowe_konto, n);
        wypisz(argv[2], nowe_konto, n);
        string nr_konta = "4556400001";
        wypisz(argv[2], nowe_konto, n, nr_konta);
        usun(konta);
        usun(nowe_konto);
    }
    return 0;
}