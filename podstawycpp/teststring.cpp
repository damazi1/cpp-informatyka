// istringstream::str
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <cstring>
#include <fstream>


using namespace std;

int main () {

  ifstream t;
  t.open("in.txt");
  string buffer;
  string line;
  while(t){
    getline(t, line);
    buffer+=line;  
  }
  t.close();

  istringstream iss(buffer);
  string slowo;
  while( iss >> slowo )
  {
      cout << slowo << endl;
  }
  return 0;
}