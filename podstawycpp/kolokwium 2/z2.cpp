#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

struct SCzas
{
    int dzien, miesiac, rok, godzina, minuta, sekunda;
    SCzas()
    {
        dzien = 0;
        miesiac = 0;
        rok = 0;
        godzina = 0;
        minuta = 0;
        sekunda = 0;
    }
    ~SCzas()
    {
        dzien = 0;
        miesiac = 0;
        rok = 0;
        godzina = 0;
        minuta = 0;
        sekunda = 0;
    }
};

bool wczytaj(SCzas *&daty, int &n, const char *plik_wej)
{
    ifstream fin;
    fin.open(plik_wej);
    if (!fin.good())
    {
        cerr << "Wystapił błąd na strumieniu wejścia fin w funkcji wczytaj\n";
        fin.clear();
        fin.close();
        return false;
    }
    fin >> n;
    if (!fin.good())
    {
        cerr << "Wystapił błąd na strumieniu wejścia fin w funkcji wczytaj\n";
        fin.clear();
        fin.close();
        return false;
    }
    if (n > 0)
    {
        daty = new SCzas[n];
    }
    else
    {
        cerr << "musisz podać co najmniej 1 date (n<1)" << endl;
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        fin >> daty[i].dzien;
        if (!fin.good())
        {
            cerr << "Wystapił błąd na strumieniu wejścia fin w funkcji wczytaj\n";
            fin.clear();
            fin.close();
            return false;
        }
        fin >> daty[i].miesiac;
        if (!fin.good())
        {
            cerr << "Wystapił błąd na strumieniu wejścia fin w funkcji wczytaj\n";
            fin.clear();
            fin.close();
            return false;
        }
        fin >> daty[i].rok;
        if (!fin.good())
        {
            cerr << "Wystapił błąd na strumieniu wejścia fin w funkcji wczytaj\n";
            fin.clear();
            fin.close();
            return false;
        }
        fin >> daty[i].godzina;
        if (!fin.good())
        {
            cerr << "Wystapił błąd na strumieniu wejścia fin w funkcji wczytaj\n";
            fin.clear();
            fin.close();
            return false;
        }
        fin >> daty[i].minuta;
        if (!fin.good())
        {
            cerr << "Wystapił błąd na strumieniu wejścia fin w funkcji wczytaj\n";
            fin.clear();
            fin.close();
            return false;
        }
        fin >> daty[i].sekunda;
        if (!fin.good())
        {
            cerr << "Wystapił błąd na strumieniu wejścia fin w funkcji wczytaj\n";
            fin.clear();
            fin.close();
            return false;
        }
    }
    fin.close();
    return true;
}

unsigned long iledni(const SCzas &data)
{
    time_t teraz = time(nullptr);
    tm data_tm = {0};
    data_tm.tm_year = data.rok - 1900;
    data_tm.tm_mon = data.miesiac - 1;
    data_tm.tm_mday = data.dzien;
    unsigned long dni = (difftime(teraz, time_t(mktime(&data_tm)))) / (60 * 60 * 24);
    return dni;
}

bool zapisz(const SCzas *daty, const int n, const char *plik_wyj)
{
    ofstream fout;
    fout.open(plik_wyj,ios::app);
    if (!fout.good())
    {
        cerr << "Błąd na strumieniu wyjścia w zapisz" << endl;
        fout.clear();
        fout.close();
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        fout << iledni(daty[i])<<"\t";
        if (!fout.good())
        {
            cerr << "Błąd na strumieniu wyjścia w zapisz" << endl;
            fout.clear();
            fout.close();
            return false;
        }
    }
    fout.close();
    return true;
}

bool zapisz(const SCzas &data)
{
    if (cout << data.dzien << "\t" << data.miesiac << "\t" << data.rok << "\t" << data.godzina << "\t" << data.minuta << "\t" << data.sekunda << endl)
    {
        return true;
    }
    return false;
}

bool zapisz(const SCzas *data, const string &plik_wyj)
{
    ofstream fout;
    fout.open(plik_wyj,ios::app);
    if (!fout.good())
    {
        cerr << "Błąd na strumieniu wyjścia w zapisz" << endl;
        fout.clear();
        fout.close();
        return false;
    }
    fout<<data->godzina<<"\t";
    if (!fout.good())
    {
        cerr << "Błąd na strumieniu wyjścia w zapisz" << endl;
        fout.clear();
        fout.close();
        return false;
    }
    fout<<data->minuta<<"\t";
    if (!fout.good())
    {
        cerr << "Błąd na strumieniu wyjścia w zapisz" << endl;
        fout.clear();
        fout.close();
        return false;
    }
    fout<<data->sekunda<<"\n";
    fout.close();
    return true;
}
void usun(SCzas* daty){
    if(daty){
        delete [] daty;
        daty=nullptr;
    }
}
int main(int argc, char **argv)
{
    if(argc!=3){
        cerr<<"Podano błedna ilosc argumentów(3)"<<endl;
        cout<<"Poprawny zapis to ./nazwa plik_wej plik_wyj"<<endl;
        return 1;
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
        unsigned long roznicaDni = iledni(daty[0]);
        cout << "Liczba dni od wybranej daty wynosi: " << roznicaDni << endl;
        if (!zapisz(daty, n, argv[2]))
            cout << "Zapisanie tablicy dat do pliku nie udalo sie" << endl;
    }
    else
    {
        cerr << "Cos poszlo nie tak!" << endl;
    }
    usun(daty);
    return 0;
}