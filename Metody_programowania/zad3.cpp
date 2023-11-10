#include <iostream>
#include <cmath>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

class punkt
{
    double x_, y_;

public:
    punkt() : x_(0), y_(0) {}
    punkt(const double a1, const double a2) : x_(a1), y_(a2) {}

    double &x() { return x_; }
    double &y() { return y_; }

    double odleglosc(punkt a1)
    {
        double x = x_ - a1.x_;
        double y = y_ - a1.y_;
        double wynik = x * x + y * y;
        return sqrt(wynik);
    }

    ostream &view(ostream &out) const
    {
        return out << x_ << " , " << y_ << endl;
    }

    friend ostream &operator<<(ostream &out, const punkt &r);
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
    
    wielobok(const punkt *b=nullptr, const punkt *e=nullptr) : roz(e - b > 0 ? e - b : 0), wsk(roz ? new punkt[roz] : 0)
    {
        for (size_t i = 0; i < roz; i++)
        {
            wsk[i] = b[i];
        }
    }

    wielobok &operator=(const wielobok &r)
    {
        if (this != &r)
        {
            roz=r.roz;
            *wsk=*r.wsk;
        }
        return *this;
    }

    ~wielobok()
    {
        if (wsk)
        {
            delete[] wsk;
            wsk = nullptr;
        }
    }

    punkt &operator[](size_t i)
    {
        return wsk[i];
    }

    double obwod()
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
    ostream &view(ostream &out)const{
        out<<roz<<endl;
        for (size_t i=0;i<roz;i++){
            wsk[i].view(out);
        }
        return out;
    }
    friend ostream &operator<<(ostream& out,const wielobok& r);
};
ostream &operator<<(ostream& out,const wielobok& r){
    return r.view(out);
}

int main()
{
    punkt p(2, 3);
    cout << p.x() << ' ' << p.y() << '\n';
    p.x() = 1;
    p.y() = 1;
    cout << p.x() << ' ' << p.y() << '\n';

    cout << p.odleglosc(punkt()) << "\n\n";

    const punkt t[] = {punkt(0, 0), punkt(0, 1), punkt(1, 1), punkt(1, 0)};
    for (size_t i = 0; i < sizeof(t) / sizeof(punkt); ++i)
        cout << i + 1 << ")  " << t[i] << endl;

    cout << "\n*****\n";

    wielobok w1(t, t + 4);
    cout << w1.obwod() << '\n';

    w1[1] = punkt(0.5, 0.5);
    cout << w1.obwod() << '\n';
    cout << "***\n\n";

    wielobok w2(t, t + 3);
    // w2 = wielobok(t, t+3);
    cout << w2.obwod() << '\n';

    wielobok w3;
    cout<<"\n******\n"<<w1<<w2<<w3<<endl;

    return 0;
}