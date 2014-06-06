/* 
 * File:   wie.cpp
 * Author: isinlor
 *
 * Created on 9 maj 2011, 12:59
 */

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    
    /*
     * Inicjalizacja zmiennych, 
     * Różne przygotowania
     */
    
   ios_base::sync_with_stdio(0); // optymalizacja związana z potokami(według OI, na ich stronie)
   int n; // n oznacza ilość wierszy i kolumn
   
   cin >> n; // standardowe wejście
   
   string szachownica[n]; // stworzenie szachownicy; pola tablicy są stringami - al'a tablicami
   string wieza("W"); // nie można porównać szachownica[][] == "W" więc zamiast "W" jest wieza[0]
   
   for(int i = 0; i < n; ++i){
       cin >> szachownica[i]; // standardowe wejście; przypisanie ulozenia figur na wierszu i
   }  
   
   int CzyRzadPusty[n]; // tablica służy do sprawdzenia czy rząd jest pusty poprzez zliczenie liczby  
                        // pustych pól, ponieważ rzędy są sprawdzane w rozsypce jest to tablica

   int m = 0;           // m jest odpowiednikiem CzyRzadPusty dla wierszy (nie musi być tablicą)
                        // resetuje się za każdym razem

   int h = 0; // h służy do iteracji po pustych wierszach/rzędach

   int PustyRzad[n]; // tablica zawierająca numery pustych rzędów
   int PustyWiersz[n]; // -||- wierszy
      
   for(int i = 0; i < n; ++i){
       CzyRzadPusty[i] = 0; // var++ na niezdefiniowanym var daje debilizmy, trzeba nadać var wartość 0
   }

   /*
    * Start algorytmu
    */

   for(int i = 0; i < n; ++i){ 
       for(int j = 0; j < n; ++j){
            if(szachownica[i][j] != wieza[0]){ // sprawdzamy czy na polu (i, j) występuje wieża

                CzyRzadPusty[j]++; // !!! liczymy liczbę pustych pól w rzędzie j !!!
                m++; // !!! liczymy liczbę pustych pól w wierszu i !!!

            }
        }
       if(m==n){ // warunek sprawdzający czy wiersz jest pusty 
                 // m podeje liczbę pustych pól w wierszu, a n to liczba pól w wierszu szachownicy

            PustyWiersz[h] = i; // !!! przypisz numer pustego wiersza !!!

            h++;
            
         }
       m = 0; // zerujemy liczbę pustych pól w wierszu dla kolejnego wiersza
   }

   h = 0; // zerujemy liczbę pustych wierszy, poniważ przechodzimy do rzędów
   for(int j = 0; j < n; j++){
       if(CzyRzadPusty[j]==n){ // warunek sprawdzający czy rząd jest pusty
                               // CzyRzadPusty[] podeje liczbę pustych pól w rzędzie, a n to liczba pól

            PustyRzad[h] = j;  // !!! przypisz numer pustego rzędu !!!

            h++;
       }
   }

   for(int i = 0; i < h; ++i){
       /*
        *      !!! Najważniejsza część algorytmu !!!
        * wstawia "W" w pole którego rząd i wiersz jest pusty
        * lista pustych wierszy i rzędów sporządzona wcześniej
        */
       szachownica[PustyWiersz[i]][PustyRzad[i]] = wieza[0];

   }
   for(int i = 0; i < n; ++i){
        cout << szachownica[i] << "\n"; // wpisyanie kolejnych gotowych wierszy szachownicy
   }
   return 0;
}

