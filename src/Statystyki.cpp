#include <iostream>
#include "Statystyki.hh"

using namespace std;

//Metoda obliczajaca procent poprawnych odp
// struktura na ktorej wywolano - dane do obliczen
// Zwraca: Procent poprawnych odp jako double
double staty::procent ()const
{
    double Wynik;
    Wynik=(this->dobrze/(this->dobrze+this->zle))*100;
    return Wynik;
}
// Wypisuje wszystkie statystyki
// StrWyj - referencja do strumienia wyjsciowego
// Odp - dane do wypisania
// Zwraca: dużo tekstu z wystepujacymi w nim danymi ze struktury staty.
std::ostream& operator << (std::ostream& StrWyj, staty Odp)
{
   StrWyj <<"Ilosc dobrych odpowiedzi:"<<Odp.dobrze<<endl;
   StrWyj<<"Ilosc zlych odpowiedzi:"<<Odp.zle<<endl;
   StrWyj<<"Wynik procentowy poprawnych odpowiedzi:"<<Odp.procent()<<"%"<<endl;
    return StrWyj;
}
