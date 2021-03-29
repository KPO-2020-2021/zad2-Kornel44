#include "LZespolona.hh"
#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdexcept>
#define MINDIV 0.01 //Dokladnosc porownywania liczb



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Struktura na której wywołano metode - pierwszy skladnik dodawania,
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

/*!
 * Realizuje odjecie dwoch liczb zespolonych.
 * Argumenty:
 *    Struktura na której wywołano metode - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Różnice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator - (LZespolona  Skl2)const
{
  LZespolona  Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;
  return Wynik;
}
/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Struktura na której wywołano metode - pierwszy czynnik ,
 *    Skl2 - drugi czynnik.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator * ( LZespolona  Skl2)const
{
  LZespolona  Wynik;
  Wynik.re=this->re*Skl2.re-this->im*Skl2.im;
  Wynik.im=this->re*Skl2.im+this->im*Skl2.re;
 
  return Wynik;
}
/*!
 * Realizuje sprzezenie liczby zespolonej.
 * Argumenty:
 *    Struktura na której wywołano metode - liczba do wykonania sprzezenia
 * Zwraca:
 *    Sprzezenie parametru
 */
LZespolona LZespolona::Sprzezenie ()const
{
  LZespolona Wynik;
  Wynik.re=this->re;
  Wynik.im=0-this->im;

  return Wynik;

}
/*!
 * Realizuje obliczenie kwadratu modulu liczby zespolonej.
 * Argumenty:
 *    Struktura na której wywołano metode - liczba do wykonania operacji modul kwadrat
 * Zwraca:
 *    kwadrat modulu liczby zepolonej (typ double)
 */
double LZespolona::Modul2()const
{
 double Wynik;
 Wynik=this->re*this->re+this->im*this->im;
 return Wynik;

}
/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Struktura na której wywołano metode - dzielna,
 *    Skl2 - dzielnik.
 * Zwraca:
 *     iloraz skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator / (LZespolona Skl2)const
{
  LZespolona Wynik;
  Wynik=*this*Skl2.Sprzezenie()/Skl2.Modul2();
  return Wynik;
}
/*!
 * Realizuje dzielenie liczby zespolonej przez liczbe typu double.
 * Argumenty:
 *    Struktura na której wywołano metode - dzielna,
 *    Skl2 - dzielnik.
 * Zwraca:
 *    Jeśli Skl2==0 to runtime_error
 *    Iloraz skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator/ (double Skl2)const
{
  LZespolona Wynik;
  if(Skl2==0)
  throw std::runtime_error ("Dzielenie przez zero");
  else{
  Wynik.re=this->re/Skl2;
  Wynik.im=this->im/Skl2;
  return Wynik;}
}
/*!
 * Realizuje wypisywanie liczb zespolonych z dwoma miejscami po przecinku.
 * Argumenty:
 *    StrWyj - referencja do strumienia wyjściowego,
 *    Skl2 - liczba zespolona do wypisania.
 * Zwraca:
 *    Referencje do zmodyfikowanego strumienia.
 */
std::ostream & operator<< (std::ostream & StrWyj,  LZespolona Skl)
{
  StrWyj<<std::fixed<<std::setprecision(2);
  StrWyj<<"("<<Skl.re<<std::showpos<<Skl.im<<std::noshowpos<<"i)";
 return StrWyj;
}
/*!
 * Funkcja pomocnicza czytająca konkretny znak.
 * Argumenty:
 *    StrWej - referencja do strumienia wejściowego,
 *    Znak - znak który chcemy wczytać .
 * Zwraca:
 *    Strumień wejściowy bez przeczytanego znaku jesli był on równy zmiennej Znak i ustawia flage strumienia na 
 * failbit jesli nie był równy.
 */
void CzytajZnak(std::istream & StrWej, char Znak)
{
char CzytanyZnak=' ';
StrWej>>CzytanyZnak;
if(CzytanyZnak!=Znak){
  StrWej.setstate(std::ios::failbit);}
}

/*!
 * Wczytuje liczby zespolone ze strumienia.
 * Argumenty:
 *    StrWej - referencja do strumienia wejsciowego,
 *    Skl - referencja do miejsca do zapisu wczytanej liczby.
 * Zwraca:
 *    zmodyfikowany strumien wejsciowy
 */


std::istream& operator>> (std::istream & StrWej, LZespolona & Skl)
{
 CzytajZnak(StrWej,'(');
 StrWej>>Skl.re>>Skl.im;
 CzytajZnak(StrWej,'i');
 CzytajZnak(StrWej,')');
 return StrWej;
}
/*!
 * Realizuje porównanie dwoch liczb zespolonych z dokladnoscia 0.01.
 * Argumenty:
 *    Struktura na której wywołano metode - pierwszy skladnik porownania,
 *    Skl2 - drugi skladnik porownania.
 * Zwraca:
 *    True jesli rowne albo False jesli rozne.
 */
bool LZespolona::operator == ( LZespolona Skl2)const
{
  if(abs(this->re-Skl2.re)<MINDIV && abs(this->im-Skl2.im<MINDIV))
  return true;
  else
  return false;
}
/*!
 * Realizuje wyświetlanie argumentu liczby zespolonej na standardowe wyjsicie
 * Argumenty:
 *    z - liczba ktorej argument ma byc wyswietlony
 * Zwraca:
 *    argument liczby zespolonej z dokladnoscia do 2 miejsc po przecinku na standardowe wejscie lu
 * blad jesli liczba zespolona rowna zero
 */
void arg(LZespolona  z){
  double arg;

  if(z.re==0){
    if(z.im>0){
     arg=(M_PI/2);
    }
    else if(z.im<0){
      arg=(-M_PI/2);
    }
    else{
      throw std::runtime_error("Brak agumentu dla LZespolona=0");
    }}
  else{
    if(z.re>0){
    arg=(atan2(z.im, z.re));
  }else{
    arg=atan2(z.im, z.re)/*+M_PI)*/;//dziwna sprawa bo chyba sam atan2 cos robi z ujemnymi liczbami 
  }

  }
std::cout<<std::fixed<<std::setprecision(2)<<arg;
}
/*!
 * Realizuje podstawienie sumy dwuch liczb zespolonych pod wartosc pierwszej
 * Argumenty:
 *    Arg1 -  skladnik modyfikowany
 *    Arg2 - skladnik nie modyfikowany
 * Zwraca:
 *    zmododyfikowany skladnik pierwszy
 */
LZespolona operator += (LZespolona &Arg1, LZespolona const &Arg2){
  Arg1=Arg1+Arg2;
  return Arg1;
}
/*!
 * Realizuje podstawienie ilorazu dwuch liczb zespolonych pod wartosc pierwszej
 * Argumenty:
 *    Arg1 -  skladnik modyfikowany
 *    Arg2 - skladnik nie modyfikowany
 * Zwraca:
 *    zmododyfikowany skladnik pierwszy 
 */
LZespolona operator /= (LZespolona &Arg1, LZespolona const &Arg2){
  Arg1=Arg1/Arg2;
  return Arg1;
}





//                  DO TESTOW BO VOID NIC NIE ZWRACA
std::ostream& Testarg(std::ostream& StrWyj,LZespolona z){
  double arg;

  if(z.re==0){
    if(z.im>0){
     arg=(M_PI_2);
    }
    else if(z.im<0){
      arg=(-M_PI_2);
    }
    else{
      throw std::runtime_error("Brak agumentu dla LZespolona=0");
    }}
  else{
    if(z.re>0){
    arg=(atan2(z.im, z.re));
  }else{
    arg=atan2(z.im, z.re)/*+M_PI*/; //dziwna sprawa bo chyba sam atan2 cos robi 
  }}
 return StrWyj<<std::fixed<<std::setprecision(2)<<arg;
}