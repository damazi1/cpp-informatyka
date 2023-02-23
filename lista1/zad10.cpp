#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

int horner(int*w,int stopien ,int x){
    if(stopien==0){
        return w[0];
    }
    else{
    return x*horner(w,stopien-1,x)+w[stopien];
    }
}
int main(){
    int *wsp;
    int stopien, arg;
    cout<<"Podaj stopień: ";
    cin>>stopien;

    wsp=new int[stopien+1];

    for(int i=0;i<=stopien;i++){
        cout<<"podaj współczynnik stojący przy potędze: "<<stopien-i<<"  ";
        cin>>wsp[i];
    }
    cout<<"podaj argumeny: ";
    cin>>arg;

    cout<<"w("<<arg<<") = "<<horner(wsp,stopien,arg)<<endl;
    if(wsp){
    delete [] wsp;
    wsp=0;
       }
    return 0;    
}