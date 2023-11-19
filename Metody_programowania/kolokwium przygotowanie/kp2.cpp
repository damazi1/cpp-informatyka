#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

class K1
{
    string *p1;

public:
    K1() : p1(nullptr) {}
    K1(const string &pa, const string &pb)
    {
        p1 = new string[2];
        p1[0] = pa;
        p1[1] = pb;
    }

    K1(const K1& k){
        p1=new string [2];
        p1[0]=k.p1[0];
        p1[1]=k.p1[1];
    }

    K1 operator=(const K1& k){
        if(p1){
            delete []p1;
            p1=nullptr;
        }
        p1=new string [2];
        p1[0]=k.p1[0];
        p1[1]=k.p1[1];
        return *this;
    }
    
    ~K1() { delete[] p1; }

    ostream &view (ostream& out)const {
        if(p1){
            out<<p1[0]<<" "<<p1[1]<<endl;
            return out;  
        }
        return out;
    }
    friend ostream &operator<<(ostream&,const K1&);
};
    ostream &operator<<(ostream& out,const K1& r){
        return r.view(out);
    }

class K2
{
    K1 w1;
    double w2;

public:
    K2() : w2(0.0) {}
    K2(const string &p1, const string &p2, const double &w) : w1(K1(p1, p2)), w2(w) {}
    
    K2 operator=(const K2& k){
        w1=k.w1;
        w2=k.w2;
        return *this;
    }

    K2 operator-(const double& a){
        w2-=a;
        return *this;
    }

    ostream &view (ostream& out)const {
        w1.view(out);
        out<<w2<<endl;
        return out;
    }
    
    friend ostream &operator<<(ostream&,const K2&);
};

    ostream &operator<<(ostream& out,const K2& r){
        return r.view(out);
    }
int main()
{
    K2 ob1, ob2;
    const K2 *wsk1 = new K2("kawa", " z mlekiem", 4.50);
    cout <<*wsk1;
    const K2 ob3(*wsk1);
    delete wsk1;
    wsk1 = nullptr;

    const K2 *wsk2 = new K2(ob3);
    ob2 = *wsk2;
    cout<<ob1<<*wsk2;
    delete wsk2;
    wsk2 = nullptr;

    cout<<ob2;
    cout<<ob2-1.25;

    return 0;
}