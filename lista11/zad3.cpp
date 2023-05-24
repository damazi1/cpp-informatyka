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
    SStudent szukaj(string);
};

int main(int argc,char **argv)
{
    if (argc!=2){
        cerr<<"Podano bledna ilosc argumentow (2)"<<endl;
        cout<< "Poprawny zapis to ./nazwa plik_wejsciowy"<<endl;
        return -1;
    }
    ifstream fin;
    SLista lista;
    fin.open(argv[1]);
    if (lista.wczytaj(fin))
    {
        if (lista.wypisz())
        {
            cout << "Srednia niezaliczonych przedmiotow wynosi :" << lista.srednia() << endl;
            SStudent student = lista.maksymalna();
            cout << "Student z najwieksza iloscia niezaliczonych przedmiotow to : " << endl;
            if(!student.wypisz()){
                cerr<<"Błąd podczas wypisywania z pliku dla studenta "<<endl;
            }

            SStudent student1 = lista.szukaj("Jan");
            if(!student1.wypisz()){
                cerr<<"Błąd podczas wypisywania z pliku dla studenta "<<endl;
            }
        }
        else
        {
            cerr << "błąd podczas wypisywania z pliku " << endl;
            fin.clear();
            fin.close();
            return 1;
        }
    }
    else
    {
        cerr << "błąd podczas wczytywania do pliku " << endl;
        fin.clear();
        fin.close();
        return 1;
    }
    fin.close();
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
        if (n == 0)
        {
            wykaz_niezaliczonych_k = nullptr;
            return true;
        }
        else if (n < 0 && n > 1000)
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
        for (int i = 0; i < n; i++)
        {
            out << wykaz_niezaliczonych_k[i] << " ";
        }
        out << endl;
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

bool SLista::wczytaj(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "Blad na strumieniu wejscia Wczytaj dla SLista" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    if (fin.good())
    {
        fin >> nazwa;
        if (!fin.good())
        {
            cerr << "Blad na strumieniu wejscia Wczytaj dla SLista" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        fin >> n;
        if (n < 1 && n > 1000)
        {
            cerr << "Podana liczba wychodzi poza zakres (1-1000)" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        if (!fin.good())
        {
            cerr << "Blad na strumieniu wejscia Wczytaj dla SLista" << endl;
            fin.clear();
            fin.close();
            return false;
        }
        student = new SStudent[n];
        for (int i = 0; i < n; i++)
        {
            student[i].wczytaj(fin);
            if (!fin.good())
            {
                cerr << "Blad na strumieniu wejscia Wczytaj dla SLista" << endl;
                fin.clear();
                fin.close();
                return false;
            }
        }
        return true;
    }
    if (!fin.good())
    {
        cerr << "Blad na strumieniu wejscia Wczytaj dla SLista" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    return false;
}

bool SLista::wypisz(ostream &out)
{
    if (!out.good())
    {
        cerr << "Błąd na strumieniu wyjściowym wypisz dla SLista" << endl;
        out.clear();
        return false;
    }
    if (out.good())
    {
        out << nazwa << endl;
        if (!out.good())
        {
            cerr << "Błąd na strumieniu wyjściowym wypisz dla SLista" << endl;
            out.clear();
            return false;
        }
        out << n << endl;
        if (!out.good())
        {
            cerr << "Błąd na strumieniu wyjściowym wypisz dla SLista" << endl;
            out.clear();
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            student[i].wypisz(out);
            if (!out.good())
            {
                cerr << "Błąd na strumieniu wyjściowym wypisz dla SLista" << endl;
                out.clear();
                return false;
            }
        }
        return true;
    }
    if (!out.good())
    {
        cerr << "Błąd na strumieniu wyjściowym wypisz dla SLista" << endl;
        out.clear();
        return false;
    }
    return false;
}

double SLista::srednia()
{
    double srednia = 0;
    double liczba_st = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < student[i].n; j++)
        {
            srednia++;
        }
        liczba_st++;
    }
    return srednia / liczba_st;
}

SStudent SLista::maksymalna()
{
    int max = 0;
    int stu = 0;
    for (int i = 0; i < n; i++)
    {
        if (student[i].n > max)
        {
            max = student[i].n;
            stu = i;
        }
    }
    SStudent pn;
    pn.imie = student[stu].imie;
    pn.nazwisko = student[stu].nazwisko;
    pn.n = student[stu].n;
    pn.wykaz_niezaliczonych_k = new string[pn.n];
    for (int i = 0; i < pn.n; i++)
    {
        pn.wykaz_niezaliczonych_k[i] = student[stu].wykaz_niezaliczonych_k[i];
    }
    return pn;
}

SStudent SLista::szukaj (string imie){
    int m=0;
    for(int i=0;i<n;i++){
        if(student[i].imie==imie){
            m=i;
            break;
        }
    }
    SStudent pn;
    pn.imie=student[m].imie;
    pn.nazwisko=student[m].nazwisko;
    pn.n=student[m].n;
    pn.wykaz_niezaliczonych_k=new string [pn.n];
    for (int i=0;i<pn.n;i++){
        pn.wykaz_niezaliczonych_k[i]=student[m].wykaz_niezaliczonych_k[i];
    }
    return pn;
}