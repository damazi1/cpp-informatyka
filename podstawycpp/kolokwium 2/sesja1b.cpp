#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void zapisz(string wej, string src, size_t n)
{
    fstream fout;
    fout.open(wej);
    if (!fout.good())
    {
        cerr << "błąd na strumieniu wyjscia" << endl;
        fout.clear();
        fout.close();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fout << src <<'\n';
        if (!fout.good())
        {
            cerr << "błąd na strumieniu wyjscia" << endl;
            fout.clear();
            fout.close();
            return;
        }
    }
    fout.close();
}

int main()
{
    zapisz("wyj.txt","hello",3);
    return 0;
}