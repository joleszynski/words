#ifndef TEKRAN_H
#define TEKRAN_H

#include <iostream>
#include <string>
//***************************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tekran
{
    std::string tresc;  //tresc ktora w danej chwili jest wyswietlana na ekranie
    char        znak_tla;  //znak tla
public:
    enum{szerokosc_ekranu = 120, wysokosc_ekranu = 30};  //wymiary ekranu

    Tekran(char znak = ' ') //konstruktor ekranu
    {
        znak_tla = znak;
        wyczysc();
    }
    //-------------
    void wyczysc() //funkcja czyscząca ekran
    {
        tresc.clear();
        //wypelnienie calego ekranu samymi znakami tla
        std::string jedna_linijka(szerokosc_ekranu-1, znak_tla); //wypelnienie ekranu znakiem tla
        jedna_linijka += '\n';
        for(int i = 0; i < wysokosc_ekranu; ++i)    tresc += jedna_linijka;  //petla dodajaca znak tla na calym ekranie
    }
    //--------------
    void wyswietl() //funkcja wyswietla tresc na ekranie poprzez wywolanie tej funkcji z obiektu
    {
        std::cout<<tresc;
    }
    //--------------
    //Funkcja składowa wpisująca w wybranym miejscu ekranu zadany tekst do treści ekranu
    void napisz(int kolumna, int rzad, std::string tekst)
    {
        tresc.replace( (szerokosc_ekranu * rzad) + kolumna, tekst.length(), tekst );
    }
};


#endif // TEKRAN_H
