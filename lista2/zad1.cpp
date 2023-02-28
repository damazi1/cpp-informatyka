#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

long long pot_bin(long long a,unsigned int n){
	if(n==0){
		return 1;
	}
	if(n%2 == 1){
		return a * pot_bin(a, n-1);
	}
	long long w= pot_bin(a,n/2);
	return w*w;
}

int main(){
	unsigned int n;
	long long a;
	cout<<"podaj a: ";
	cin>>a;
	cout<<"podaj n: ";
	cin>>n;
	cout<<a<<" do potegi "<<n<<" wynosi "<<pot_bin(a,n);
	return 0;
}