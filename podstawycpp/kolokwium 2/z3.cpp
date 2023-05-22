#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

struct SKonto
{
    string numer_konta;
    string imie, nazwisko;
    int id;
    string data;
    double kwota;

    SKonto()
    {
        numer_konta = "";
        imie = "";
        nazwisko = "";
        id = 0;
        data = "";
        kwota = 0;
    }
    ~SKonto()
    {
        numer_konta = "";
        imie = "";
        nazwisko = "";
        id = 0;
        data = "";
        kwota = 0;
    }
};

bool wczytaj(const char *plik_wej, SKonto *&konta, int &n)
{
    ifstream fin;
    fin.open(plik_wej);
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejściowym w funkcji wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin >> n;
    if (n > 0)
    {
        konta = new SKonto[n];
    }
    else
    {
        cerr << "Podana liczba kont jest błędna " << endl;
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        fin >> konta[i].numer_konta;
        if (!fin.good())
        {
            cerr << "Błąd na strumieniu wejściowym w funkcji wczytaj" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> konta[i].imie;
        if (!fin.good())
        {
            cerr << "Błąd na strumieniu wejściowym w funkcji wczytaj" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> konta[i].nazwisko;
        if (!fin.good())
        {
            cerr << "Błąd na strumieniu wejściowym w funkcji wczytaj" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> konta[i].id;
        if (!fin.good())
        {
            cerr << "Błąd na strumieniu wejściowym w funkcji wczytaj" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> konta[i].data;
        if (!fin.good())
        {
            cerr << "Błąd na strumieniu wejściowym w funkcji wczytaj" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> konta[i].kwota;
        if (!fin.good())
        {
            cerr << "Błąd na strumieniu wejściowym w funkcji wczytaj" << endl;
            fin.clear();
            fin.close();
            return false;
        }
    }
    return true;
}

SKonto *dodajTransakcje(SKonto *&konta, int &n, const string &nr_konta, const string &imie, const string &nazwisko, int id_transakcji, const string &data, double kwota)
{
    n++;
    SKonto *nowekonto = new SKonto[n];
    for(int i=0;i<n-1;i++){
        nowekonto[i].numer_konta=konta[i].numer_konta;
        nowekonto[i].imie=konta[i].imie;
        nowekonto[i].nazwisko=konta[i].nazwisko;
        nowekonto[i].id=konta[i].id;
        nowekonto[i].data=konta[i].data;
        nowekonto[i].kwota=konta[i].kwota;
    }
    nowekonto[n - 1].numer_konta = nr_konta;
    nowekonto[n - 1].imie = imie;
    nowekonto[n - 1].nazwisko = nazwisko;
    nowekonto[n - 1].id = id_transakcji;
    nowekonto[n - 1].data = data;
    nowekonto[n - 1].kwota = kwota;
    return nowekonto;
}

string losuj(const int min = 0, const int max = 9)
{
    if (max > min)
    {
        int los = rand() % (max - min + 1) + min;
        string losa = to_string(los);
        return losa;
    }
    if (max == min)
    {
        return to_string(min);
    }
    cerr << "Wartość maksymalna musi być mniejsza od wartości minimalnej" << endl;
    return "";
}

void wypisz(const SKonto *konta, const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setfill('0') << setw(10);
        cout << konta[i].numer_konta ;
        cout<< "\t" << konta[i].imie << "\t" << konta[i].nazwisko << "\t" << konta[i].id << "\t" << konta[i].data << "\t";
        cout << fixed << setprecision(2);
        cout << konta[i].kwota << '\n';
    }
}

bool wypisz(const string plik_wyj, const SKonto *konta, const int n)
{
    ofstream fout;
    fout.open(plik_wyj);
    if (!fout.good())
    {
        cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
        fout.clear();
        fout.close();
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        fout << konta[i].numer_konta;
        if (!fout.good())
        {
            cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
            fout.clear();
            fout.close();
            return false;
        }
        fout << konta[i].imie;
        if (!fout.good())
        {
            cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
            fout.clear();
            fout.close();
            return false;
        }
        fout << konta[i].nazwisko;
        if (!fout.good())
        {
            cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
            fout.clear();
            fout.close();
            return false;
        }
        fout << konta[i].id;
        if (!fout.good())
        {
            cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
            fout.clear();
            fout.close();
            return false;
        }
        fout << konta[i].data;
        if (!fout.good())
        {
            cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
            fout.clear();
            fout.close();
            return false;
        }
        fout << konta[i].kwota;
        if (!fout.good())
        {
            cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
            fout.clear();
            fout.close();
            return false;
        }
    }
    fout.close();
    return true;
}

bool wypisz(const char *plik_wyj, const SKonto *konta, const int n, const string nr_konta)
{
    ofstream fout;
    fout.open(plik_wyj);
    if (!fout.good())
    {
        cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
        fout.clear();
        fout.close();
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        if (konta[i].numer_konta == nr_konta)
        {
            fout << konta[i].numer_konta;
            if (!fout.good())
            {
                cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
                fout.clear();
                fout.close();
                return false;
            }
            fout << konta[i].imie;
            if (!fout.good())
            {
                cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
                fout.clear();
                fout.close();
                return false;
            }
            fout << konta[i].nazwisko;
            if (!fout.good())
            {
                cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
                fout.clear();
                fout.close();
                return false;
            }
            fout << konta[i].id;
            if (!fout.good())
            {
                cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
                fout.clear();
                fout.close();
                return false;
            }
            fout << konta[i].data;
            if (!fout.good())
            {
                cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
                fout.clear();
                fout.close();
                return false;
            }
            fout << konta[i].kwota;
            if (!fout.good())
            {
                cerr << "Błąd na strumieniu wyjściowym w wypisz" << endl;
                fout.clear();
                fout.close();
                return false;
            }
            fout.close();
            return true;
        }
    }
    cout << "Brak konta o podanym numerze" << endl;
    fout.close();
    return false;
}

void usun(SKonto* konto){
    if(konto){
        delete [] konto;
        konto = nullptr;
    }
}

int main(int argc,char **argv)
{
    if(argc!=3){
        cerr<<"Podano błędną ilość argumentów (3)"<<endl;
        cout<<"Poprawny zapis to ./nazwa plik_wej plik_wyj"<<endl;
        return 1;
    }

    srand(time(NULL));
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
    }
    usun(konta);
    usun(nowe_konto);

    return 0;
}
