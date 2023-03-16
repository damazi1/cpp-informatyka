#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>

using namespace std;

 
int main(int argc,char *argv[])
{
size_t n=strlen(argv[1]);
size_t i=0,j=n-1;
// i - pokazuje na kolejne litery wyrazu począwszy od początku, j - zaczyna od końca
// funkcja length() wywołana na obiekcie string zwraca jego długość
for (; i < j; i++, j--)
{
// pominiecie spacji
while (argv[1][i] == ' ') i++;
while (argv[1][j] == ' ') j--;
while (argv[1][i] == '?') i++;
while (argv[1][j] == '?') j--;
while (argv[1][i] == '!') i++;
while (argv[1][j] == '!') j--;
while (argv[1][i] == '.') i++;
while (argv[1][j] == '.') j--;
if (argv[1][i] != argv[1][j])
break;
}
if (i < j)
cout << "Podany wyraz nie jest palindromem" << endl;
else
cout << "Podany wyraz jest palindromem" << endl;
 
return 0;
}