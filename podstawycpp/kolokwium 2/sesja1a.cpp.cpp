#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void kopiuj(const string src, char *&dest)
{
    size_t n = src.size();
    dest = new char[n];
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

string wstaw(const string src, const char s, size_t pos)
{
    string dest = src;
    dest.insert(pos, 1, s);
    return dest;
}

string wstaw(const string src, const string s, size_t pos)
{
    string dest = src;
    dest.insert(pos, s);
    return dest;
}

string wytnij(const string src, size_t n)
{
    string dest = src;
    dest.erase(0, n);
    return dest;
}

int szukaj(const string src, const char s)
{
    int n = src.find(s);
    return n;
}
int szukaj(const string src, const char *s)
{
    int n = src.find(s);
    return n;
}

int porownaj(const string s1,const string s2){
    if(s1==s2)return 0;
    if(s1<s2)return -1;
    else return 1;
}

int main()
{
    string src = {"Ala ma kotka"};
    char *dest = nullptr;
    kopiuj(src, dest);
    cout << dest << endl;
    char *dest1 = new char[src.size()];
    strcpy(dest1, src.c_str());
    cout << dest1 << endl;
    string dest2 = wstaw(src, 'X', 4);
    cout << dest2 << endl;
    string dest3 = wstaw(src, "Kuklki sa fajne ", 4);
    cout << dest3 << endl;
    string dest4 = wytnij(src, 4);
    cout << dest4 << endl;
    cout << szukaj(src, 'm') << endl;
    cout << szukaj(src, "kotka") << endl;
    cout<< porownaj(src,src)<<endl;

    return 0;
}