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
ostream& operator<<(ostream& StrWyj,  WyrazenieZesp WyrZ)
{
    const char ZnakOP[]="+-*/";
    StrWyj<<WyrZ.Arg1<<ZnakOP[WyrZ.Op]<<WyrZ.Arg2;
    return StrWyj;

}


istream& operator >> (istream& StrWej, WyrazenieZesp& WyrZ)
{
    char Znak;
    StrWej>>WyrZ.Arg1;
    StrWej>>Znak;
    switch (Znak)
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
        StrWej.setstate(ios::failbit);
        return StrWej;
        break;
    }
    StrWej>>WyrZ.Arg2;
    return StrWej;
}