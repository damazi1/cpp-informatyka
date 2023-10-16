#include <iostream>
#include <fstream>
#ifdef _WIN32
  #include <windows.h>
#endif // _WIN32 and _WIN64 too

using namespace std;

/*
  Wszędzie gdzie znajdziesz ???_xx poeksperymentuj  
*/

class adres{
  string mia, ul;
  int nr;
public:
 
/*  // ???_03
  adres(){}
/*/
  adres()://resztę dopisz sam {}
// */
  
//  adres(const string& a1, const string& a2, int a3) //resztę dopisz sam
  ostream& view(ostream& out)const{
    return out << mia << ", " << ul << ", " << nr << '\n';
  }

  friend 
  ostream& operator<< (ostream& out, const adres& r);
};
ostream& operator<< (ostream& out, const adres& r){
  return r.view(out);  
}

class osoba{
  string im;
  int wi;
  adres* adr;
public:
//  osoba() //resztę dopisz sam
  osoba(const string& a1, int a2, const adres& a3):im(a1), wi(a2), adr(new adres(a3)){}

/*
  osoba(const osoba& a1) //resztę dopisz sam
  osoba& operator=(const osoba& a1){
    // resztę dopisz sam
    return *this;
  }
// */
  ~osoba(){ delete adr; }

  // resztę dopisz sam - potrzebne są metody miasto() w tej klasie


  friend 
  ostream& operator<< (ostream& out, const osoba& r);
};
ostream& operator<< (ostream& out, const osoba& r){
  // resztę dopisz sam
  return out ;  
}

int main(){
  #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); 
  #endif


  adres* wsk = new adres("Częstochowa", "Dąbrowskiego", 73);

/*                     // ???_01
  cout <<  wsk << '\n'; // Zastanów się czym różnią się te dwie linijki kodu 
/*/                     // jaki jest w jednym i drugim przypadku typ  
  cout << *wsk << '\n'; // prawego argumentu operatora << . Żeby ten fragment kodu się wykonał musisz przeciążyć operator<<  .                      
// */

    

  adres a1(*wsk);     // ???_02 Czy wiesz co tu się dzieje? Co jest wartością wyłuskania wskaźnika wsk ?
                      // Tu wywołałeś konstruktor kopiujący. Nie musiałeś go definiować. Zadziała mechanizm kopiowania składowa po składowej.
  
  delete wsk;         // Skończył się czas trwania dynamicznego obiektu, na który wskazywał wskaźnik wsk.  
  wsk=nullptr;        // Sam wskaźnik jednak nadal jest. Od tej pory nie wskazuje na żaden obiekt typu adres.
                      // Ma wartość 0 (zero).
           
  const adres* wsk1 = new adres("Łódź", "Piotrkowska", 33);

  cout << a1 << '\n';
  cout << *wsk1 << '\n';

  adres a2;           // Tutaj definiujesz obiekt typu adres z użyciem konstruktora domyślnego.
                      // Możesz go, co prawda, zdefiniować tak, by nie było w nim listy inicjalizacyjnej.
                      // Składowe typu string nie będą miały żadnych wartości (długość łańcucha znaków będzie zero), - więcej: https://en.cppreference.com/w/cpp/string/basic_string
                      // natomiast pole numeru budynku będzie miało wartość bliżej nieokreśloną. 
                      // Zdefiniuj ten konstruktor jednak tak, 
  cout << a2 << '\n'; // by efektem instrukcji, którą widzisz po lewej stronie było: brak, brak, 0  
                      // ???_03 Poeksperymentuj. Konstruktor domyślny z listą inicjalizacyjną i bez.

  a2 = a1;            // Tu wywołałeś operator przypisania. Nie musisz go definiować. Zadziała mechanizm kopiowania składowa po składowej.  
  cout << a2 << '\n';

  osoba os1("Ala", 25, *wsk1); //By w ten sposób zdefiniować obiekt typu osoba w klasie musisz zdefiniować odpowiedni konstruktor.
  delete wsk1;

  cout << os1 << '\n';
  

  osoba os2(os1);     // ???_04 Ta definicja, analogicznie jak w przypadku ???_02 , jest możliwa jeśli nie zdefiniujesz konstruktora kopiującego.
                      // Ale! Ale program nie będzie działać prawidłowo. Domyślnie działający mechanizm kopiowania składowa po składowej
                      // sprawi, że pole adr (obiektu os2) będzie miało tę samą wartość co pole adr obiektu os1.
                      // Teraz już dwa obiekty typu osoba będą "chciały zarządzać" raz alokowanym dynamicznie obiektem typu adres.
                      // Taka sytuacja wcześniej czy później musi się skończyć źle.
                      // Skoro os2 ma być kopią os1 to musisz zadbać o to, 
                      // by os2 dysponował własną kopią wartości obiektu typu adres  
                      // a nie kopią adresu obiektu typu adres.

                      // Jeśli dalej masz kłopot ze zrozumieniem co tu się dzieje to posłużę się takim oto przykładem.
                      // Paweł i Gaweł siedzą w jednym domku.
                      // Paweł na górze a Gaweł na dole (dwa obiekty tego samego typu).
                      // Paweł właśnie kupił sobie nowy samochód. 
                      // Gaweł - zazdośnik - chce mieć taki sam.
                      // Czy wystarczy Gawłowi, że wie gdzie (pod jakim adresem) Paweł parkuje samochód.
                      // Czy samochód Pawła ma być wspólnym zasobem obydwu gagatków?
                      // Jeśli Gaweł chce mieć to samo co Paweł to musi nabyć taki sam samochód. 
                      // Mieć własną kopię obiektu a nie informację o adresie garażowania własności Pawła. 
             
  os1.miasto()="Zmieniono miasto osoby 1.";  // Czyli Paweł uszkodził swój samochód

  cout << os2 << '\n';                       // Czy samochód Gawła ma mieć takie samo uszkodzenie ?
                                             // ???_05 Zakomentuj/odkomentuj definicję konstruktora kopiującego
                                             // Porównaj wyniki działania programu.
 
  osoba os3;            // Tu potrzebny jest konstruktor domyślny klasy osoba
  cout << os3 << '\n';
  
  os3 = os2;            // Od teraz os3 ma być kopią os2. Taka operacja jest możliwa nawet jeśli w klasie osoba
                        // nie zdefiniowałeś operatora przypisania. Zadziała mechanizm kopiowania składowa po składowej. 
                        // Jeśli jednak nie zadbasz o to, by skopiowana zastała wartość obiektu typu adres
                        // to efekt będzie taki sam jak: patrz ???_04
                        // ???_06 Zakomentuj/odkomentuj definicję operatora przypisania 
                        // Porównaj wyniki działania programu. 
  
  os1.miasto()="Drugi raz zmieniono miasto osoby 1.";  

  cout << os3 << '\n';  

  #ifdef _WIN32
    system("PAUSE");
  #endif
  return 0;
}