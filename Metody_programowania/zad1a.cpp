#include <iostream>

using namespace std;

class punkt
{
    double x, y, z;

public:
    punkt()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    punkt(const double &a, const double &b, const double &c)
    {
        x = a;
        y = b;
        z = c;
    }
    double &x1() { return x; }
    double &y1() { return y; }
    double &z1() { return z; }

    double x1() const { return x; }
    double y1() const { return y; }
    double z1() const { return z; }
};

class prostokat
{
    double x, y, z, a, b;

public:
    prostokat()
    {
        x = 0;
        y = 0;
        z = 0;
        a = 0;
        b = 0;
    }

    prostokat(const double &x1, const double &y1, const double &z1, const double &a1, const double &b1)
    {
        x = x1;
        y = y1;
        z = z1;
        a = a1;
        b = b1;
    }

    prostokat(const punkt &p, const double &a1, const double &b1)
    {
        x = p.x1();
        y = p.y1();
        z = p.z1();
        a = a1;
        b = b1;
    }

    double &x1() { return x; }
    double &y1() { return y; }
    double &z1() { return z; }
    double &a1() { return a; }
    double &b1() { return b; }

    double x1() const { return x; }
    double y1() const { return y; }
    double z1() const { return z; }
    double a1() const { return a; }
    double b1() const { return b; }

    double pole()
    {
        return a * b;
    }

    double pole() const
    {
        return a * b;
    }
};

class graniastoslup
{
    double x, y, z, a, b, h;

public:
    graniastoslup()
    {
        x = 0;
        y = 0;
        z = 0;
        a = 0;
        b = 0;
        h = 0;
    }

    graniastoslup(const double &x1, const double &y1, const double &z1, const double &a1, const double &b1, const double &h1)
    {
        x = x1;
        y = y1;
        z = z1;
        a = a1;
        b = b1;
        h = h1;
    }

    graniastoslup(const punkt &p, const double &a1, const double &b1, const double &h1)
    {
        x = p.x1();
        y = p.y1();
        z = p.z1();
        a = a1;
        b = b1;
        h = h1;
    }

    graniastoslup(const prostokat &pr, const double &h1)
    {
        x = pr.x1();
        y = pr.y1();
        z = pr.z1();
        a = pr.a1();
        b = pr.b1();
        h = h1;
    }

    double &x1() { return x; }
    double &y1() { return y; }
    double &z1() { return z; }
    double &a1() { return a; }
    double &b1() { return b; }
    double &h1() { return h; }

    double x1() const { return x; }
    double y1() const { return y; }
    double z1() const { return z; }
    double a1() const { return a; }
    double b1() const { return b; }
    double h1() const { return h; }

    double objetosc()
    {
        return a * b * h;
    }

    double objetosc() const
    {
        return a * b * h;
    }
};

int main()
{
    punkt p1, p2(1, 2, 3);
    const punkt p3(1.1, 2.2, 3.3);

    cout << p1.z1() << endl;
    cout << p2.z1() << endl;

    cout << p3.x1() << "\t" << p3.y1() << "\t" << p3.z1() << endl;

    p1.x1() = 1;
    p1.y1() = 10;
    p1.z1() = 100;
    cout << p1.x1() << "\t" << p1.y1() << "\t" << p1.z1() << endl;

    prostokat pr1, pr2(1, 2, 3, 10.5, 20.5);

    const prostokat pr3(p2, 5, 5);
    pr1.x1() = 2;
    pr1.y1() = 20;
    pr1.z1() = 200;
    pr1.a1() = 10;
    pr1.b1() = 10;
    cout << pr1.x1() << '\t' << pr1.y1() << '\t' << pr1.z1() << '\t' << pr1.a1() << '\t' << pr1.b1() << endl;
    cout << pr1.pole() << endl;

    cout << pr3.x1() << '\t' << pr3.y1() << '\t' << pr3.z1() << '\t' << pr3.a1() << '\t' << pr3.b1() << endl;
    cout << pr3.pole() << endl;

    graniastoslup g1, g2(1, 2, 3, 10.5, 20.5, 30.5), g3(p2, 100, 200, 300);
    const graniastoslup g4(pr3, 5);

    cout << g4.x1() << '\t' << g4.y1() << '\t' << g4.z1() << '\n'
         << g4.a1() << '\t' << g4.b1() << '\t' << g4.h1() << '\n'
         << g4.objetosc() << endl;

    g1.a1() = 10;
    g1.b1() = 10;
    g1.h1() = 10;

    cout << g1.x1() << '\t' << g1.y1() << '\t' << g1.z1() << '\n'
         << g1.a1() << '\t' << g1.b1() << '\t' << g1.h1() << '\n'
         << g1.objetosc() << endl;

    return 0;
}