#include <iostream>
#include <fstream>
using namespace std;

class K1{
    string *p1;
    public:
    K1():p1(new string[2]){}
    K1(const string&a,const string&b):p1(new string[2]){
        p1[0]=a;
        p1[1]=b;
    }
    K1(const K1& k):p1(new string[2]){
        p1[0]=k.p1[0];
        p1[1]=k.p1[1];
    }
    
    ~K1(){delete[]p1;}

    K1 operator=(const K1&k){
        if(p1){
            delete []p1;
            p1=nullptr;
        }
        p1=new string[2];
        p1[0]=k.p1[0];
        p1[1]=k.p1[1];
        return *this;
    }
    K1 dodaj(const string& s){
        p1[1]+=s;
        return *this;
    }
    
    K1 dodaj1(const string& s){
        p1[0]=s+p1[0];
        return *this;
    }
    ostream &view(ostream& out)const{
        if(p1){
            out<<p1[0]<<" "<<p1[1]<<endl;
        }
        return out;
    }
    friend ostream &operator<<(ostream& out,const K1& r);
};
 ostream &operator<<(ostream& out,const K1& r){
    return r.view(out);
 }
class K2{
    K1 w1;
    double w2;
    public:
    K2():w1(K1()),w2(0){}
    K2(const string&a,const string&b,const double&c):w1(K1(a,b)),w2(c){}
    K2(const K2&k){
        w1=k.w1;
        w2=k.w2;
    }
    K2 operator=(const K2& k){
        w1=k.w1;
        w2=k.w2;
        return *this;
    }

    K2 operator-(const double& l){
        w2=w2-l;
        return *this;
    }
    K2 operator+=(const double& l){
        w2+=l;
        return *this;
    }
    K2 operator+(const string& s){
        w1.dodaj(s);
        return *this;
    }
    friend K2 operator+(const string&s ,K2& k){
        k.w1.dodaj1(s);
        return k;
    }
    ostream &view(ostream& out)const{
        w1.view(out);
        out<<w2<<endl;
        return out;
    }
    friend ostream &operator<<(ostream& out,const K2& r);
};
 ostream &operator<<(ostream& out,const K2& r){
    return r.view(out);
 }

int main(){
    K2 ob1,ob2;
    const K2 * wsk1 =new K2("kawa ","z mlekiem",4.50);
    const K2 ob3(*wsk1);
    delete wsk1;
    wsk1=nullptr;

    const K2* wsk2=new K2(ob3);

    ob2=*wsk2;
    cout<<ob1<<*wsk2;
    delete wsk2;
    wsk2=nullptr;

    cout<<ob2;
    cout<<ob2-1.25;
    cout<<"*****3*****"<<endl;

    K2 tab[4];
    ifstream fin("data.txt");
        for(int i=0;i<4;i++){
            string a,b;
            double c;
            fin>>a;
            fin>>b;
            fin>>c;
            tab[i]=K2(a,b,c);
        }
    for(int i=0;i<4;i++){
        tab[i]+=1;
        cout<<tab[i];
    }
    cout<<"*****4*****"<<endl;
    tab[1]=tab[1]+" with sugar";
    tab[3]="hot "+tab[3];
    for(int i=0;i<4;i++){
        cout<<tab[i];
    }
    cout<<"*****5*****"<<endl;
    return 0;
}