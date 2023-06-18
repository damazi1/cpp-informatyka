#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct SStudent
{
    string imie, nazwisko;
    string *wykaz;
    int liczba;

    SStudent()
    {
        imie = "";
        nazwisko = "";
        wykaz = nullptr;
        liczba = 0;
    }
    ~SStudent()
    {
        imie = "";
        liczba = 0;
    }
    bool wczytaj(ifstream &);
    bool wypisz(ostream &out = cout);
};

struct SLista
{
    string nazwa;
    int liczba;
    SStudent *student;

    SLista()
    {
        nazwa = "";
        liczba = 0;
        student = nullptr;
    }
    ~SLista()
    {
        nazwa = "";
        for (int i = 0; i < liczba; i++)
        {
            if (student[i].wykaz)
            {
                delete[] student[i].wykaz;
                student[i].wykaz = nullptr;
            }
        }
        if (student){
        delete[] student;
        student = nullptr;
        }

        liczba = 0;
    }
    bool wczytaj(ifstream &fin);
    bool wypisz(ostream &out = cout);
    double srednia(const SLista &);
    SStudent maksymalna();
};

int main()
{

    ifstream fin;
    fin.open("sesja.txt");
    if (!fin.good())
    {
        cerr << "Błąd podczas otwierania pliku wejsciowego" << endl;
        fin.clear();
        fin.close();
        return 1;
    }
    SLista lista;
    if (!lista.wczytaj(fin))
    {
        cerr << "Błąd podczas wczytywania z listy" << endl;
        fin.clear();
        fin.close();
        return 1;
    }
    if (!lista.wypisz())
    {
        cerr << "Błąd podczas wypisywania z listy" << endl;
        fin.clear();
        fin.close();
        return 1;
    }

    double wynik = lista.srednia(lista);
    cout << wynik << endl;

    SStudent student = lista.maksymalna();
    student.wypisz();

    fin.close();
    return 0;
}

bool SStudent::wczytaj(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd podczas otwierania pliku w SStudent wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin >> imie;
    if (!fin.good())
    {
        cerr << "Błąd podczas otwierania pliku w SStudent wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin >> nazwisko;
    if (!fin.good())
    {
        cerr << "Błąd podczas otwierania pliku w SStudent wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin >> liczba;
    if (liczba == 0)
    {
        wykaz = nullptr;
        return true;
    }
    if (liczba < 0)
    {
        cerr << "Liczba osób jest błędna" << endl;
        return false;
    }
    else
    {
        wykaz = new string[liczba];
        for (int i = 0; i < liczba; i++)
        {
            fin >> wykaz[i];
            if (!fin.good())
            {
                cerr << "Błąd podczas otwierania pliku w SStudent wczytaj" << endl;
                fin.clear();
                fin.close();
                return false;
            }
        }
    }
    return true;
}

bool SStudent::wypisz(ostream &out)
{
    if (!out.good())
    {
        cerr << "Błąd na strumieniu wyjscia w SStudent wypisz" << endl;
        out.clear();
        return false;
    }
    out << imie << '\t' << nazwisko << '\t' << liczba << '\t';
    for (int i = 0; i < liczba; i++)
    {
        cout << wykaz[i] << '\t';
    }
    if (!out.good())
    {
        cerr << "Błąd na strumieniu wyjscia w SStudent wypisz" << endl;
        out.clear();
        return false;
    }
    return true;
}

bool SLista::wczytaj(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia w SLista wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin >> nazwa;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia w SLista wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin >> liczba;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu wejścia w SLista wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    if (liczba == 0)
    {
        student = nullptr;
        return true;
    }
    if (liczba < 0)
    {
        cerr << "Niepoprawna ilosc studentow" << endl;
        return false;
    }
    else
    {
        student = new SStudent[liczba];
        for (int i = 0; i < liczba; i++)
        {
            student[i].wczytaj(fin);
        }
    }
    return true;
}

bool SLista::wypisz(ostream &out)
{
    if (!out.good())
    {
        cerr << "Błąd na strumieniu wyjścia w SLista wypisz" << endl;
        out.clear();
        return false;
    }
    out << nazwa << '\n'
        << liczba << endl;
    for (int i = 0; i < liczba; i++)
    {
        if (!student[i].wypisz(out))
        {
            cerr << "Błąd na strumieniu w SLista wypisz w studencie" << endl;
            return false;
        }
        cout << endl;
    }
    return true;
}

double SLista::srednia(const SLista &lista)
{
    int wyn = 0, ile = 0;
    for (int i = 0; i < lista.liczba; i++)
    {
        wyn += lista.student[i].liczba;
        ile++;
    }
    double wynik = wyn / ile;
    return wynik;
}

SStudent SLista::maksymalna()
{
    int max = -1;
    for (int i = 0; i < liczba; i++)
    {
        if (student[i].liczba > max)
        {
            max = i;
        }
    }
    if (max > -1)
    {
        return student[max];
    }
    return SStudent();
}