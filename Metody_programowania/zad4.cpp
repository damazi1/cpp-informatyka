#include <iostream>
#include <cmath>

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

	~point() {}

	double operator[](size_t i) const { return tab[i]; }

	double distance(const point &pa) const
	{
		double a = (pa[0] - tab[0]) * (pa[0] - tab[0]);
		double b = (pa[1] - tab[1]) * (pa[1] - tab[1]);
		double c = (pa[2] - tab[2]) * (pa[2] - tab[2]);
		double d = sqrt(a + b + c);
		return d;
	}

	point operator+(const point &pa) const
	{
		return point(tab[0] + pa[0], tab[1] + pa[1], tab[2] + pa[2]);
	}

	point operator-(const point &pa) const
	{
		return point(tab[0] - pa[0], tab[1] - pa[1], tab[2] - pa[2]);
	}

	point operator*(const double &a) const
	{
		return point(tab[0] * a, tab[1] * a, tab[2] * a);
	}

	friend point operator*(const double &a, const point &p) { return p * a; }

	bool mniejsze(const point &pa) const
	{
		if (this->distance(pa) >= 1e-10)
		{
			return 1;
		}
		return 0;
	}

	bool operator<(const point &other) const
	{
		return mniejsze(other);
	}

	bool rowne(const point &pa) const
	{
		if (this->distance(pa) < 1e-10)
		{
			return 1;
		}
		return 0;
	}

	bool operator==(const point &other) const
	{
		return rowne(other);
	}

	friend istream &operator>>(istream &in,point &r)
	{
		double a = 0, b = 0, c = 0;
		cout << "Podaj a : ";
		in >> a;
		cout << "\nPodaj b : ";
		in >> b;
		cout << "\nPodaj c : ";
		in >> c;
		r = point(a,b,c);
		return in;
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
	double x[2][3] = {{1.0, 1.0, 1.0},
					  {1.0, 2.0, 3.0}};
	point p1(x[0]), p2(x[1]);
	const point p3(0.4, 0.2, 0.1);

	cout << p1 << p2 << p3 << endl;
	cout << p3[0] << ' ' << p3[1] << ' ' << p3[2] << '\n';

	cout << p1.distance(point()) << endl;
	cout << p3.distance(p1) << endl;

	cout << p1 << p2 << endl;
	cout << p1 + p2 << endl;

	cout << p1 - p3 << endl;

	cout << 3.14 * p2 << endl;
	cout << p2 * 3.14 << endl;

	cout << (p1 < p3) << endl;
	cout << (p1 == point(1.0, 1.0, 1.0)) << endl;

	cin>>p1;
  	cout << p1 << '\n';

	cout<<p1.distance(point())<<endl;

	return 0;
}
