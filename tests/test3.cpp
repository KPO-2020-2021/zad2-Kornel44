#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Statystyki.hh"

TEST_CASE("Statystyki Procent"){
    staty x, y;
    double a, b;

    a=40;
    b=50;

    x.dobrze=2;
    x.zle=3;

    y.dobrze=2;
    y.zle=2;

    CHECK(x.procent()==a);
    CHECK(y.procent()==b);



}

TEST_CASE("Statystyki wyswietlanie"){
    staty x;

    x.dobrze=2;
    x.zle=3;

    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "Ilosc dobrych odpowiedzi:2\nIlosc zlych odpowiedzi:3\nWynik procentowy poprawnych odpowiedzi:40%\n" == out.str() );
}
