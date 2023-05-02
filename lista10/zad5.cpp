#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

struct SWielomian
{
    int stopien;
    float * wspolczynniki;
};

float losuj(const float min, const float max)
{
    float liczba = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    return (max - min) * liczba + min;
}

float *wspolczynniki(SWielomian &w, const unsigned int stopien = 1, const double min = -5.5, const double max = 5.5)
{
    w.wspolczynniki = new float [stopien+1];
    w.stopien=stopien;
    for (unsigned int i = 0; i <= stopien; i++)
    {
        w.wspolczynniki [i]= losuj(min, max);
    }
    return w.wspolczynniki;
}

float wartosc_wielomianu(const SWielomian &w, const float x)
{
    float wynik = w.wspolczynniki[0];
    for (int i = 1; i <= w.stopien; i++)
    {
        wynik = wynik * x + w.wspolczynniki[i];
    }
    return wynik;
}

void wypisz(const float w, const unsigned i)
{
    cout << "Wyraz " << w << "Stopnia i " << i << endl;
}

void wypisz(const SWielomian &w)
{
    for (int i = 0; i <= w.stopien; i++)
    {
        cout << w.wspolczynniki[i] << " * x^" << w.stopien-i << '\t';
    }
}

void usun(SWielomian p)
{
    if (p.wspolczynniki)
    {
        delete[] p.wspolczynniki;
        p.wspolczynniki = nullptr;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 5)
    {
        cerr << "Podano bledna ilosc argumentow (3-5)" << endl;
        cout << "Poprawny zapis to ./nazwa stopien x wartoscmin wartoscmax" << endl;
        return -1;
    }
    srand(time(NULL));
    SWielomian w;
    int stopien = atoi(argv[1]);
    float x = atof(argv[2]);
    float wartosc = 0;
    if (argc == 5)
    {
        float min = atoi(argv[3]), max = atoi(argv[4]);
        if (min < 0 && max > 0 && stopien > 1)
        {
            wspolczynniki(w, stopien, min, max);
            wartosc = wartosc_wielomianu(w, x);
                cout << "Wartosc wielomianu stopnia " << w.stopien
                     << " dla x = " << x << " wynosi: " << wartosc << endl;
                wypisz(w);
            }
            else
            {
                cout << "Podano zla wartosc min, max lub stopien. ";
                cout << "Wartosc wielomianu wyliczona zostaje "
                     << "dla argumentow domyslnych" << endl;
                cout << "stopien = 1, min = -5.5, max = 5.5" << endl;
                wspolczynniki(w);
                wartosc = wartosc_wielomianu(w, x);
                cout << "Wartosc wielomianu stopnia " << w.stopien - 1
                     << " dla x = " << x
                     << " wynosi: " << wartosc << endl;
                wypisz(w);
        }
        usun(w);
        return 0;
    }
}