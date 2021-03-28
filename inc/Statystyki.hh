#include<iostream>
#ifndef STATYSTYKA
#define STATYSTYKA



struct staty
{
    double dobrze;
    double zle;

    double procent ()const;
    
};

std::ostream& operator << (std::ostream& StrWyj, const staty Odp);





#endif