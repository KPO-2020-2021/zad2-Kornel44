#include <iostream>
#include "WyrazenieZesp.hh"

using namespace std;


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
        if (this->Arg2.Modul2()==0)
        cerr<<"Błąd:Dzielenie przez zero"<<endl;
        else
        Wynik=this->Arg1/this->Arg2;
        break;
    }
    default:
    break;}
    return Wynik;

}
std::ostream& operator<<(std::ostream& StrWyj, const WyrazenieZesp WyrZ)
{
    const char ZnakOP[]="+-*/";
    StrWyj<<WyrZ.Arg1<<ZnakOP[WyrZ.Op]<<WyrZ.Arg2;
    return StrWyj;
}

std::istream& operator >> (std::istream& StrWej, WyrazenieZesp& WyrZ)
{
    char Znak=' ';
    StrWej>>WyrZ.Arg1;
    StrWej>>Znak;
    if (Znak!='+' && Znak!='-' && Znak!='*' && Znak!='/'){
        StrWej.setstate(std::ios::failbit);
        return StrWej;
    }
    StrWej>>WyrZ.Arg2;
    return StrWej;
}