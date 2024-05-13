#include <iostream>
#include <fstream>

using namespace std;

class pomiar{
	protected:
	string opis;
	size_t roz;
	double* tab;
	public:
	pomiar():roz(0),tab(nullptr){}
	pomiar(const string& a):opis(a),roz(0),tab(nullptr){}
	pomiar(const string& a,const double* p,const double* k):opis(a), roz(k-p>0?k-p:0),tab(roz?new double [roz] : nullptr){}
	pomiar(const pomiar& a):opis(a.opis),roz(a.roz){
		if(roz){
			tab=new double[roz];
		}
		for (size_t i=0;i<roz;i++){
			tab[i]=a.tab[i];
		}
	}
	pomiar& operator=(const pomiar&a){
		opis=a.opis;
		roz=a.roz;
		if(roz){
			tab=new double [roz];
		}
		for(size_t i=0;i<roz;i++){
			tab[i]=a.tab[i];
		}
	}
	virtual ostream& pokaz_opis(ostream&)const=0;
	virtual ~pomiar(){
		delete [] tab;
		cout<<"destruktor pomiar"<<endl;
		}
	/*
	friend ostream& operator<< (ostream& a, const pomiar& r);
	*/
};

ostream& operator<<(ostream& a,const pomiar& r){
	return r.pokaz_opis(a);
}


class ciezar :public pomiar{
	public:
	ciezar():pomiar(){}
	ciezar(const string& a):pomiar(a){}
	ciezar(const string& a,const double* p,const double* k):pomiar(a,p,k){}

	ostream& pokaz_opis(ostream& out)const{
		return out<<"ciezar-\""<<opis<<"\""<<endl;
	}
	~ciezar(){cout<<"destruktor ciezar"<<endl;}


};

class temp : public pomiar{
	public:
	temp():pomiar(){}
	temp(const string& a):pomiar(a){}
	temp(const string& a,const double* p,const double* k):pomiar(a,p,k){}
	
	ostream& pokaz_opis(ostream& out)const{
		return out<<"Temperatura-\""<<opis<<"\""<<endl;
	}

	~temp(){cout<<"destruktor temp"<<endl;}


};

int main(){
	double dane[]={0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8};
	
	pomiar* tab[5];
		tab[0] = new ciezar("cytryny") ;
	  tab[1] = new temp("poranki", dane+3, dane+6);
	  tab[2] = new ciezar("jabłka", dane+1, dane+3) ;
	  tab[3] = new temp("wieczory", dane+1, dane+9);
	  tab[4] = new ciezar;
	
	cout<<"********** 1 **********" << endl;
	
	for(int i=0; i<5; i++){
		cout<<*tab[i]<<endl;
	}
	
	for(int i=0; i<5; i++){
		delete tab[i];
	}
	
	return 0;
}
