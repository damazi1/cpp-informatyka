#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

class unint{
	unsigned v;
public:
	unint():v(0){}
	unint (const unsigned& a):v(a){}
	operator unsigned()const {return v;}
	friend ostream& operator<<(ostream& out, const unint& r){return out<<r.v;}
	friend istream& operator>>(istream& in, unint& r){return in>>r.v;}
};

struct blad {
	string txt;
	unsigned lp;
	blad():lp(0){}
	blad(const string& a, unsigned b):txt(a),lp(b){}
};
ostream& operator<<(ostream& out, const blad& p){return out<<p.txt<< ' ' << p.lp << endl; }

using naturalne =unint;
class polygon;

class point {
	double x,y;
	public:
	point():x(0),y(0){}
	point (const double& a, const double& b):x(a),y(b){}
	double distance(const point& a)const;
	friend class polygon;
	friend istream& operator>>(istream&,point&);
	friend ostream& operator<<(ostream&,const point&);
};

double point::distance(const point& a)const {
  double c2 = (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y);
  if(c2<1e-20)
    return 0; 
  return sqrt(c2); 
}
istream& operator>>(istream& in, point& p){return in>>p.x>>p.y; }
ostream& operator<<(ostream& out, const point& p){return out << p.x <<' '<<p.y; }

class polygon{
	unsigned n;
	point *points;
	naturalne* order;
public:
	polygon():n(0),points(nullptr),order(nullptr){}
	polygon(const polygon& a);
	polygon& operator=(const polygon& a);
	~polygon(){delete[] points;delete[] order;cout<<"\n\n!!!~polygon()!!!\n\n";}
	void read (ifstream &);
	double obwod()const;
	double pole()const;
};

polygon::polygon(const polygon& a){
}
polygon& polygon::operator=(const polygon& a){
  if(this != &a){
	n=a.n;
	*points=*a.points;
	*order=*a.order;
  }
  return *this;
}  


void polygon::read(ifstream & f){

  string buf;
  getline(f,buf);

  if(buf!="[POLYGON]") throw string("Brak nagłówka \"[POLYGON]\""); 
  //cout << buf << endl;
  
  getline(f,buf);
  if(buf!="[NUMBER OF NODES]") throw string("Brak nagłówka \"[NUMBER OF NODES]\""); 
  //cout << buf << endl;

  f >> n ; 
  getline(f,buf);

  if(!f || buf[0]!='\0' ) throw string("Nieprawidłowy format parmetru \"n\""); 
  //cout << n << endl;
 
  if(n<3) throw string("Liczba punktów mniejsza od 3");

  getline(f,buf);
  if(buf!="[NODES]") throw string("Brak nagłówka \"[NODES]\""); 
  //cout << buf << endl;
}

double polygon::obwod()const{
  double obw=0;
  if(!order) throw string ("Brak tablicy order.");
  if(!points) throw string ("Brak tablicy points.");
  for(int i=0, j=0; (unsigned)i<n ;++i){
    j = order[i]-1;
    if(j<0) throw string ("Niedozwolona wartość 0 w tablicy order.");
    if(j>0) throw string ("tak");
    obw+=points[j].distance(points[order[(i+1)%n]-1]);
  }
  return obw;
}

double polygon::pole()const{
	double suma=0;
	for (size_t i=0;i<n-1;i++){
		suma+=points[i].x*points[i+1].y-points[i+1].x*points[i].y;
	}
	return suma/2;
}



int main(int argc,char * argv[])try{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
  #endif

  if (argc !=2) throw int(0);
  if (strlen(argv[1]) < 5 ) throw int(1);
  if (string(argv[1]+(strlen(argv[1])-3))!="txt") throw 2 ;  

  ifstream file(argv[1]);
  if(!file) throw int (3);
  {
    polygon poly;
    try{
      poly.read(file);
      cout<< "obwód : " << poly.obwod()<< endl;
      cout<< "pole  : " << poly.pole()<< endl;  
    }
    catch ( const string& e ){ cout << e << endl;}
    catch ( const blad&   e ){ cout << e ;}
    file.close();
  }

  #ifdef _WIN32
    system("PAUSE");
  #endif
  return 0;
}
catch (int err){
  switch (err) {
    case 0: cout << err <<": Zła liczba parametrów programu.\n";
    break;
    case 1: cout << err <<": Zła nazwa pliku z danymi.\n";
    break;
    case 2: cout << err <<": Złe rozszerzenie pliku z danymi - musi być *.txt .\n";
    break;
    case 3: cout << err <<": Brak pliku o nazwie "<< argv[1] << " .\n";
  }
}
catch ( ... ) { cout << "Nieznana sytuacja wyjątkowa.\n"; }

