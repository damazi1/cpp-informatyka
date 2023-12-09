#include <iostream>
#include <fstream>

using namespace std;

class pomiar
{
protected:
	string opis;
	size_t roz;
	double *tab;

public:
	pomiar() : roz(0), tab(nullptr) {}
	pomiar(const string &a) : opis(a), roz(0), tab(nullptr) {}
	pomiar(const string &a, const double *p, const double *k) : opis(a), roz(k - p > 0 ? k - p : 0), tab(roz ? new double[roz] : nullptr)
	{
		for (size_t i = 0; i < roz; i++)
		{
			tab[i] = p[i];
		}
	}
	pomiar(const pomiar &a) : opis(a.opis), roz(a.roz)
	{
		if (roz)
		{
			tab = new double[roz];
		}
		for (size_t i = 0; i < roz; i++)
		{
			tab[i] = a.tab[i];
		}
	}
	pomiar &operator=(const pomiar &a)
	{
		opis = a.opis;
		cout << opis << endl;
		roz = a.roz;
		cout << roz << endl;
		if (roz)
		{
			tab = new double[roz];
		}
		for (size_t i = 0; i < roz; i++)
		{
			tab[i] = a.tab[i];
			cout << a.tab[i];
		}
		return *this;
	}
	virtual double oblicz_wynik() const = 0;
	virtual ostream &pokaz_opis(ostream &) const = 0;
	virtual ~pomiar()
	{
		delete[] tab;
	}
	/*
	friend ostream& operator<< (ostream& a, const pomiar& r);
	*/
};

ostream &operator<<(ostream &a, const pomiar &r)
{
	return r.pokaz_opis(a);
}

class ciezar : public pomiar
{
public:
	ciezar() : pomiar() {}
	ciezar(const string &a) : pomiar(a) {}
	ciezar(const string &a, const double *p, const double *k) : pomiar(a, p, k) {}

	double oblicz_wynik() const
	{
		double suma = 0;
		for (size_t i = 0; i < roz; i++)
		{
			suma += tab[i];
		}
		if (!suma)throw("Brak danych");
		return suma;
	}

	ostream &pokaz_opis(ostream &out) const
	{
		return out << "ciezar-\"" << opis << "\"" << endl;
	}

	~ciezar() {}
};

class temp : public pomiar
{
public:
	temp() : pomiar() {}
	temp(const string &a) : pomiar(a) {}
	temp(const string &a, const double *p, const double *k) : pomiar(a, p, k) {}

	double oblicz_wynik() const
	{
		double suma = 0;
		for (size_t i = 0; i < roz; i++)
		{
			suma += tab[i];
		}
		if (!suma)throw("Brak danych");
		suma = suma / roz;
		return suma;
	}

	ostream &pokaz_opis(ostream &out) const
	{
		return out << "Temperatura-\"" << opis << "\"" << endl;
	}

	~temp() {}
};

int main()
try
{
	double dane[] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};

	pomiar *tab[5];
	tab[0] = new ciezar("cytryny");
	tab[1] = new temp("poranki", dane + 3, dane + 6);
	tab[2] = new ciezar("jabłka", dane + 1, dane + 3);
	tab[3] = new temp("wieczory", dane + 1, dane + 9);
	tab[4] = new ciezar;

	cout << "********** 1 **********" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << *tab[i] << endl;
	}

	cout << "\n********** 2 **********" << endl;

	for (int i = 0; i < 5; i++)
		try
		{
			{
				cout << *tab[i] << ", Wynik: " << tab[i]->oblicz_wynik() << endl;
			}
		}
		catch (const string &a)
		{
			cout << a << endl;
		}

	cout << "\n********** 2a *********" << endl;
	*tab[0] = ciezar("cytryny", dane, dane + 1);
	// *tab[0] = ("[kg] " + *tab[0]) += "po wyprzedaży";
	// *tab[1] = "Wiosenne " + *tab[1];
	// *tab[2] += "ANTONÓWKI suszone";
	// *tab[2] *= 0.1;
	// *tab[3] += "po korekcie odczytu";
	// *tab[3] += 0.1;

	for (int i = 0; i < 5; ++i)
		try
		{
			cout << *tab[i] << ", WYNIK : " << tab[i]->oblicz_wynik() << endl;
		}
		catch (const string &a)
		{
			cout << a << endl;
		}

	for (int i = 0; i < 5; i++)
	{
		delete tab[i];
	}

	return 0;
}

catch (...)
{
	cout << "Cos poszlo nie tak" << endl;
}
