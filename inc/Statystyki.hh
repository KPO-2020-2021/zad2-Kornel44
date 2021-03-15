#include<iostream>
#ifndef STATYSTYKA
#define STATYSTYKA



struct staty
{
    int dobrze;
    int zle;
};


double procent (staty Odp);
std::ostream& operator << (std::ostream& StrWyj, staty Odp);



#endif