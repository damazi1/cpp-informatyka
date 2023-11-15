#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class adres
{
    string miasto, ulica;
    int nr_domu;

public:
    adres(const string &m = "brak", const string &u = "brak", int nr = 0) : miasto(m), ulica(u), nr_domu(nr) {}

    bool wczytaj(ifstream &fin)
    {
        fin >> miasto;
        fin >> ulica;
        fin >> nr_domu;
        return 1;
    }

    ostream &view(ostream &out) const
    {
        return out << miasto << " " << ulica << " " << nr_domu << endl;
    }
    friend ostream &operator<<(ostream &out, const adres &r);
};

ostream &operator<<(ostream &out, const adres &r)
{
    return r.view(out);
}

int main(int argc, char *argv[])
try
{
    if (argc != 3)
        throw int(0);
    if (string(argv[1] + (strlen(argv[1]) - 3)) != "txt")
        throw int(1);
    if (string(argv[2] + (strlen(argv[2]) - 3)) != "txt")
        throw int(1);

    ifstream file(argv[1]);
    ofstream fout(argv[2]);
    if (!file)
        throw int(2);
    {
        adres a1;

        if (a1.wczytaj(file))
        {
            cout << a1;
            fout << a1;
        }

        fout.close();
        file.close();
    }

    adres *wsk = new adres("Częstochowa","Dąbrowskiego",73);
    cout<<wsk<<endl;
    cout<<*wsk<<"\n/**************/"<<endl;
    adres a2(*wsk);
    delete wsk;
    wsk=nullptr;

    const adres* wsk1 = new adres("Łódź", "Piotrkowska", 33);

    cout<<a2;
    cout << *wsk1 << '\n';
    adres a3;
    cout<<a3<<endl;
    a3=a2;
    cout<<a3<<endl;
    delete wsk1;
    return 0;
}
catch (int err)
{
    switch (err)
    {
    case 0:
        cout << err << " Za mało argumentów wywołania programu(3)" << endl;
        break;
    case 1:
        cout << err << " Plik powinien mieć format txt" << endl;
        break;
    case 2:
        cout << err << " Nie znaleziono pliku o podanej nazwie" << endl;
        break;
    }
}
catch (...)
{
    cout << "Nieznana sytuacja wyjątkowa.\n";
}