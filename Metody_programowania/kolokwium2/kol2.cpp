#include <iostream>

using namespace std;

class komunikator{
    protected:
    string opis;
    int liczba;
    static int liczba_ob;
    public:
    komunikator():liczba(0){liczba_ob++;}
    komunikator(const string& s):opis(s),liczba(0){liczba_ob++;}
    komunikator(const string& s,const int& l):opis(s),liczba(l){liczba_ob++;}
    komunikator(const komunikator& k):opis(k.opis),liczba(k.liczba){liczba_ob++;}
    virtual ~komunikator(){liczba_ob--;}
    static int liczba_obiektow(){return liczba_ob;}
    virtual ostream& pokaz(ostream&)const=0;
    friend ostream& operator<<(ostream&,const komunikator&);
    komunikator& operator+=(const int& i){
        liczba+=i;
        return *this;
    }
};
ostream& operator<<(ostream& out,const komunikator& k){
    return k.pokaz(out);
}

class k1 :public komunikator{
    public:
    k1(){}
    k1(const string& a):komunikator(a){}
    ~k1(){}
    ostream& pokaz(ostream& out)const{
        if(opis.empty())
            throw string("Brak danych");
        return out<<opis<<endl;
    }
};
class k2:public komunikator{
    public:
    k2(){}
    k2(const string& a,const int &b):komunikator(a,b){}
    ~k2(){}
    ostream& pokaz(ostream& out)const{
        if(opis.empty())
            throw string("Brak danych");
        return out<<opis<<" "<<liczba<<endl;
    }
};

int komunikator::liczba_ob=0;

int main(){
    const k1 koniec("Koniec komunikatow");
    komunikator *linia[5];
    
    linia[0]=new k1("Temperatura powietrza : ");
    linia[1]=new k2("Czestochowa",5);
    linia[2]=new k1("Opady śniegu (cm): ");
    linia[3]=new k2("Katowice",10);
    linia[4]=new k1(koniec);
    *(static_cast<k2*>(linia[1]))+=2;
    *(static_cast<k2*>(linia[3]))+=2;
    for(int i=0;i<5;i++){
        cout<<*linia[i];
        delete linia[i];
    }

    cout<<"Liczba dzialajacych obiektow :"<<komunikator::liczba_obiektow()<<endl;

    linia[0]=new k1("Temperatura powietrza : ");
    linia[1]=new k2;
    linia[2]=new k1("Opady śniegu (cm): ");
    linia[3]=new k2;
    linia[4]=new k1(koniec);

    cout<<"Liczba dzialajacych obiektow :"<<komunikator::liczba_obiektow()<<endl;

    for (int i=0;i<5;i++)try{
        cout<<*linia[i];
    }catch (const string& e){cout<<e<<endl;}

    return 0;
}