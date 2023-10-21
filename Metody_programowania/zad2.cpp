#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

class adres
{
	string miasto, ulica;
	int nr;

public:
	adres()
	{
		miasto = "brak";
		ulica = "brak";
		nr = 0;
	}
	adres(const string &a1, const string &a2, int a3) : miasto(a1), ulica(a2), nr(a3) {}

	ostream &view(ostream &out) const
	{
		return out << miasto << ", " << ulica << ", " << nr << '\n';
	}

	string &miasto1()
	{
		return miasto;
	}

	friend ostream &operator<<(ostream &out, const adres &r);
};
ostream &operator<<(ostream &out, const adres &r)
{
	return r.view(out);
}

class osoba
{
	string im;
	int wi;
	adres *adr;

public:
	osoba()
	{
		im = "";
		wi = 0;
		adr = new adres;
	}
	osoba(const string &a1, int a2, const adres &a3) : im(a1), wi(a2), adr(new adres(a3)) {}

	osoba(const osoba &a1) : im(a1.im), wi(a1.wi), adr(new adres(*a1.adr)) {}

	osoba &operator=(const osoba &a1)
	{
		if (this != &a1)
		{
			im = a1.im;
			wi = a1.wi;
			*adr = *a1.adr;
		}
		return *this;
	}

	~osoba()
	{
		if (adr)
		{
			delete adr;
			adr = nullptr;
		}
	}

	string &miasto() { return adr->miasto1(); }

	ostream &view(ostream &out) const
	{
		return out << im << ", " << wi << ", " << *adr << '\n';
	}

	friend ostream &operator<<(ostream &out, const osoba &r);
};
ostream &operator<<(ostream &out, const osoba &r)
{
	return r.view(out);
}
int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif
	adres *wsk = new adres("Częstochowa", "Dąbrowskiego", 73);
	cout << wsk << '\n';
	cout << *wsk << '\n';

	adres a1(*wsk);

	if (wsk)
	{
		delete wsk;
		wsk = nullptr;
	}

	const adres *wsk1 = new adres("Łódź", "Piotrkowska", 33);

	cout << a1 << '\n';
	cout << *wsk1 << '\n';

	adres a2;
	cout << a2 << '\n';
	a2 = a1;
	cout << a2 << '\n';

	osoba os1("Ala", 25, *wsk1);
	if (wsk1)
	{
		delete wsk1;
		wsk1 = nullptr;
	}
	cout << os1 << '\n';
	osoba os2(os1);
	cout << os2 << '\n';

	os1.miasto() = "Zmieniono miasto osoby 1.";
	cout << os1 << '\n';

	osoba os3;
	cout << os3 << '\n';
	os3 = os2;
	cout << os3 << '\n';

	os1.miasto() = "Drugi raz zmieniono miasto osoby 1.";
	cout << os1 << '\n';

#ifdef _WIN32
	system("PAUSE");
#endif
	return 0;
}
