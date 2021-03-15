#include <iostream>
#include "WyrazenieZesp.hh"

using namespace std;


LZespolona Oblicz (WyrazenieZesp WyrZ)
{
    LZespolona Wynik;
    switch (WyrZ.Op)
    {
    case 0:{
        Wynik=WyrZ.Arg1+WyrZ.Arg2;
        break;
    }
    case 1:{
        Wynik=WyrZ.Arg1-WyrZ.Arg2;
        break;
    }
    case 2:{
        Wynik=WyrZ.Arg1*WyrZ.Arg2;
        break;
    }
    case 3:{
        if (Modul2(WyrZ.Arg2)==0)
        cerr<<"Błąd:Dzielenie przez zero"<<endl;
        else
        Wynik=WyrZ.Arg1/WyrZ.Arg2;
        break;
    }
    default:
    break;}
    return Wynik;

}
std::ostream& operator<<(std::ostream& StrWyj, WyrazenieZesp WyrZ)
{
    const char ZnakOP[]="+-*/";
    return StrWyj<<WyrZ.Arg1<<ZnakOP[WyrZ.Op]<<WyrZ.Arg2;
}
