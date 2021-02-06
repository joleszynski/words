#ifndef TMENU_H
#define TMENU_H

#include <iostream>
#include <vector>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <conio.h>
#include "tzapis_odczyt.h"
#include "tobsluga_slowek.h"




//***************************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Tmenu
{  
    std::string pokazuje; //zawartosc tekstu wyswietlanego w ramce
    //------------------
    int         x,y;      //pozycja ramki na ekranie
    //------------------
    std::vector<Tmenu> Tmenu_obiekty;
    std::vector<Tmenu> pliki;
    //------------------
public:
    //konstruktory
    Tmenu(std::string); //konstruktor odpowiadający za wyświetlenie odpowiednieg menu
    Tmenu(int, int, std::string);  //konstruktor ramek z napisami
    Tmenu(int xx, int yy, std::string nnn, std::string n);
    Tmenu(); //Konstruktor domyślny
    //------------------
    void narysuj(); //Funkcja rysuje ramke
    void narysuj_gw(); //--||-- gwiazdkowa
    void narys_st();
    void sprmenu(int); //Funkcja tworzy menu wyboru folderow
    void plimenu(std::vector<std::string>, std::string, int); //Funkcja tworzy menu wyboru plikow
    void tab_obiektow(int, int, int, std::vector<std::string>);  //Funkcja tworząca dynamicznie obiekty z okienkami
    void pol_ang(std::string, std::string ); //Funkcja tworząca menu wyboru wczytywania słówek polski czy angielski
    void wys_wszystko(std::string nazwa_pliku, std::string nazwa_folderu); //Funkcja wyświetla wszystkie słówka z wybranego pliku
    void zapisz_s(); //Funkcja zapisująca słówka
    void tab_plikow(int dlugosc, int x, int y, std::vector<std::string> nazwa);
    //------------------
    int key();  //Funkcja pobierjąca numer wciśnietego klawisza
    int mmenu(); //Funkcja wyświetlająca Menu Główne
    int poz(int &pozycja, int dlugosc, int klawisz, int x);  //Zwraca wartość pozycji
    //------------------


};
#endif // TMENU_H
