#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct SStudent
{
    string imie, nazwisko;
    int n;
    string *wykaz_niezaliczonych_k;

    SStudent()
    {
        imie = "";
        nazwisko = "";
        n = 0;
        wykaz_niezaliczonych_k = nullptr;
    }
    ~SStudent()
    {
        imie = "";
        nazwisko = "";
        n = 0;
        if (wykaz_niezaliczonych_k)
        {
            delete[] wykaz_niezaliczonych_k;
            wykaz_niezaliczonych_k = nullptr;
        }
    }

    bool wczytaj(ifstream &);
    bool wypisz(ostream &out = cout);
};

struct SLista
{
    string nazwa;
    int n;
    SStudent *student;

    SLista()
    {
        nazwa = "";
        n = 0;
        student = nullptr;
    }
    ~SLista()
    {
        nazwa = "";
        n = 0;
        if (student)
        {
            delete[] student;
            student = nullptr;
        }
    }
    bool wczytaj(ifstream &);
    bool wypisz(ostream &out = cout);
    double srednia();
    SStudent maksymalna();
};

int main()
{

    return 0;
}

bool SStudent::wczytaj(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "Blad podczas wczytywania danych z pliku dla SSstudent" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    if (fin.good())
    {
        fin >> imie;
        if (!fin.good())
        {
            cerr << "Blad podczas wczytywania danych z pliku dla SSstudent imie" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> nazwisko;
        if (!fin.good())
        {
            cerr << "Blad podczas wczytywania danych z pliku dla SSstudent nazwisko" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> n;
        if(n==0){
            wykaz_niezaliczonych_k=nullptr;
        }
        elif (n < 0 && n > 1000)
        {
            cerr << "Podana liczba wychodzi poza zakres (1-1000)";
            fin.clear();
            fin.close();
            return false;
        }
        if (!fin.good())
        {
            cerr << "Blad podczas wczytywania danych z pliku dla SSstudent liczba" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        wykaz_niezaliczonych_k = new string[n];
        for (int i = 0; i < n; i++)
        {
            fin >> wykaz_niezaliczonych_k[i];
            if (!fin.good())
            {
                cerr << "Blad podczas wczytywania danych z pliku dla SSstudent przedmioty" << endl;
                fin.clear();
                fin.close();
                return false;
            }
        }
        return true;
    }
    if (!fin.good())
    {
        cerr << "Blad podczas wczytywania danych z pliku dla SSstudent koniec" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    return false;
}

bool SStudent::wypisz(ostream &out)
{
    if (!out.good())
    {
        cerr << "Blad na strumieniu Wyjsciowym wypisz dla SStudent" << endl;
        out.clear();
        return false;
    }
    if (out.good())
    {
        out << imie << " ";
        if (!out.good())
        {
            cerr << "Blad na strumieniu Wyjsciowym wypisz dla SStudent" << endl;
            out.clear();
            return false;
        }
        out << nazwisko << " ";
        if (!out.good())
        {
            cerr << "Blad na strumieniu Wyjsciowym wypisz dla SStudent" << endl;
            out.clear();
            return false;
        }
        out << n << " ";
        if (!out.good())
        {
            cerr << "Blad na strumieniu Wyjsciowym wypisz dla SStudent" << endl;
            out.clear();
            return false;
        }
        out << wykaz_niezaliczonych_k << endl;
        if (!out.good())
        {
            cerr << "Blad na strumieniu Wyjsciowym wypisz dla SStudent" << endl;
            out.clear();
            return false;
        }
        return true;
    }
    if (!out.good())
    {
        cerr << "Blad na strumieniu Wyjsciowym wypisz dla SStudent" << endl;
        out.clear();
        return false;
    }
    return false;
}

bool SLista::wczytaj(ifstream& fin){
    if(!fin.good()){
        cerr<<"Blad na strumieniu wejscia Wczytaj dla SLista"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    if(fin.good()){
        fin>>nazwa;
        if(!fin.good()){
        cerr<<"Blad na strumieniu wejscia Wczytaj dla SLista"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin>>n;
    if(n<1&&n>1000){
        cerr<<"Podana liczba wychodzi poza zakres (1-1000)"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    if(!fin.good()){
        cerr<<"Blad na strumieniu wejscia Wczytaj dla SLista"<<endl;
        fin.clear();
        fin.close();
        return false;
    }
    }
}