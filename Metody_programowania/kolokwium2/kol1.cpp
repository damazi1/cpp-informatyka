#include <iostream>

using namespace std;
class robot{
    protected:
    string opis;
    int liczba;
    public:
    robot():liczba(0){}
    robot(const string& a):opis(a),liczba(0){}
    robot(const string& a,const int&b):opis(a),liczba(b){}

    virtual ~robot(){}
    virtual ostream& praca() const=0;
    robot& operator-=(const int& l){
        liczba-=l;
        return *this;
    }
};

class rt1 : public robot{
    protected:
    public:
    rt1(){}
    rt1(const string& a):robot(a){}
    ~rt1(){}

    ostream& praca()const{
        return cout<<opis<<endl;
    }
};
class rt2 : public robot{
    protected:
    public:
    rt2(){}
    rt2(const string& a,const int l):robot(a,l){}
    ~rt2(){}

    ostream& praca()const{
        return cout<<opis<<" "<<liczba<<endl;
    }

};
int main() try {
    const rt1 odbior("odebrano gotowy produkt");
    robot * linia[5];

    linia[0]=new rt1("polozono");
    linia[1]=new rt2("uderzono",5);
    linia[2]=new rt2("prawo",4);
    linia[3]=new rt2("uderzono",7);
    linia[4]=new rt1(odbior);

    * linia[3]-=5;
    for (int i=0;i<5;i++){
        linia[i]->praca();
        delete linia[i];
    }

    return 0;
}

catch (...){
    cout <<"Coś poszło nie tak!!"<<endl;
}