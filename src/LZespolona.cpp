#include "LZespolona.hh"
#include<iostream>
#include<cmath>
#include<iomanip>
#define MINDIV 0.01



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (LZespolona  Skl2)const
{
  LZespolona  Wynik;

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;
  return Wynik;
}

LZespolona  LZespolona::operator - (LZespolona  Skl2)const
{
  LZespolona  Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;
  return Wynik;
}

LZespolona  LZespolona::operator * ( LZespolona  Skl2)const
{
  LZespolona  Wynik;
  Wynik.re=this->re*Skl2.re-this->im*Skl2.im;
  Wynik.im=this->re*Skl2.im+this->im*Skl2.re;
 
  return Wynik;
}

LZespolona LZespolona::Sprzezenie ()const
{
  LZespolona Wynik;
  Wynik.re=this->re;
  Wynik.im=0-this->im;

  return Wynik;

}

double LZespolona::Modul2()const
{
 double Wynik;
 Wynik=this->re*this->re+this->im*this->im;
 return Wynik;

}
LZespolona LZespolona::operator / (LZespolona Skl2)const
{
  LZespolona Wynik;
  Wynik=*this*Skl2.Sprzezenie()/Skl2.Modul2();
  return Wynik;
}

LZespolona LZespolona::operator/ (double Skl2)const
{
  LZespolona Wynik;
  Wynik.re=this->re/Skl2;
  Wynik.im=this->im/Skl2;
  return Wynik;
}

std::ostream & operator<< (std::ostream & StrWyj, const LZespolona Skl)
{
  StrWyj<<std::fixed<<std::setprecision(2);
  StrWyj<<"("<<Skl.re<<std::showpos<<Skl.im<<std::noshowpos<<")";
 return StrWyj;
}

void CzytajZnak(std::istream & StrWej, char Znak)
{
char CzytanyZnak=' ';
StrWej>>CzytanyZnak;
if(CzytanyZnak!=Znak){
  StrWej.setstate(std::ios::failbit);}
}




std::istream& operator>> (std::istream & StrWej, LZespolona & Skl)
{
 CzytajZnak(StrWej,'(');
 StrWej>>Skl.re>>Skl.im;
 CzytajZnak(StrWej,'i');
 CzytajZnak(StrWej,')');
 StrWej.ignore();
 return StrWej;
}

bool LZespolona::operator == ( LZespolona Skl2)const
{
  if(abs(this->re-Skl2.re)<MINDIV && abs(this->im-Skl2.im<MINDIV))
  return true;
  else
  return false;
}
