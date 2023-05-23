#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

float losuj(int min = 0, int max = 10)
{
    float los = 0;
    los = (float)rand()/(float)RAND_MAX*(max-min)+min;
    return los;
}

int main(int argc,char**argv)
{
    srand(time(NULL));
    int a=atoi(argv[1]);
    cout<<a<<endl;
    return 0;
}