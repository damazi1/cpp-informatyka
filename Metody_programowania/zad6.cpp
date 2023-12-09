#include <iostream>

using namespace std;

class osoba{
	protected:
	string naz;
	int wi;
public:
	osoba():naz("brak"),wi(0){}
	osoba(const string& a1,int a2):naz(a1),wi(a2){}
	void pokaz () const{
		cout<<naz<<"  "<< wi<<endl;
	}
	string nazwisko() const{return naz;}
	int liczba_lat()const {return wi;}
};

class pracownik : public osoba {
	string stan;
	double plac;
public:
	pracownik(){}
	pracownik(const string& a1,int a2,const string& a3, const double& a4):osoba(a1,a2),stan(a3),plac(a4){}
	pracownik(const pracownik& pr):osoba(pr.nazwisko(),pr.liczba_lat()),stan(pr.stanowisko()),plac(pr.placa()){}
	
	string stanowisko ()const {return stan;}
	double placa() const {return plac;}
	
	void pokaz()const{
		osoba::pokaz();
		cout<<stan<<"  "<<plac<<endl;
	}
};

int main(){
osoba os("Dolas",26);
os.pokaz();

const pracownik pr1("Dyzma",35,"mistrz",1250.50);
cout<<pr1.nazwisko()<< pr1.liczba_lat();
cout << pr1.stanowisko() << pr1.placa()<<endl;

pracownik pr2(pr1);
pr2.pokaz();

pracownik pr3("Kos" , 45, "kierownik" ,2999.0);
pr3.pokaz();
pr3 = pr2;
pr3.pokaz();

osoba * w=&os;
w->pokaz();
w = &pr3;
w->pokaz();

return 0;
}
