#include <iostream>
#include <cmath>
#ifdef _WIN32
  #include <windows.h>
#endif // _WIN32 and _WIN64 too

using namespace std;

/*
  Wszędzie gdzie znajdziesz ???_xx poeksperymentuj  
*/

//*
class point{
  double tab[3];
public:
  //...
  //Jeśli zastanawiasz się, czy powinieneś zdefiniować konstruktor kopiujący i operator przypisania to wykonaj 
  //eksperyment ???_02 - znajdziesz go na samym końcu przykładu.
};

// */


//...

int main(){

  double x[2][3] = { {1.0, 1.0, 1.0},
                     {1.0, 2.0, 3.0} }; // Przypomnij sobie co to są tablice, jak należy interpretować tablice wielowymiarowe.
                                        // Jaki jest typ zmiennej x.
                                        // Jak należy interpretować x[0], czy x[1].
                                        // Jeśli nie wiesz to popatrz jak zapisałem łańcuch inicjujący tablicę.
                                        // Mogłem to zrobić np. tak: x[2][3] = {1.0, 1.0, 1.0, 1.0, 2.0, 3.0};
                                        // Chciałem jednak uwidocznić drugi wymiar.
                                        // Sposób inicjowania tablicy wielowymiarowej podlega ściśle określonym regułom, które zapewne pamiętasz z podstaw informatyki.
                                        // ???_01
                                        // Jeśli masz jednak wątpliwości to poeksperymentuj - wyświetlaj wartości tablicy x jeśli zainicjujesz ją inaczej:
                                        // np.:
                                        // double x[2][3] = { 9.0 };
                                        // double x[2][3] = { 9.0, 8.0 };
                                        // double x[2][3] = { {9.0}, {8.0} };
                                        // double x[2][3] = { {9.0, 8.0}, {7.0} };
                                        // double x[2][3] = { {9.0, 8.0, 7.0} };


/*
  point p1(x[0]), p2(x[1]);             // Zapewne doskonale wiesz jak do funkcji przekazywać tablice za pomocą wskaźników.
                                        // C++ daje jeszcze jeden sposób. Jest nim przekazywanie tablicy przez referencję - dokładniej mówiąc przez referencję do tablicy o określonym typie i rozmiarze.
                                        // W tym zadaniu ten rozmiar to 3. 
                                        // Jest to bardzo bezpieczny i wygodny sposób - kompilator skrupulatnie dokona sprawdzenia typu i rozmiaru przekazywanej tablicy.
                                        // Tu właśnie definiujesz dwa obiekty typu point, gdzie wywoływany jest konstruktor, którego argumentem jest referencja do tablicy (znanego typu i rozmiaru) 
 



  const point p3(0.4, 0.2, 0.1);        
 
  cout << p1 << ", " << p2 << '\n';     
  cout << p3[0] << ' ' << p3[1] << ' ' << p3[2] << '\n';
 
  cout << p1.distance(point()) << endl; // distance( ) -analogicznie jak w zadaniu 3  
  cout << p3.distance(p1) << endl;

  cout << p1 + p2 << endl;              // Dwuargumentowy operator+ oraz operator- może być zdefiniowany jako metoda albo funkcja niebędąca metodą.  
  cout << p1 - p3 << endl;              // Wypróbuj obydwa sposoby implementacji operatorów np. + jako metoda, a - jako funkcja zewnętrzna 
                                        // Pamiętaj, że wynikiem działania tych operatorów jest nowy obiekt obliczony na podstawie wartości lewego i prawego argumentu funkcji.
                                        // Wskazówka - do implementacji tych operatorów wykorzystaj jeden z konstruktorów klasy point  

  cout << 3.14 * p2 << endl;            // Ta operacja może być zrealizowana wyłącznie za pomocą przeciążonego operatora, który nie może być metodą klasy. 
  cout << p2 * 3.14 << endl;            // To może być realizowane jak w przypadku operatorów + i -
 

  cout << (p1 < p3) << endl;                

  cout << (p1 == point(1.0, 1.0, 1.0)) << endl;

  cin >> p1;

  cout << p1 << '\n';
// */
 
/*  ???_02

  //W klasie point zdefiniuj: const double* T3()const{ return tab; } 
  //Analizuj dokładnie wyniki wyświetlane na ekranie.

  cout << "\n***e0**\n";
  point e0;
  cout << &e0 << '\n' << e0.T3() << '\n' << e0 << endl;

  cout << "\n***e1**\n";
  point e1(x[0]);
  cout << x << "  " << x[0] << "  (" << x[0][0] << ")  " << &x[0][0] << '\n';
  cout << &e1 << '\n' << e1.T3() << '\n' << e1 << endl; 

  cout << "\n***e2**\n";
  point e2(e1);
  cout << &e2 << '\n' << e2.T3() << '\n' << e2 << endl;

  cout << "\n***e0**\n";
  e0 = e2;
  cout << &e0 << '\n' << e0.T3() << '\n' << e0 << endl;

// */

  #ifdef _WIN32
    system("PAUSE");
  #endif
  return 0;
}