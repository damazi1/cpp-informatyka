#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class K1
{
    string *p1;

public:
    K1() : p1(nullptr) {}
    K1(const string &a, const string &b)
    {
        p1 = new string[2];
        p1[0] = a;
        p1[1] = b;
    }
    K1(const K1 &k)
    {
        p1 = new string[2];
        p1[0] = k.p1[0];
        p1[1] = k.p1[1];
    }
    K1 operator=(const K1 &w)
    {
        if (p1)
        {
            delete[] p1;
            p1 = nullptr;
        }
        p1 = new string[2];
        p1[0] = w.p1[0];
        p1[1] = w.p1[1];
        return *this;
    }
    ~K1() { delete[] p1; }

    K1 dodaj(K1 &p, const string &r)
    {
        p.p1[1] += r;
        return p;
    }

    K1 dodaj1(K1 &p, const string &r)
    {
        p.p1[0]=r+p.p1[0] ;
        return p;
    }

    ostream &view(ostream &out) const
    {
        if (p1)
        {
            out << p1[0] << " " << p1[1] << endl;
        }
        return out;
    }

    friend ostream &operator<<(ostream &, const K1 &);
};

ostream &operator<<(ostream &out, const K1 &r)
{
    return r.view(out);
}

class K2
{
    K1 w1;
    double w2;

public:
    K2() : w2(0.0) {}
    K2(const string &a, const string &b, const double &l) : w1(K1(a, b)), w2(l) {}

    K2 operator=(const K2 &k)
    {
        w1 = k.w1;
        w2 = k.w2;
        return *this;
    }

    K2 operator-(const double &l)
    {
        w2 -= l;
        return *this;
    }

    double operator+=(const double &l)
    {
        w2 += l;
        return w2;
    }

    K2 operator+(const string &r)
    {
        w1.dodaj(w1, r);
        return *this;
    }
    friend K2 operator+(const string& r,K2 &k){
        k.w1.dodaj1(k.w1,r);
        return k;
    }

    ostream &view(ostream &out) const
    {
        w1.view(out);
        out << w2 << endl;
        return out;
    }
    friend ostream &operator<<(ostream &, const K2 &);
};

ostream &operator<<(ostream &out, const K2 &r)
{
    return r.view(out);
}

int main(int argc, char *argv[])
try
{
    if (argc != 2)
        throw int(0);
    if (string(argv[1] + strlen(argv[1]) - 3) != "txt")
        throw int(1);

    K2 ob1, ob2;
    const K2 *wsk1 = new K2("kawa", " z mlekiem", 4.50);
    const K2 ob3(*wsk1);
    cout << *wsk1;
    delete wsk1;
    wsk1 = nullptr;

    const K2 *wsk2 = new K2(ob3);
    ob2 = *wsk2;
    cout << ob1 << *wsk2;

    delete wsk2;
    wsk2 = nullptr;
    cout << ob2;
    cout << ob2 - 1.25;
    cout << "*****3*****\n"
         << endl;

    K2 tab[4];
    ifstream fin(argv[1]);
    if (!fin)
        throw int(2);
    {
        for (size_t i = 0; i < 4; i++)
        {
            string a, b;
            double c;
            fin >> a;
            fin >> b;
            fin >> c;
            tab[i] = K2(a, b, c);
        }
        for (int i = 0; i < 4; ++i)
        {
            tab[i] += 1;
            cout << tab[i];
        }
        fin.close();
    }

    cout << "*****4*****\n"
         << endl;

    tab[1] = tab[1] + " with sugar";
    tab[3] = "hot " + tab[3];

    for (int i = 0; i < 4; i++)
    {
        cout << tab[i];
    }

    cout << "*****5*****\n";

    return 0;
}
catch (int err)
{
    switch (err)
    {
    case 0:
        cout << err << "blad 1" << endl;
        break;
    case 1:
        cout << err << "blad 2" << endl;
        break;
    case 2:
        cout << err << "blad 3" << endl;
        break;
    }
}
catch (...)
{
    cout << "Nieznany blad" << endl;
}