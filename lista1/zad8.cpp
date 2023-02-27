#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

void pobierz(float &a,float &b,float &c){
    cout<<"podaj 3 liczby a,b,c :";
    cin>>a>>b>>c;
}
bool sprawdz(float a,float b,float c){
    if(a+b<=c||a+c<=b||b+c<=a){
        return false;
    }
    else{
        return true;
    }
}
float pole(float a,float b,float c){
    float polea;
    if (sprawdz(a,b,c)==true)
    {
        polea=(a+b+c)/2;
        return polea;
    }
    else{
        return 0;
    }
}
float poleherona(float a,float b, float c){
    float poleherona;
    if (sprawdz(a,b,c)==true)
    {
        poleherona=sqrt(pole(a,b,c)*(pole(a,b,c)-a)*(pole(a,b,c)-b)*(pole(a,b,c)-c));
        return poleherona;
    }
    else{
        return 0;
    }
}
int main(){
    float a,b,c;
    pobierz(a,b,c);
    cout<<"z podanych liczb ";
    if(sprawdz(a,b,c)==true){
        cout<<"da się zbudować trójkąt"<<endl;
        }
        else
        {
        cout<<"nie da się zbudować trójkąta"<<endl;
        }
    cout<<"pole: "<<pole(a,b,c)<<" \npole herona: "<<poleherona(a,b,c)<<endl;
  return 0;
}