#include <iostream>
#include "WyrazenieZesp.hh"

using namespace std;

/*!
 * Oblicza zadane wyrazenie zespolone
 * Argumenty:
 *    Struktura na której wywołano metode - wyrazenie do obliczenia
 * Zwraca:
 *    wynik dzialania w postaci liczby zespolonej
 */
LZespolona WyrazenieZesp::Oblicz ()const
{
    LZespolona Wynik;
    switch (this->Op)
    {
    case 0:{
        Wynik=this->Arg1+this->Arg2;
        break;
    }
    case 1:{
        Wynik=this->Arg1-this->Arg2;
        break;
    }
    case 2:{
        Wynik=this->Arg1*this->Arg2;
        break;
    }
    case 3:{
        Wynik=this->Arg1/this->Arg2;
        break;
    }
    default:
    break;}
    return Wynik;

}
/*!
 * Wypisuje wyrazenie zespolone
 * Argumenty:
 *    StrWyj- referencja do strumienia wyjsciowego
 *    WyrZ - wyrazenie do wypisania
 * Zwraca:
 *    Odpowiedni zmodyfikowany strumien wyjsciowy 
 */
ostream& operator<<(ostream& StrWyj,  WyrazenieZesp WyrZ)
{
    const char ZnakOP[]="+-*/"; // tablica z ktorej wypisywane sa odpowiednie znaki arytmetyczne poprzez liczbe jaka jest enum WyrZ.Op
    StrWyj<<WyrZ.Arg1<<ZnakOP[WyrZ.Op]<<WyrZ.Arg2;
    return StrWyj;

}
/*!
 * Wczytuje wyrazenia zespolone
 * Argumenty:
 *   StrWej- referencja do strumienia wejsciowego
 *   WyrZ - referencja do miejsca do zapisu wyrazenia zespolonego
 * Zwraca:
 *    Odpowiednio zmodyfikowany strumien wejsciowy (z podniesiona flaga failbit jesci operacja sie nie powiodla)
 */

istream& operator >> (istream& StrWej, WyrazenieZesp& WyrZ)
{
    char Znak;
    StrWej>>WyrZ.Arg1;
    StrWej>>Znak;                     //Znak arytmetyczny wpisujemy do tymczasowej zmiennej znakowej
    switch (Znak)                     //switchujemy po niej i ustawiamy na odpowiedni WyrZ.Op
    {
    case '+':
      WyrZ.Op=Op_Dodaj;
        break;
    case '-':
        WyrZ.Op=Op_Odejmij;
        break;
    case '*':                             
        WyrZ.Op=Op_Mnoz;
        break;
    case '/':
        WyrZ.Op=Op_Dziel;
        break;
    default:
        StrWej.setstate(ios::failbit);  //jesli Znak nie jest jednym z podstawowych 4 znakow arytmetycznych- failbit
        return StrWej;
        break;
    }
    StrWej>>WyrZ.Arg2;
    return StrWej;
}