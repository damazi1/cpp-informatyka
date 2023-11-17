#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

class punkt
{
    double x_, y_;

public:
    punkt(const double &x = 0, const double &y = 0) : x_(x), y_(y) {}
    ~punkt() {}
    double x() const { return x_; }
    double y() const { return y_; }
    double &x() { return x_; }
    double &y() { return y_; }

    double odleglosc(const punkt &p1) const
    {
        double x = this->x() - p1.x();
        double y = this->y() - p1.y();
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    ostream &view(ostream &out) const
    {
        return out << x_ << "\t" << y_ << endl;
    }
    friend ostream &operator<<(ostream &, const punkt &);
};
ostream &operator<<(ostream &out, const punkt &r)
{
    return r.view(out);
}

class wielobok
{
    size_t roz;
    punkt *wsk;

public:
    wielobok() : roz(0), wsk(nullptr) {}
    wielobok(const punkt *pp, const punkt *pk) : roz(pk - pp > 0 ? pk - pp : 0), wsk(roz ? new punkt[roz] : nullptr)
    {
        for (size_t i = 0; i < roz; i++)
        {
            wsk[i] = pp[i];
        }
    }
    wielobok(const wielobok &w)
    {
        roz = w.roz;
        wsk = new punkt[roz];
        for (size_t i = 0; i < roz; i++)
        {
            wsk[i] = w.wsk[i];
        }
    }
    ~wielobok() { delete[] wsk; }
    void read(ifstream &in)
    {
        string buf;
        getline(in, buf);
        if (buf != "WIELKOSC")
            throw string("brak nagłówka \"WIELKOSC\"");
        cout << buf << endl;
        in >> roz;
        cout << roz << endl;
        if (roz > 0)
        {
            wsk = new punkt[roz];
            for (size_t i = 0; i < roz; i++)
            {
                in >> wsk[i].x();
                in >> wsk[i].y();
                cout << i << ")  " << wsk[i].x() << " " << wsk[i].y() << endl;
            }
        }
        else
            throw string("Wielkość tablicy nie może być mniejsza niż 1");
    }

    double obwod() const
    {
        double wynik = 0;
        if (wsk)
        {
            for (size_t i = 0; i < roz - 1; i++)
            {
                wynik += wsk[i].odleglosc(wsk[i + 1]);
            }
            wynik += wsk[roz - 1].odleglosc(wsk[0]);
        }
        return wynik;
    }

    punkt &operator[](size_t i)
    {
        return wsk[i];
    }
    wielobok &operator=(const wielobok &r)
    {
        if (this != &r)
        {
            roz = r.roz;
            wsk = new punkt[roz];
            for (size_t i = 0; i < roz; i++)
            {
                wsk[i] = r.wsk[i];
            }
        }
        return *this;
    }

    size_t ilosc() const { return roz; }

    ostream &view(ostream &out) const
    {
        out << roz << endl;
        for (size_t i = 0; i < roz; i++)
        {
            wsk[i].view(out);
        }
        return out;
    }
    friend ostream &operator<<(ostream &, const wielobok &);
};
ostream &operator<<(ostream &out, const wielobok &r)
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
        throw int(2);

    ifstream plik_we(argv[1]);
    ofstream plik_wy(argv[2]);
    if (!plik_we)
        throw int(3);
    {
        wielobok w;
        try
        {
            w.read(plik_we);
            cout << w;
            plik_wy << w;
        }
        catch (const string &e)
        {
            cout << e << endl;
        }
        plik_we.close();
        plik_wy.close();
    }

    punkt p1(2, 3);
    cout << p1.x() << ' ' << p1.y() << endl;
    p1.x() = 1;
    p1.y() = 1;
    cout << p1.x() << ' ' << p1.y() << endl;
    cout << p1.odleglosc(punkt()) << endl;
    const punkt t[] = {punkt(0, 0), punkt(0, 1), punkt(1, 1), punkt(1, 0)};
    for (size_t i = 0; i < sizeof(t) / sizeof(punkt); ++i)
        cout << i + 1 << ")  " << t[i] << endl;

    cout << "\n\n**********\n\n";

    wielobok w1(t, t + 4);
    cout << w1.obwod() << endl;

    w1[1] = punkt(0.5, 0.5);
    cout << w1.obwod() << endl;

    wielobok w2;
    w2 = wielobok(t, t + 3);

    for (size_t i = 0; i < w2.ilosc(); ++i)
        cout << w2[i].x() << ' ' << w2[i].y() << '\n';

    cout << "\n*****\n";
    wielobok w3(w2);
    w3[1] = punkt(0, -1);
    w3[2] = punkt(-1, -1);
    for (size_t i = 0; i < w3.ilosc(); ++i)
        cout << w3[i] << endl;
    cout << "***\n\n";
    cout << "\n*****\n";
    cout << w2 << "***\n"
         << w3;
    cout << "*****\n\n";

    cout << w2.obwod() - w3.obwod() << "\n\n";
    return 0;
}

catch (int err)
{
    switch (err)
    {
    case 0:
        cout << "Niepoprawna ilość argumentów wejściowych (3) ./nazwa plik_wej.txt plik_wyj.txt" << endl;
        break;
    case 1:
        cout << "Niepoprawne rozszerzenie pliku wejściowego (.txt)" << endl;
        break;
    case 2:
        cout << "Niepoprawne rozszerzenie pliku wyjściowego (.txt)" << endl;
        break;
    case 3:
        cout << "Nie znaleziono podanego pliku " << argv[1] << endl;
        break;
    }
}

catch (...)
{
    cout << "Nieznana sytuacja wyjątkowa" << endl;
}