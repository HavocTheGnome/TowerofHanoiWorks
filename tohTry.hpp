#include "Stacktry2.hpp"
#include <iostream>

class tohTry
{
    private:
        Stack* towerOne;
        Stack* towerTwo;
        Stack* towerThree;
        int count1;
        int count2;
        int count3;
    public:
        tohTry();
        void addto(int val, int newT);
        void fromTo(int origT, int newT);
        void showTowers();
        void playGame();
};