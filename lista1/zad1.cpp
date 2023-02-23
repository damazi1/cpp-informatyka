#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  cout << "petla for"<<endl;
  for (int i=0;i<n;i++){
    cout<<i<<"Dawid Ziora"<<endl;
  }
  cout<<"Petla while"<<endl;
  int i=0;
  while(i<n){
    cout<<i<<"Dawid Ziora"<<endl;
    i++;
  }
  cout <<"petla dowhile"<<endl;
  i=0;
  do{
    cout<<i<<"Dawid Ziora"<<endl;
    i++;
      }
  while(i<n);
  return 0;
}
