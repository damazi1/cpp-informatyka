#include <iostream>

using namespace std;



struct SWezel
{
    string dane;
    SWezel *wezel;

};

struct SLista
{
    SWezel *pierwszyw;
    int n;
};

int inicjuj(SLista &lista)
{
    lista.pierwszyw = nullptr;
    lista.n = 0;
    return 0;
}

SWezel *ostatni(SWezel *n)
{
    if (n == nullptr)
    {
        return nullptr;
    }
    SWezel *temp = n;
    while (temp->wezel != nullptr)
    {
        temp = temp->wezel;
    }
    return temp;
}

SWezel *nowy(string dane)
{
    SWezel *wezel = new SWezel;
    wezel->dane = dane;
    wezel->wezel = nullptr;
    return wezel;
}

int dodaj(SLista &lista, string dane)
{
    SWezel *wezel = nowy(dane);
    if (lista.pierwszyw == nullptr)
    {
        lista.pierwszyw = wezel;
        lista.n++;
    }
    else
    {
        SWezel *ostatni1 = ostatni(lista.pierwszyw);
        ostatni1->wezel = wezel;
        lista.n++;
    }
    return 0;
}

void wyswietl(SLista& lista){
    SWezel* wezel=lista.pierwszyw;
    for (int i=0;i<lista.n;i++){
        cout<<wezel->dane<<endl;
        wezel=wezel->wezel;
    }
}

int usun(SLista& l,string& dane){
    SWezel *wezel=ostatni(l.pierwszyw);
    if(wezel==nullptr){
        cerr<<"Ostatni węzeł jest pusty"<<endl;
        return -1;
    }
    
    dane=wezel->dane;
    if(wezel){
        delete wezel;
        wezel=nullptr;
        l.n--;
    }
    wezel=l.pierwszyw;
    for(int i=0;i<l.n-1;i++){
        wezel=wezel->wezel;        
    }
    wezel->wezel=nullptr;
    return 0;
}

int usun(SLista& l){
    SWezel* wezel=l.pierwszyw;
    SWezel* temp;
    for(int i=0;i<l.n;i++){
        temp=wezel->wezel;
        if(wezel){
            delete wezel;
            wezel=nullptr;
        }
        wezel=temp;
    }
    l.n=0;
    return 0;
}

int main()
{
    SLista lista;
    inicjuj(lista);
    dodaj(lista, "Dane1");
    dodaj(lista, "Dane2");
    dodaj(lista, "Dane3");
    dodaj(lista, "Dane4");
    dodaj(lista, "Dane5");
    wyswietl(lista);
    string dane;
    usun(lista,dane);
    cout<<dane<<endl;
    wyswietl(lista);
    usun(lista);
    wyswietl(lista);
    return 0;
}