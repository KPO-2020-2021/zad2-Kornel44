#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("LZespolona Suma"){
    LZespolona x, y, z, a, b, c, d;
    
    a.re=0;
    a.im=0;

    b.re=0.0;
    b.im=0.0;

    c.re=0.001;
    c.im=0.001;

    d.re=0.009;
    d.im=0.009;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
    CHECK(a+x==x);
    CHECK(x+c==x);
    CHECK(z+b==z);
    CHECK(a+c==a);
    CHECK(c+d==x);
}
TEST_CASE("LZespolona Roznica"){
    LZespolona x, y, z, a, b, c;


    a.re=0;
    a.im=0;

    b.re=0.0;
    b.im=0.0;

    c.re=0.001;
    c.im=0.001;

     x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 0;
    z.im = 4;

    CHECK(x-y == z);
    CHECK(x-a==x);
    CHECK(x-c==x);
    CHECK(z-b==z);
    CHECK(a-c==a);
}
TEST_CASE("LZespolona Mnozenie"){
LZespolona x, y, z, a, b, c;

    a.re=0;
    a.im=0;

    b.re=0.0;
    b.im=0.0;

    c.re=0.001;
    c.im=0.001;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 4;
    z.im = -2;
    
    CHECK(x*y==z);
    CHECK(y*x==z);
    CHECK(y*a==b);
    CHECK(x*b==a);
    CHECK(x*c==a);

}

TEST_CASE("LZespolona - dzielenie przez skalar - standardowe 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK((x/t) == y);
}

TEST_CASE("LZespolona - dzielenie przez skalar - standardowe z przyblizeniem") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.333;
    y.im = 0.333;
    std::cout << (x/t) << std::endl;
    std::cout << y << std::endl;
    std::cout << ((x/t) == y) << std::endl;
    CHECK_FALSE((x/t) == y);
}

TEST_CASE("LZespolona - dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
   }
TEST_CASE("LZespolona - dzielenie przez LZespolona"){
    LZespolona x, y, z, a, b, c, d;

    a.re=0;
    a.im=0;

    b.re=1;
    b.im=0;

    c.re=2;
    c.im=3;

    d.re=2;
    d.im=4;

    x.re = 1;
    x.im = 1;

    y.re = 2;
    y.im = -3;

    z.re = -0.38;
    z.im = 0.92;

    CHECK(c/x==d);
    CHECK(c/y==z);
    CHECK(z/b==z);
    WARN_THROWS(c/a);


}

TEST_CASE("LZespolona - Sprzezenie"){
    LZespolona x, y, z, a;

    a.re=1;
    a.im=0;

    x.re = 2;
    x.im = 1;

    y.re = 1;
    y.im = 0;

    z.re = 2;
    z.im = -1;

    CHECK(a.Sprzezenie()==y);
    CHECK(x.Sprzezenie()==z);
}

TEST_CASE("LZespolona - Mudul^2"){
    LZespolona x, y, z;
    double a,b;

    a=5;
    b=1;
    
    x.re = 2;
    x.im = 1;

    y.re = -1;
    y.im = 0;

    z.re = -2;
    z.im = -1;

    CHECK(x.Modul2()==a);
    CHECK(y.Modul2()==b);
    CHECK(z.Modul2()==a);
}

TEST_CASE("LZespolona - porownanie 1") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK_FALSE(x == y);
}

TEST_CASE("LZespolona - porownanie 2") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 2;
   
    CHECK(x == y);
}



TEST_CASE("LZespolona - wyswietlanie standard") {
    LZespolona x;
   
    x.re = 2;
    x.im = 2;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(2.00+2.00i)" == out.str() );
}

TEST_CASE("LZespolona - wyswietlanie zaokraglane") {
    LZespolona x;
   
    x.re = 2.0/3.0;
    x.im = 2.0/3.0;
    
    std::ostringstream out;
    
    out << x;
    std::cout << out.str() << std::endl;
    CHECK( "(0.67+0.67i)" == out.str() );
}

TEST_CASE("LZespolona - wczytywanie standard") {
    LZespolona x;
    
    std::istringstream in("(10+10.10i)");
    in >> x;
    std::ostringstream out;
    out << x; // lub strcmp? ew. == dla LZesp
    
    CHECK( "(10.00+10.10i)" == out.str() );
}

TEST_CASE("Operator +="){
    LZespolona x, y, z, a, b, c, d, g, h;
    
    a.re=0;
    a.im=0;

    b.re=0.0;
    b.im=0.0;

    c.re=0.001;
    c.im=0.001;

    d.re=0.009;
    d.im=0.009;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;

    g.re = 1;
    g.im = 1;

    h.re = 1;
    h.im = -3;

    x+=a;
    CHECK(x==g);
    x+=c;
    CHECK(x==g);
    x+=y;
    CHECK(x== z);
    CHECK_FALSE(x ==g);
    y+=c;
    CHECK(y==h);
    a+=d;
    CHECK(a==b);
}

TEST_CASE("OPERATOR /="){
    LZespolona x, y, z, a, b, c, d, g, h;

    a.re=0;
    a.im=0;

    b.re=1;
    b.im=0;

    c.re=2;
    c.im=3;

    d.re=2;
    d.im=4;

    x.re = 1;
    x.im = 1;

    y.re = 2;
    y.im = -3;

    z.re = -0.38;
    z.im = 0.92;

    g.re = 2;
    g.im = 3;

    h.re = -0.38;
    h.im = 0.92;

    z/=b;
    CHECK(z==h);
    WARN_THROWS(c/=a);
    c/=d;
    CHECK_FALSE(c==g);
    g/=x;
    CHECK(g==d);
    y/=y;
    CHECK(y==b);
   
}
TEST_CASE("Argument liczby zespolonej"){
    LZespolona x, y, z, a, b, c;
   
   
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = -3;

    a.re= 0;
    a.im = 4.03;

    b.re=-4;
    b.im=2;

    c.re= -3;
    c.im= -1;

    std::ostringstream outx, outc,outz,outa, outb;
    Testarg(outx, x);
    Testarg(outc, c);
    Testarg(outz, z);
    Testarg(outa, a);
    Testarg(outb, b);

    CHECK(outx.str()=="0.79");
    CHECK(outz.str()=="-1.57");
    CHECK(outa.str()=="1.57");
    CHECK(outb.str()=="2.68");
    CHECK(outc.str()=="-2.82");
    WARN_THROWS(arg(y));
}