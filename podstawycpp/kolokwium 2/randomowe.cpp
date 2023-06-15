#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

float losuj(int min = 0, int max = 10)
{
    float los = 0;
    los = (float)rand()/(float)RAND_MAX*(max-min)+min;
    los = (float)rand()%max/(float)RAND_MAX;
    return los;
}

int main(int argc,char**argv)
{
    srand(time(NULL));
    cout<<losuj(0,15);
    return 0;
}