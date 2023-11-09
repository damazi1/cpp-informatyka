#include <iostream>

using namespace std;

class kuku1
{
    double x_, y_, z_;

public:
    kuku1(const double x = 0, const double y = 0, const double z = 0) : x_(x), y_(y), z_(z) {}

    ostream &view(ostream &out) const
    {
        out << x_ << " , " << y_ << " , " << z_ << endl;
        return out;
    }
    friend ostream &operator<<(ostream &out, const kuku1 &r);
};

ostream &operator<<(ostream &out, const kuku1 &r)
{
    return r.view(out);
}

class kuku2
{
    string nazwa;
    kuku1 *wsk;

public:
    kuku2(const string &b = "", const kuku1 &wsk1 = kuku1()) : nazwa(b), wsk(new kuku1(wsk1)) {}
    ~kuku2()
    {
        if (wsk)
        {
            delete wsk;
            wsk = nullptr;
        }
    }

    ostream &view(ostream &out) const
    {
        out << nazwa << endl;
        wsk->view(out);
        return out;
    }
    friend ostream &operator<<(ostream &out, const kuku2 &r);
};

ostream &operator<<(ostream &out, const kuku2 &r)
{
    return r.view(out);
}

int main()
{
    kuku1 k1, k2(1, 2, 3);
    cout << k1 << k2 << endl;

    kuku2 kk1;
    kuku2 kk2("siema", k2);

    cout << kk1 << kk2 << endl;
    return 0;
}