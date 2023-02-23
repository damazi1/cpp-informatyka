#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

void pobierz(int &a,int &b,int &c){
    cout<<"podaj 3 liczby:";
    cin>>a>>b>>c;
}
int sprawdz(int a,int b,int c){
    if(a+b>c){
        return 1;
    }
    else if(a+c>b){
        return 1;
    }
    else if(b+c>a){
        return 1;
    }
    else{
        return 0;
    }
}
float pole(int a,int b,int c){
    float pole;
    if (sprawdz(a,b,c)==1)
    {
        pole=(a+b+c)/2;
        return pole;
    }
    else{
        return 0;
    }
}
float poleherona(int a,int b, int c){
    float poleherona;
    if (sprawdz(a,b,c)==1)
    {
        poleherona=sqrt(pole(a,b,c)*(pole(a,b,c)-a)*(pole(a,b,c)-b)*(pole(a,b,c)-c));
        return poleherona;
    }
    else{
        return 0;
    }
}
int main(){
    int a,b,c;
    pobierz(a,b,c);
    cout<<"twoja liczba jest: "<<sprawdz(a,b,c);
    cout<<"pole: "<<pole(a,b,c)<<" \n pole herona: "<<poleherona(a,b,c)<<endl;
  return 0;
}