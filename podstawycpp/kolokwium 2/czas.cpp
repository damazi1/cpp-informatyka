#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

time_t ustaw (){
    tm czas = {0};
    czas.tm_year=rand()%123;
    czas.tm_mon=rand()%12;
    czas.tm_mday=rand()%30+1;
    czas.tm_hour=rand()%24;
    czas.tm_min=rand()%60;
    czas.tm_sec=rand()%60;
    time_t czas1=mktime(&czas);
    return czas1;
}

unsigned long porownaj(time_t czas1){
    time_t czas2=(time(nullptr));
    unsigned long dni = difftime(czas2,czas1)/(60*60*24);
    return dni;
}

int main(){
    srand(time(NULL));
    time_t czas1=ustaw();
    cout<<"Liczba dni między datami "<<setw(10)<<setfill('X')<<porownaj(czas1);
    return 0;
}