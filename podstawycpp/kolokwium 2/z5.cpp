#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct SStudent
{
    string imie, nazwisko;
    string *wykaz;
    int n;

    SStudent()
    {
        imie = "";
        nazwisko = "";
        n = 0;
        wykaz = nullptr;
    }
    ~SStudent()
    {
        imie = "";
        nazwisko = "";
        n = 0;
        if (wykaz)
        {
            delete[] wykaz;
            wykaz = nullptr;
        }
    }
    bool wczytaj(ifstream &);
    bool wypisz(ostream &out = cout);
};

struct SLista
{
    string nazwa;
    int n;
    SStudent *student;

    SLista()
    {
        nazwa = "";
        n = 0;
        student = nullptr;
    }
    ~SLista()
    {
        nazwa = "";
        n = 0;
        if (student)
        {
            delete[] student;
            student = nullptr;
        }
    }
    bool wczytaj(ifstream &);
    bool wypisz(ostream &out = cout);
    double srednia(const SLista &);
    SStudent maksymalna();
};

int main(int argc,char **argv)
{
    if(argc!=3){
        cerr<<"podano błędną ilość argumentów (3)"<<endl;
        cout<<"Poprawny zapis to ./nazwa plik_wej plik_wyj"<<endl;
        return 1;
    }
    SLista lista;
    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    fout.open(argv[2]);
    if(!fin.good()&&!fout.good()){
        cerr<<"błąd podczas otwierania plików"<<endl;
        fin.clear();
        fin.close();
        fout.clear();
        fout.close();
        return 2;
    }
    if(lista.wczytaj(fin)){
        if(lista.wypisz()){
            cout<<"srednia niezaliczonych przedmiotów wynosi : "<<lista.srednia(lista)<<endl;
            SStudent student = lista.maksymalna();
            student.wypisz(fout);
        }
    }
    fin.close();
    fout.close();

    return 0;
}

bool SStudent::wczytaj(ifstream &fin)
{
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin >> imie;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin >> nazwisko;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin >> n;
    if (!fin.good())
    {
        cerr << "Błąd na strumieniu" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    if (n == 0)
    {
        wykaz = nullptr;
        return true;
    }
    if (n < 0)
    {
        cerr << "Podano nieprawidłową ilość niezaliczonych przedmiotów" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    else
    {
        wykaz = new string[n];
        for (int i = 0; i < n; i++)
        {
            fin >> wykaz[i];
            if (!fin.good())
            {
                cerr << "Błąd na strumieniu" << endl;
                fin.clear();
                fin.close();
                return false;
            }
        }
    }
    return true;
}

bool SStudent::wypisz(ostream &out)
{
    if (!out.good())
    {
        cerr << "Bląd na strumieniu wypisz" << endl;
        out.clear();
        return false;
    }
    cout << imie << '\t' << nazwisko << '\t' << n << '\t';
    for (int i = 0; i < n; i++)
    {
        cout << wykaz[i] << '\t';
    }
    cout << endl;
    if (!out.good())
    {
        cerr << "Bląd na strumieniu wypisz" << endl;
        out.clear();
        return false;
    }
    return true;
}

bool SLista::wczytaj(ifstream& fin){
    if (!fin.good())
    {
        cerr << "Bląd na strumieniu wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin>>nazwa;
    if (!fin.good())
    {
        cerr << "Bląd na strumieniu wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    fin>>n;
    if (!fin.good())
    {
        cerr << "Bląd na strumieniu wczytaj" << endl;
        fin.clear();
        fin.close();
        return false;
    }
     if (n == 0)
    {
        cout<<"Brak studentów na liście"<<endl;
        student = nullptr;
        return true;
    }
    if (n < 0)
    {
        cerr << "Podano nieprawidłową ilość Studentów" << endl;
        fin.clear();
        fin.close();
        return false;
    }
    else{
        student=new SStudent[n];
        for (int i=0;i<n;i++){
            student[i].wczytaj(fin);
        }
    }
    return true;
}

bool SLista::wypisz(ostream& out){
    if(!out.good()){
        cerr<<"Bląd na strumieniu wyjscia"<<endl;
        out.clear();
        return false;
    }
    out<<nazwa<<'\n'<<n<<'\n';
    for(int i=0;i<n;i++){
        student[i].wypisz(out);
    }
    if(!out.good()){
        cerr<<"Bląd na strumieniu wyjscia"<<endl;
        out.clear();
        return false;
    }
    return true;
}

double SLista::srednia(const SLista& lista){
    double ile=0;
    int stu=0;
    for(int i=0;i<lista.n;i++){
        ile+=lista.student[i].n;
        stu++;
    }
    return ile/stu;
}

SStudent SLista::maksymalna(){
    int max=0;
    int ktory=0;
    for(int i=0;i<n;i++){
        if(student[i].n>max){
            max=student[i].n;
            ktory=i;
        }
    }
    SStudent studen;
    studen.imie=student[ktory].imie;
    studen.nazwisko=student[ktory].nazwisko;
    studen.n=student[ktory].n;
    studen.wykaz=new string [studen.n];
    for(int i=0;i<studen.n;i++){
        studen.wykaz[i]=student[ktory].wykaz[i];
    }
    return studen;
}