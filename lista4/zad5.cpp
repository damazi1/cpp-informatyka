#include<iostream>
#include<cstring>
using namespace std;
void szyfruj(char src[],char key) {
   size_t n = strlen(src);
   for (size_t i = 0; i < n; i++){
      src[i] = src[i] ^ key;
      cout<<src[i];
   }
}
int main(int argc,char*argv[]){
    if(argc!=3){
        cerr<<"Nieprawidłowa ilośc przekazanych argumentów(3)!"<<endl;
        cout<<"Wymagane argumenty to: ./nazwa,napis,klucz"<<endl;
        return 1;
    }
   cout<<"Zakodowany napis: ";
   szyfruj(argv[1],argv[2][0]);
   cout<<"\nOdkodowany napis:";
   szyfruj(argv[1],argv[2][0]);
   cout<<endl;
   return 0;
}