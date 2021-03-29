#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"

TEST_CASE("WyrazenieZesp Wyswietlanie"){
    WyrazenieZesp x;
   
    x.Arg1.re = 2.0/3.0;
    x.Arg1.im = 2.0/3.0;
    x.Op=Op_Mnoz;
    x.Arg2.re= 1;
    x.Arg2.im=-1;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(0.67+0.67i)*(1.00-1.00i)" == out.str() );
}

TEST_CASE("WyrazenieZesp Wczytywanie"){
    WyrazenieZesp x;
    
    std::istringstream in("(10+10.10i)/(2.34+2i)");
    in >> x;
    std::ostringstream out;
    out << x; 
    
    CHECK( "(10.00+10.10i)/(2.34+2.00i)" == out.str() );
}

TEST_CASE("WyrazenieZesp Oblicz"){
   WyrazenieZesp x, y, z, a;
    LZespolona l, m, n, k;

    x.Arg1.re = 0.333333333333;
    x.Arg1.im = 0.333333333333;
    x.Op=Op_Dodaj;
    x.Arg2.re= 0.666666666666;
    x.Arg2.im= 0.666666666666;

    y.Arg1.re = 2/3;
    y.Arg1.im = 2/3;
    y.Op=Op_Odejmij;
    y.Arg2.re= 1;
    y.Arg2.im=-1;

    z.Arg1.re = 2;
    z.Arg1.im = 2;
    z.Op=Op_Mnoz;
    z.Arg2.re= 1;
    z.Arg2.im=-1;

    a.Arg1.re = 2.0;
    a.Arg1.im = 2.0;
    a.Op=Op_Dziel;
    a.Arg2.re= 1;
    a.Arg2.im=-1;

    l.re=1;
    l.im=1;

    m.re=-1.33;
    m.im=1.67;

    n.re=4;
    n.im=0;

    k.re=0;
    k.im=2;

CHECK(x.Oblicz()==l);
CHECK(y.Oblicz()==m);
CHECK(z.Oblicz()==n);
CHECK(a.Oblicz()==k);
}
