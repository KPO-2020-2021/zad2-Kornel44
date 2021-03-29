#include<iostream>
#ifndef STATYSTYKA
#define STATYSTYKA

//Plik zawiera strukture przechowujoca dane statystyczne testu oraz zapowiedz przeciazenia ja wysujaca

struct staty
{
    double dobrze;
    double zle;

    double procent ()const; // metoda obliczjaca procent poprawnych odp
    
};

std::ostream& operator << (std::ostream& StrWyj, const staty Odp);





#endif