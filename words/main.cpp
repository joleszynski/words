#include <QCoreApplication>
#include <iostream>
#include "tmenu.h"

using namespace std;
//**************************************************************************************************************************
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Tmenu test("m");

    getchar();
    exit(0);

    return a.exec();
}
//**************************************************************************************************************************




