#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

void wypelnij(int*t,const int n){
    for (int i=0;i<n;i++){
        t[i]=rand()%100;
    }
}
void wypisz(int*t,const int n){
    for(int i=0;i<n;i++){
        cout<<t[i]<<endl;
    }
}
void sortuj(int*t,const int n){
    int pom;
    for(int i=1;i<n;i++){
        if(t[i-1]>t[i]){
            pom=t[i-1];
            t[i-1]=t[i];
            t[i]=pom;
            i=0;
        }
    }
}
int binarnie(int*t,const int n,const int element){
    int poz;
    sortuj(t,n);
    int p=n-1;
    int l=0;
    while(t[0]<=t[n-1]){
        poz=(l+p)/2;
        if (t[poz]==element){
            return poz;
        }
        if(t[poz]>element){
            p=poz-1;
        }
        else{
            l=poz+1;
        }
    }
    return -1;
}

int main(){
  srand(time(NULL));
    int n;
    cout<<"podaj n: ";
    cin>>n;
    int element;
    cout<<"podaj element: ";
    cin>>element;
    int*t=new int [n];
    wypelnij(t,n);
    wypisz(t,n);
    cout<<"posortowany ciąg"<<endl;
    sortuj(t,n);
    wypisz(t,n);
    cout<<"element znajduję się na indeksie: "<<binarnie(t,n,element)<<endl;
      if(t){
    delete[]t;
    t=0;
  }
  return 0;

}