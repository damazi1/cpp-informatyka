#include <iostream>

using namespace std;

//Totolotek dla kilku kuponów !!

int main(int argc,char *argv[]){
    if(argc!=1){
        cerr<<"Podana bledna ilosc argumentow(1)"<<endl;
        cout<<"Poprawny zapis to ./nazwa"<<endl;
        return 1;
    }
    return 0;
}