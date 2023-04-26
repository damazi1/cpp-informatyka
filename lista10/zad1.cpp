#include <iostream>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

struct SPunkt
{
    double x, y;
};

struct SProsta
{
    double a, b;
};

struct SOkrag
{
    double a, b, r;
};

struct SRownanie
{
    double a, b, c;
};
int rozw_rown(const SRownanie &r, SPunkt &p1, SPunkt &p2)
{
    if (r.a < 0 || r.a > 0)
    {
        double delta = r.b * r.b - 4 * r.a * r.c;
        if (delta < 0)
        {
            return 0;
        }
        else if (delta > 0)
        {
            if (r.b > 0)
            {
                p1.x = (-r.b - sqrt(delta)) / (2 * r.a);
                p2.x = r.c / (r.a * p1.x);
            }
            else if (r.b < 0)
            {
                p1.x = (-r.b + sqrt(delta)) / (2 * r.a);
                p2.x = r.c / (r.a * p1.x);
            }
            else
            {
                p1.x = -sqrt(delta) / 2 * r.a;
                p2.x = sqrt(delta) / 2 * r.a;
            }
            return 2;
        }
        else
        {
            p1.x = -r.b / (2 * r.a);
            p2.x = p1.x;
            return 1;
        }
    }
    else
        return -1;
}

int pkt_przec(const SProsta &p, const SOkrag &o, SPunkt &p1, SPunkt &p2)
{
    SRownanie r;

    r.a = p.a * p.a + 1;
    // r.b = 2 * p.a * (p.b - o.b) - 2 * o.a;
    r.b = 2 * p.a * p.b - 2 * p.a * o.b - 2 * o.a;
    // r.c = o.a * o.a + (p.b - o.b) * (p.b - o.b) - o.r * o.r;
    r.c = -2 * p.b * o.b + o.a * o.a + p.b * p.b + o.b * o.b - o.r * o.r;

    int pierw = rozw_rown(r, p1, p2);
    if (pierw > 0)
    {
        p1.y = p.a * p1.x + p.b;
        p2.y = p.a * p2.x + p.b;
        return 2;
    }
    else if (pierw < 0)
    {
        return 0;
    }
    else
    {
        p1.y = p.a * p1.x + p.b;
        p2.y = p1.y;
        return 1;
    }

    return -1;
}

bool czy_prostopadle(const SProsta &p1, const SProsta &p2)
{
    if (p1.a * p2.a == -1)
    {
        return true;
    }
    return false;
}

int main()
{
    SPunkt p1 = {0, 0}, p2 = {0, 0};
    SProsta prosta1 = {-1.0, 3.0}, prosta2 = {1.0, -3.0};
    SOkrag okrag = {0.0, 1.0, 2.0};
    int pier1 = pkt_przec(prosta1, okrag, p1, p2);
    if (pier1 == 2)
    {
        cout << "Prosta przecina okrag w punktach: " << endl;
        cout << "(" << p1.x << ", " << p1.y << ")" << endl;
        cout << "(" << p2.x << ", " << p2.y << ")" << endl;
    }
    else if (pier1 == 1)
    {
        cout << "Prosta jest styczna do okregu w punkcie: " << endl;
        cout << "(" << p1.x << ", " << p1.y << ")" << endl;
    }
    else if (pier1 == 0)
    {
        cout << "Prosta nie przecina okregu" << endl;
    }
    else
    {
        cout << "Brak rozwiazania - to nie jest rownianie kwadratowe";
        cout << "Czy proste sa prostopadle? " << boolalpha << czy_prostopadle(prosta1, prosta2) << endl;
    }
    return 0;
}