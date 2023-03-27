#include <iostream>

using namespace std;

int main(){
  char imieinaz[]="Dawid Ziora";
  int n=0,i=0;
  cout<<"Podaj liczbe powtorzen: ";
  cin>>n;

  cout<<"\nPetla for: \n";
  
  for(i=0;i<n;i++){
    cout<<i+1<<imieinaz<<endl;
  }
  i=0;
  cout<<"\nPetla while: \n";
  while(i<n){
    cout<<i+1<<imieinaz<<endl;
    i++;
  }
  i=0;
  cout<<"\nPetla dowhile: \n";
  do{
    cout<<i+1<<imieinaz<<endl;
    i++;
  }
  while(i<n);
  
  
  return 0;
}
