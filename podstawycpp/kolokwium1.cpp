#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int **utworz(const unsigned int n,const unsigned int m){
  int **tab=new int *[n];
  for(unsigned int i=0;i<n;i++){
    tab[i]=new int [m];
  }
  int min,max;
  cout<<"Podaj minimalna wartosc i maksymalna wartosc jaka przyjmuje tablica : ";
  cin>>min>>max;
  for(unsigned int i=0;i<n;i++){
    for(unsigned int j=0;j<m;j++){
      tab[i][j]=rand()%(max+1-min)+min;
    }
  }
  
  return tab;
}

void wypisz(int **tab,const unsigned int n,const unsigned int m){
  for(unsigned int i=0;i<n;i++){
    for(unsigned int j=0;j<m;j++){
      cout<<tab[i][j]<<'\t';
    }
    cout<<endl;
  }
}

void min_max(int** tab,const unsigned int n,const unsigned int m,int &min, int &max){
  min=tab[0][0];
  max=tab[0][0];
  for(unsigned int i=0;i<n;i++){
    for(unsigned int j=0;j<m;j++){
      if(tab[i][j]>max){
	max=tab[i][j];
      }
      if(tab[i][j]<min){
	min=tab[i][j];
      }
    }
  }
}

void usun (int ** tab,const unsigned int n){
  if(tab){
    for(unsigned int i=0;i<n;i++){
      delete [] tab[i];
    }
    delete [] tab;
    tab=nullptr;
  }
}

void filtruj1(ifstream& fin,){

}

int main(int argc,char *argv[]){
  if(argc!=1){
    cerr<<"bledna ilosc argumentow()"<<endl;
    cout<<"Poprawny zapis to: ./nazwa "<<endl;
    return 1;
  }
  srand(time(NULL));
  int n,m;
  cout<<"Podaj wielkosci tablicy 2-wymiarowej(x,y): ";
  cin>>n>>m;
  int min,max;
  int** tab=utworz(n,m);
  wypisz(tab,n,m);
  cout<<endl;
  min_max(tab,n,m,min,max);
  cout<<"Liczba minimalna to: "<<min<<" \nMakymalna to: "<<max<<endl;

  ifstream fin;
  fin.open(argv[1]);



  fin.close();

  usun(tab,n);
  


  
  return 0;
}
