#include <iostream>
#include <vector>

using namespace std;

class robot;
using wsk = robot*;

class robot{
	protected:
	static int l_ob;
	public:
	static int l_obiektow(){return l_ob;}
	virtual ~robot(){ cout << "~robot()" << endl;}
	virtual wsk clone() const =0;
};
class r1 : public robot {
  public:
	  r1(){l_ob++;}                               
	  r1(const r1& r){l_ob++;}           
	  void praca()const;   
	  ~r1(){cout << "~r1()" << endl; l_ob--;}
	  wsk clone()const{
		robot::l_ob++;
		return new r1(*this);
	  }
};
class r2 : public robot {
  public:
	  r2(){l_ob++;}                               
	  r2(const r2& r){l_ob++;}           
	  void praca()const;   
	  ~r2(){cout << "~r2()" << endl; l_ob--;}
	  wsk clone()const{
		robot::l_ob++;
		return new r2(*this);
	  }
};

class line{
		vector <wsk> ve;
	public:
	  line(){}
	  line(int r):ve(r){ 
		cout << "Wartości wektora ve : " ;
		for( auto&& ref : ve )
			cout << ref << ", " ; 
		cout << endl;
	  }

	  line(const wsk* b, const wsk* e);    // Pamiętaj,  
	  line(const line& arg);               // że w każdej z tych funkcji masz zadbać o to, by obiekt klasy line
	  line& operator = (const line& a){
	    if(this!=&a){
		  for(auto&& r:ve)
		    delete r;
		  //for (size_t i=0;i<ve.size();++i)
			//delete ve[i];
		  ve.resize(a.ve.size());
		  for (size_t i=0;i<ve.size();++i)
			ve[i]=a.ve[i]->clone();
		}
	    return *this;
	  }
		  
	  void dodaj_ostatni( const wsk& arg){
		  ve.push_back(arg);
	  }
	  void dodaj_ity(int i,  const wsk& arg);
	  void usun_ity(int i);
	  void usun_ostatni(){
		  ve.pop_back();
	  }
	  
	  void do_roboty()
	  {
		  
	  }
	  
	  ~line(){cout<<"~line"<<endl;}
};

int robot::l_ob = 0; 
void liczba_obiektow(){
  cout << "liczba_obiektów = " << robot::l_obiektow() << endl;
}
int main()try{
	liczba_obiektow();
	{ line l1 ;    }
	{ line l2(5) ; }
    liczba_obiektow();

	cout << "--==**1**==--" << endl;
	liczba_obiektow();
	line lp1,lp2;
	lp1.dodaj_ostatni(new r1);
    lp1.dodaj_ostatni(new r1);
    lp1.dodaj_ostatni(new r2);
    lp1.dodaj_ostatni(new r2);
    liczba_obiektow();
    lp2=lp1;
    liczba_obiektow();
    
    {
      line lp3;
      //liczba_obiektow();
      lp3.dodaj_ostatni(new r1);
      lp3.dodaj_ostatni(new r2);
      lp3.dodaj_ostatni(new r1);
      lp3.dodaj_ostatni(new r2);
      //liczba_obiektow();
      lp3.usun_ostatni();     
      //liczba_obiektow();
      cout << "--==**2**==--" << endl;
      //liczba_obiektow();
      lp3.do_roboty();       
      //liczba_obiektow();
      lp1 = lp3;
      cout << "--==**2a**==--" << endl;  
      //liczba_obiektow();
    }      
return 0;
}

catch (...){
	cout<<"Nieznany blad "<<endl;
}
