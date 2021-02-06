#ifndef TZAPIS_ODCZYT_H
#define TZAPIS_ODCZYT_H

#include <iostream>
#include <vector>
#include <dirent.h>
#include <fstream>
#include <algorithm>



class Tzapis_odczyt
{

public:
    std::vector<std::string> foldery;
    std::vector<std::string> pliki;
    std::vector<std::string> vec_slowka;
    Tzapis_odczyt();
    Tzapis_odczyt(std::string);


    void odczyt_fol();
    void odczyt_plik(std::string);
    void odczyt_slow(std::string);

};

#endif // TZAPIS_ODCZYT_H
