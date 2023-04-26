#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct SCzas
{
    int dzien, miesiac, rok, godzina, minuta, sekunda;
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

bool wczytaj(SCzas *&daty, int &n, const char *plik_wej)
{
    string plik_w = plik_wej;
    ifstream fin = otworz(plik_w);
    sprawdz(fin);
    fin >> n;
    daty = new SCzas[n];
    sprawdz(fin);
    if (fin.good())
    {
        for (int i = 0; i < n; i++)
        {
            sprawdz(fin);
            fin >> daty[i].dzien;
            sprawdz(fin);
            fin >> daty[i].miesiac;
            sprawdz(fin);
            fin >> daty[i].rok;
            sprawdz(fin);
            fin >> daty[i].godzina;
            sprawdz(fin);
            fin >> daty[i].minuta;
            sprawdz(fin);
            fin >> daty[i].sekunda;
        }
        zamknij(fin);
        return true;
    }
    zamknij(fin);
    return false;
}

unsigned long ileDni(const SCzas &data)
{
    time_t now = time(nullptr);
    tm data_tm = {0};
    data_tm.tm_year = data.rok - 1900;
    data_tm.tm_mon = data.miesiac - 1;
    data_tm.tm_mday = data.dzien;
    time_t dataa = mktime(&data_tm);
    unsigned long timediff = difftime(now, dataa);
    unsigned long days = timediff / (60 * 60 * 24);
    return days;
}

bool zapisz(const SCzas *daty, const int n, const char *plik_wyj)
{
    string plik_w = plik_wyj;
    ofstream fout = otworz1(plik_w);
    sprawdz(fout);
    if (fout.good())
    {
        for (int i = 0; i < n; i++)
        {
            sprawdz(fout);
            fout << ileDni(daty[i]) << ";\n";
        }
        zamknij(fout);
        return true;
    }
    zamknij(fout);
    return false;
}
bool zapisz(const SCzas &data)
{
    if (data.dzien)
    {
        cout << data.dzien << endl;
        cout << data.miesiac << endl;
        cout << data.rok << endl;
        cout << data.godzina << endl;
        cout << data.minuta << endl;
        cout << data.sekunda << endl;
        return true;
    }
    return false;
}
bool zapisz(const SCzas *data, const string &plik_wyj)
{
    ofstream fout = otworz1(plik_wyj);
    sprawdz(fout);
    if (fout.good())
    {
        sprawdz(fout);
        fout << data->godzina << '\t';
        sprawdz(fout);
        fout << data->minuta << '\t';
        sprawdz(fout);
        fout << data->sekunda << '\n';
        zamknij(fout);
        return true;
    }
    zamknij(fout);
    return false;
}

void usun(SCzas *data)
{
    if (data)
    {
        delete[] data;
        data = nullptr;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Podano niewłaściwą ilośc argumentów(3)" << endl;
        cout << "Poprawny zapis to ./nazwa plik_wej plik_wyj" << endl;
        return -1;
    }
    SCzas *daty = nullptr;
    int n = 0;
    if (wczytaj(daty, n, argv[1]))
    {
        for (int i = 0; i < n; i++)
        {
            if (!zapisz(daty[i]))
                cout << "Wyswietlenie i" << i << "-tej daty nie udalo sie"
                     << endl;
            if (!zapisz(&daty[i], argv[2]))
                cout << "Zapisanie do pliku i" << i << "-tej daty nie udalo sie"
                     << endl;
        }
        unsigned long roznicaDni = ileDni(daty[0]);
        cout << "Liczba dni od wybranej daty wynosi: " << roznicaDni << endl;
        if (!zapisz(daty, n, argv[2]))
            cout << "Zapisanie tablicy dat do pliku nie udalo sie" << endl;
        usun(daty);
    }
    else
    {
        cerr << "Cos poszlo nie tak!" << endl;
    }
    return 0;
}