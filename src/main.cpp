#include <iostream>
#include <ios>
#include <limits>
#include <stdexcept>
#include "BazaTestu.hh"
#include"Statystyki.hh"


using namespace std;




int main(int argc, char **argv)
{
 BazaTestu   BazaT = { nullptr, 0, 0 };
 WyrazenieZesp   WyrZ_PytanieTestowe;
 LZespolona Odp;
 staty Staty;
 Staty.zle=0;
 Staty.dobrze=0;
 
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


 

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

 

try{                                                               
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {      //pobieramy kolejne pytania testu
    cout << "Podaj wynik operacji:";
    cout << WyrZ_PytanieTestowe<< endl;
    cin >> Odp;                     // wczytujemy odpowiedz
    if (cin.fail()){                                 //jesli blad to dajemy 3 szanse na poprawe formatu 
      for(int i=0; i<3; i++){
      cerr<<"Nieprawidlowy format liczby zespolonej, sprobuj ponownie"<<endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cin>>Odp;
      if (cin.fail()==0)
      break;
      }
    }
    if (Odp==WyrZ_PytanieTestowe.Oblicz())            //sprawdzamy poprawnosc odpowiedzi
    {
      cout<<"Poprawna odpowiedz"<<endl;
      Staty.dobrze++;                     // zwiekszamy poprawne odpowiedzi
    }
      else
      {cout<<"Blenda odpowiedz"<<endl;
      cout<<"Poprawna odpowiedz to"<<WyrZ_PytanieTestowe.Oblicz()<<endl; // podejemy poprawna jesli byla bledna
      Staty.zle++;}

    }}
  catch(runtime_error& e){                 // jesli gdzies wystapi blad to zwracamy go na stderr
    cerr<<"Znaleziono wyjątek"<<endl;
    cerr<<e.what();
  }
  

  cout<<Staty<<endl;            // wyswietlamy statystyki podejscia
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
