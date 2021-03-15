#include <iostream>
#include "Statystyka.hh"

using namespace std;

double procent (staty Odp)
{
    double Wynik;
    Wynik=Odp.dobrze/(Odp.dobrze+Odp.zle)*100;
    return Wynik;
}

std::ostream& operator << (std::ostream& StrWyj, staty Odp)
{
   StrWyj <<"Ilosc dobrych odpowiedzi:"<<Odp.dobrze<<endl;
   StrWyj<<"Ilosc zlych odpowiedzi:"<<Odp.zle<<endl;
   StrWyj<<"Wynik procentowy poprawnych odpowiedzi:"<<procent(Odp)<<"%"<<endl;
    return StrWyj;
}
