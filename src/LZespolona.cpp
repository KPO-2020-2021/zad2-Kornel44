#include "LZespolona.hh"
#include<iostream>

using namespace std;


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  Wynik.re=Skl1.re*Skl2.re-Skl1.im*Skl2.im;
  Wynik.im=Skl1.re*Skl2.im+Skl1.im*Skl2.re;
 
  return Wynik;
}

LZespolona Sprzezenie (LZespolona Skl1)
{
  LZespolona Wynik;
  Wynik.re=Skl1.re;
  Wynik.im=0-Skl1.im;

  return Wynik;

}

double Modul2 (LZespolona Skl1)
{
 double Wynik;
 Wynik=Skl1.re*Skl1.re+Skl1.im*Skl1.im;
 return Wynik;

}
LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  Wynik=Skl1*Sprzezenie(Skl2)/Modul2(Skl2);
  return Wynik;
}

LZespolona operator/ (LZespolona Skl1, double Skl2)
{
  LZespolona Wynik;
  Wynik.re=Skl1.re/Skl2;
  Wynik.im=Skl1.im/Skl2;
  return Wynik;
}

std::ostream & operator<< (std::ostream & StrWyj, LZespolona Skl1)
{
  if (Skl1.im>=0)
{
  return StrWyj<<"("<<Skl1.re<<"+"<<Skl1.im<<"i)";
}
else
return StrWyj<<"("<<Skl1.re<<Skl1.im<<"i)";
}

std::istream& operator>> (std::istream & StrWej, LZespolona & Odp)
{
 StrWej>>Odp.re>>Odp.im;
 StrWej.ignore();
 return StrWej;
}

bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
  return true;
  else
  return false;
}
