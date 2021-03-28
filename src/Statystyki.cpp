#include <iostream>
#include "Statystyki.hh"

using namespace std;

double staty::procent ()const
{
    double Wynik;
    Wynik=(this->dobrze/(this->dobrze+this->zle))*100;
    return Wynik;
}

std::ostream& operator << (std::ostream& StrWyj, staty Odp)
{
   StrWyj <<"Ilosc dobrych odpowiedzi:"<<Odp.dobrze<<endl;
   StrWyj<<"Ilosc zlych odpowiedzi:"<<Odp.zle<<endl;
   StrWyj<<"Wynik procentowy poprawnych odpowiedzi:"<<Odp.procent()<<"%"<<endl;
    return StrWyj;
}
