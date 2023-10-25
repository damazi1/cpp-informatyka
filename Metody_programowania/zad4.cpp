#include <iostream>

using namespace std;

class point
{
    double tab[3];

public:
    point(double a1, double a2, double a3)
    {
        tab[0] = a1;
        tab[1] = a2;
        tab[2] = a3;
    }
    point(const double *wsk)
    {
        for (int i = 0; i < 3; i++)
        {
            tab[i] = wsk[i];
        }
    }

    double &operator[](size_t i)
    {
        return tab[i]; // Nie wiem !?!
    }

    double distance(const point &p)
    {
        for (int i = 0; i < 3; i++)
        {
            double x = x_ - a1.x_;
            double y = y_ - a1.y_;
            double wynik = x * x + y * y;
        }
        return sqrt(wynik);
    }

    ostream &view(ostream &out) const
    {
        return out << tab[0] << " , " << tab[1] << " , " << tab[2] << endl;
    }
    friend ostream &operator<<(ostream &out, const point &r);
};
ostream &operator<<(ostream &out, const point &r)
{
    return r.view(out);
}

int main()
{
    double x[2][3] = {{1.0, 1.0, 1.0}, {1.0, 2.0, 3.0}};
    point p1(x[0]), p2(x[1]);

    const point p3(0.4, 0.2, 0.1);

    cout << p1 << p2 << p3 << endl;
    // cout << p3[0] <<'\n'; nie wiem !?!

    return 0;
}