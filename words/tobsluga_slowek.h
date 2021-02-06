#ifndef TOBSLUGA_SLOWEK_H
#define TOBSLUGA_SLOWEK_H

#include <iostream>
#include <vector>
#include <string>
#include <cctype>


class Tobsluga_slowek
{
    int punkty = 0;
public:
    //friend class Tzapis_odczyt;

    Tobsluga_slowek();
    Tobsluga_slowek(std::string);
    Tobsluga_slowek(std::string, int);

    //------------------------
    std::vector<std::string> znaczenie;
    std::vector<std::string> tlumaczenie;
    //------------------------

    void podzial(std::string, int);
    void wyswietlenie();
    void ocena();
    void wyswietla_wszystkie(std::string);
    void dopisuje_slowka(std::string);



};

#endif // TOBSLUGA_SLOWEK_H
