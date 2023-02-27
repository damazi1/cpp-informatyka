#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;
void viete(int a,int b,int c){
double x1,x2;
    double delta=(pow(b,2)-4*(a*c));
    if (delta>0){
        x1=(-b-sqrt(delta))/(2*a);
        x2=(c/(a*x1));
        cout <<"miejsca zerowe to "<<x1<<" i "<<x2<<endl;
    }
    else if(delta==0){
        x1=(-b)/(2*a);
        cout<<"miejsce zerowe to: "<<x1<<endl;
    }
    else{
        cout<<"nie ma miejsc zerowych"<<endl;
    }
}
int main(){
    double a,b,c;
    cout<<"Podaj zmienne a,b,c: ";
    cin>>a>>b>>c;
    viete(a,b,c);
       return 0;
}