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
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona Skl1, LZespolona Skl2);
LZespolona operator * (LZespolona Skl1, LZespolona SkL2);
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, double Skl2); 
LZespolona Sprzezenie (LZespolona);
bool operator == (LZespolona Skl1, LZespolona Skl2);
std::ostream& operator<< (std::ostream & StrWyj, LZespolona Skl1);
std::istream& operator>> (std::istream & StrWej, LZespolona & Odp);
double Modul2 (LZespolona);


#endif
 