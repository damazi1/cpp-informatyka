#include<iostream>
using namespace std;

int main(){
    // int*p;
    // p=new int;
    // return 0;
    int *t;
    t=new int;
    *t=2;
    int a =10;
    t=new int;
    *t=a;
    delete t;
    t=0;
}