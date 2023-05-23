#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct SOsoba
{
    int id, rok;
    string email, imie;

    SOsoba()
    {
        id = 0;
        email = "";
        rok = 0;
        imie = "";
    }
    ~SOsoba()
    {
        id = 0;
        email = "";
        rok = 0;
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
    };
    ~SLista()
    {
        nazwa = "";
        n = 0;
        if (osoba)
        {
            delete[] osoba;
            osoba = nullptr;
        }
    };
    bool wczytaj(ifstream &);
    bool wypisz(ostream &out = cout);
    SOsoba szukaj(const unsigned int);
    void podzial(ofstream &, ofstream &);
};

int main(int argc,char **argv)
{
    if(argc!=5){
        cerr<<"Podano błędną ilość argumentów (5)"<<endl;
        cout<<"Poprawny zapis to ./nazwa plik_wej plik_wyj1 plik_wyj2 id"<<endl;
        return 1;
    }
    SLista lista;
    ifstream fin;
    ofstream fout1, fout2;
    fin.open(argv[1]);
    fout1.open(argv[2]);
    fout2.open(argv[3]);
    if (!fin.good() && !fout1.good() && !fout2.good()){
        cerr<<"Błąd podczas otwierania plików"<<endl;
        fin.clear();
        fin.close();
        fout1.clear();
        fout1.close();
        fout2.clear();
        fout2.close();
        return 2;
    }
    if(lista.wczytaj(fin)){
        if(lista.wypisz()){
            SOsoba osoba=lista.szukaj(atoi(argv[4]));
            lista.podzial(fout1,fout2);
        }
    }
    fin.close();
    fout1.close();
    fout2.close();
        return 0;
}

SOsoba SOsoba::wczytaj(ifstream &fin)
{
    SOsoba osoba;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejściowym fin we wczytaj" << endl;
        fin.clear();
        fin.close();
        return SOsoba();
    }
    fin >> osoba.id;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejściowym fin we wczytaj" << endl;
        fin.clear();
        fin.close();
        return SOsoba();
    }
    fin >> osoba.email;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejściowym fin we wczytaj" << endl;
        fin.clear();
        fin.close();
        return SOsoba();
    }
    fin >> osoba.rok;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejściowym fin we wczytaj" << endl;
        fin.clear();
        fin.close();
        return SOsoba();
    }
    fin >> osoba.imie;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejściowym fin we wczytaj" << endl;
        fin.clear();
        fin.close();
        return SOsoba();
    }
    return osoba;
}

bool SOsoba::wypisz(ostream &out)
{
    if (!out.good())
    {
        cerr << "Błąd na strumieniu wyjściowym we wypisz" << endl;
        out.clear();
        return false;
    }
    out << id << '\t' << email << '\t' << rok << '\t' << imie << endl;
    if (!out.good())
    {
        cerr << "Błąd na strumieniu wyjściowym we wypisz" << endl;
        out.clear();
        return false;
    }
    return true;
}

bool SLista::wczytaj(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia we wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin >> nazwa;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia we wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin >> n;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia we wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    if (n == 0)
    {
        osoba = nullptr;
        cout << "Brak osób na liście " << endl;
        return true;
    }
    if (n < 0)
    {
        cerr << "Liczba osób nie może być ujemna";
        fin.clear();
        fin.close();
        return false;
    }
    else
    {
        osoba = new SOsoba[n];
        for (int i = 0; i < n; i++)
        {
            osoba[i] = osoba[i].wczytaj(fin);
        }
    }
    return true;
}

bool SLista::wypisz(ostream &out)
{
    if (!out.good())
    {
        cerr << "Błąd na strumieniu wyjścia we wypisz" << endl;
        out.clear();
        return false;
    }
    out << nazwa << '\n'
        << n << '\n';
    for (int i = 0; i < n; i++)
    {
        osoba[i].wypisz(out);
    }
    if (!out.good())
    {
        cerr << "Błąd na strumieniu wyjścia we wypisz" << endl;
        out.clear();
        return false;
    }
    return true;
}

SOsoba SLista::szukaj(const unsigned int id)
{
    for (int i = 0; i < n; i++)
    {
        if (osoba[i].id == id)
        {
            osoba[i].wypisz();
            return osoba[i];
        }
    }
    return SOsoba();
}
void SLista::podzial(ofstream &fout1, ofstream &fout2)
{
    if (!fout1.good() && !fout2.good())
    {
        cerr << "błąd na strumieniu wyjścia w podzizal" << endl;
        fout1.clear();
        fout1.close();
        fout2.clear();
        fout2.close();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int m = osoba[i].imie.length();
        if (osoba[i].imie[m - 1] == 'a')
        {
            if (!osoba[i].wypisz(fout1))
            {
                cerr << "Błąd podczas dzielenia osób na płcie" << endl;
                fout1.clear();
                fout1.close();
                fout2.clear();
                fout2.close();
                return;
            }
        }
        else
        {
            if (!osoba[i].wypisz(fout2))
            {
                cerr << "Błąd podczas dzielenia osób na płcie" << endl;
                fout1.clear();
                fout1.close();
                fout2.clear();
                fout2.close();
                return;
            }
        }
    }
}