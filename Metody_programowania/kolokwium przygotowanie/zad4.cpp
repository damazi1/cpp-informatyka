#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

class point
{
    double tab[3];

public:
    point(const double a = 0, const double b = 0, const double c = 0)
    {
        tab[0] = a;
        tab[1] = b;
        tab[2] = c;
    }
    point(const double (&wsk)[3])
    {
        tab[0] = wsk[0];
        tab[1] = wsk[1];
        tab[2] = wsk[2];
    }

    double operator[](size_t i) const
    {
        return tab[i];
    }

    double distance(const point &p) const
    {
        double x = (pow(tab[0] - p.tab[0], 2));
        double y = (pow(tab[1] - p.tab[1], 2));
        double z = (pow(tab[2] - p.tab[2], 2));
        return sqrt(x + y + z);
    }

    point operator+(const point &r) const
    {
        double a = tab[0] + r.tab[0];
        double b = tab[1] + r.tab[1];
        double c = tab[2] + r.tab[2];
        return point(a, b, c);
    }
    point operator-(const point &r) const
    {
        double a = tab[0] - r.tab[0];
        double b = tab[1] - r.tab[1];
        double c = tab[2] - r.tab[2];
        return point(a, b, c);
    }
    point operator*(const double &r) const
    {
        double a = tab[0] * r;
        double b = tab[1] * r;
        double c = tab[2] * r;
        return point(a, b, c);
    }
    friend point operator*(const double &c, const point &r)
    {
        return r * c;
    }

    bool operator<(const point &p) const
    {
        double a = this->distance(point());
        double b = p.distance(point());
        if (a - b < 0)
        {
            return 1;
        }
        return 0;
    }

    bool operator==(const point &p) const
    {
        double a = this->distance(point());
        double b = p.distance(point());
        if (a - b < 1e-10 && a - b > -1e-10)
        {
            return 1;
        }
        return 0;
    }

    friend istream &operator>>(istream &in,point &r)
    {
        cout << "podaj a: ";
        in >> r.tab[0];
        cout << "podaj b: ";
        in >> r.tab[1];
        cout << "podaj c: ";
        in >> r.tab[2];
        return in;
    }

    ostream &view(ostream &out) const
    {
        out << tab[0] << "  " << tab[1] << "  " << tab[2] << endl;
        return out;
    }
    friend ostream &operator<<(ostream &, const point &);
};
ostream &operator<<(ostream &out, const point &r)
{
    return r.view(out);
}

int main(int argc, char *argv[])
try
{
    if (argc != 1)
        throw int(0);

    double x[2][3] = {{1.0, 1.0, 1.0},
                      {1.0, 2.0, 3.0}};

    point p1(x[0]), p2(x[1]);
    const point p3(0.4, 0.2, 0.1);

    cout << p1 << ", " << p2 << '\n';
    cout << p3[0] << ' ' << p3[1] << ' ' << p3[2] << '\n';

    cout << p1.distance(point()) << endl;
    cout << p3.distance(p1) << endl;

    cout << p1 + p2 << endl;
    cout << p1 - p3 << endl;

    cout << 3.14 * p2 << endl;
    cout << p2 * 3.14 << endl;

    cout << boolalpha;
    cout << (p1 < p3) << endl;
    cout << (p1 == point(1.0, 1.0, 1.0)) << endl;

    cin >> p1;
    cout << p1 << '\n';

    return 0;
}
catch (int err)
{
    switch (err)
    {
    case 0:
        cout << err << ". Niepoprawna ilośc argumentów programu (1)" << endl;
    }
}