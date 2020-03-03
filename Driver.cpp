#include "tohTry.hpp"
#include <iostream>

int main()
{
    tohTry* theTowers = new tohTry();
    theTowers->addto(4, 1);
    theTowers->addto(3, 1);
    theTowers->addto(2, 1);
    theTowers->addto(1, 1);
    theTowers->showTowers();
    theTowers->playGame();
    return 0;
}