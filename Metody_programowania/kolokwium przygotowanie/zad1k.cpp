#include <iostream>


using namespace std;

class punkt
{
    double x_, y_, z_;

public:
    punkt(const double x = 0, const double y = 0, const double z = 0) : x_(x), y_(y), z_(z) {}
    punkt(const punkt&p):x_(p.x()),y_(p.y()),z_(p.z()){}
    ostream &view(ostream &out) const
    {
        out << x_ << " , " << y_ << " , " << z_ << endl;
        return out;
    }

    double x() const { return x_; }
    double y() const { return y_; }
    double z() const { return z_; }
    double &x() { return x_; }
    friend ostream &operator<<(ostream &out, const punkt &r);
};

ostream &operator<<(ostream &out, const punkt &r)
{
    return r.view(out);
}

class prostokat
{
    punkt *p_;
    double a_, b_;

public:
    prostokat(const double x = 0, const double y = 0, const double z = 0, const double a = 0, const double b = 0) : p_(new punkt(punkt(x, y, z))), a_(a), b_(b) {}
    prostokat(const punkt &p, const double a = 0, const double b = 0){
        punkt p1(p);
        p_=new punkt(p1);
        a_=a;
        b_=b;
    }
    prostokat(const prostokat& p){
        punkt p1(p.p());
        p_=new punkt(p1);
        a_=p.a();
        b_=p.b();
    }

     prostokat &operator=(const prostokat &other)
    {
        if (this != &other)
        {
            delete p_;
            p_ = new punkt(*other.p_);
            a_ = other.a_;
            b_ = other.b_;
        }
        return *this;
    }

    ~prostokat() { delete p_; p_=nullptr;}

    double pole() const
    {
        return a_ * b_;
    }

    punkt p() const {return *p_;}
    double a() const { return a_; }
    double b() const { return b_; }
   
    ostream &view(ostream &out) const
    {
        p_->view(out);
        out << a_ << " , " << b_ << endl;
        return out;
    }
    friend ostream &operator<<(ostream &out, const prostokat &r);
};

ostream &operator<<(ostream &out, const prostokat &r)
{
    return r.view(out);
}

class graniastoslup
{
    prostokat *p_;
    double h_;

public:
    graniastoslup(const double x = 0, const double y = 0, const double z = 0, const double a = 0, const double b = 0, const double h = 0) : p_(new prostokat(punkt(x, y, z), a, b)), h_(h) {}
    graniastoslup(const punkt &p, const double a = 0, const double b = 0, const double h = 0){
        punkt p1(p);
        p_=new prostokat(p1,a,b);
        h_=h;
    }
    graniastoslup(const prostokat &p, const double h = 0){
        prostokat p1(p);
        p_=new prostokat(p1);
        h_=h;
    }

    graniastoslup &operator=(const graniastoslup &other)
    {
        if (this != &other)
        {
            delete p_;
            p_ = new prostokat(*other.p_);
            h_ = other.h_;
        }
        return *this;
    }

    ~graniastoslup() { delete p_; p_=nullptr;}

    double objetosc() const { return p_->a() * p_->b() * h_; }


    ostream &view(ostream &out) const
    {
        p_->view(out);
        out << h_ << endl;
        return out;
    }
    friend ostream &operator<<(ostream &out, const graniastoslup &r);
};

ostream &operator<<(ostream &out, const graniastoslup &r)
{
    return r.view(out);
}

int main()
{

    punkt p1, p2(1, 2, 3);
    const punkt p3(1.1, 2.2, 3.3);

    cout << p1 << p2 << p3 << endl;

    cout << p2.x() << endl;
    p1.x() = 1;
    cout << p1.x() << endl;

    prostokat pr1, pr2(1, 2, 3, 10.5, 20.5);
    const prostokat pr3(p2, 5, 5);

    cout << pr1 << pr2 << pr3 << endl;

    cout << pr1.pole() << "\n"
         << pr3.pole() << endl;

    graniastoslup g1, g2(1, 2, 3, 10.5, 20.5, 30.5), g3(p2, 100, 200, 300);
    const graniastoslup g4(pr3, 5);

    cout << g1 << g2 << g3 << g4 << endl;

    cout << g3.objetosc() << "\n"
         << g4.objetosc() << endl;

    return 0;
}