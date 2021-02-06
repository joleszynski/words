#ifndef GETCH_H
#define GETCH_H

/*

#include <iostream>
#include <unistd.h>
#include <termios.h>

//***************************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;
int getch(void)
{
    int ch;
    struct termios oldt;
    struct termios newt;
    tcgetattr(STDIN_FILENO , &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
*/

#endif // GETCH_H
