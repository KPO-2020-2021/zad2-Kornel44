#include<iostream>
#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH


/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona  operator + (LZespolona  Skl2)const;
  LZespolona operator - (LZespolona Skl2)const;
  LZespolona operator * (LZespolona SkL2)const;
  LZespolona operator / (LZespolona Skl2)const;
  LZespolona operator / (double Skl2)const; 
  LZespolona Sprzezenie ()const;
  bool operator == (LZespolona Skl2)const;
  double Modul2 ()const;
};

void CzytajZnak(std::istream & StrWej, char Znak);
std::ostream& operator<< (std::ostream & StrWyj,const LZespolona Skl);
std::istream& operator>> (std::istream & StrWej,const LZespolona& Skl);

#endif
 