#include "tohTry.hpp"
#include <stdio.h>
#include <string>
#include <iostream>


using namespace std;

tohTry::tohTry()
{
    this->towerOne = new Stack();
    this->towerTwo = new Stack();
    this->towerThree = new Stack();
    this->count1 = 0;
    this->count2 = 0;
    this->count3 = 0;
}

void tohTry::addto(int val, int newT)
{
    if(newT = 1)
    {
        if(this->towerOne->peek() > val or this->towerOne->peek() == 0)
        {
            this->towerOne->push(val);
            this->count1++;
        }
        else
        {
            std::cout << "Larger than Previous disk" << "\n";
        }
    }
    else if(newT = 2)
    {
        if(this->towerTwo->peek() > val or this->towerTwo->peek() == 0)
        {
            this->towerTwo->push(val);
            this->count2++;
        }
        else
        {
            std::cout << "Larger than Previous disk" << "\n";
        }
    }
    else if(newT = 3)
    {
        if(this->towerThree->peek() > val or this->towerThree->peek() == 0)
        {
            this->towerThree->push(val);
            this->count3++;
        }
        else
        {
            std::cout << "Larger than Previous disk" << "\n";
        }
        
    }
    else
    {
        std::cout << "not 1,2, or 3" << "\n";
    }
}

void tohTry::fromTo(int origT, int newT)
{
    if(origT == 1)
    {
        if(this->towerOne->peek() != 0)
        {
            int val = this->towerOne->pop();
            this->count1--;
            if(newT == 2)
            {
                if(this->towerTwo->peek() > val or this->towerTwo->peek() == 0)
                {
                    this->towerTwo->push(val);
                    this->count2++;
                }
                else
                {
                    std::cout << "Disk is too big" << "\n";
                    this->towerOne->push(val);
                    this->count1++;
                }
            }
            else if(newT == 3)
            {
                if(this->towerThree->peek() > val or this->towerThree->peek() == 0)
                {
                    this->towerThree->push(val);
                    this->count3++;
                }
                else
                {
                    std::cout << "Disk is too big" << "\n";
                    this->towerOne->push(val);
                    this->count1++;
                }
            }
            else
            {
                std::cout << "not 2, or 3" << "\n";
                
            }
        }
        else
        {
            std::cout << "Pulling from empty tower" << "\n";
        }
        
    }
    else if(origT == 2)
    {
        if(this->towerTwo->peek() != 0)
        {
            int val = this->towerTwo->pop();
            this->count2--;
            if(newT == 1)
            {
                if(this->towerOne->peek() >= val or this->towerOne->peek() == 0)
                {
                    this->towerOne->push(val);
                    this->count1++;
                }
                else
                {
                    std::cout << "Disk is too big" << "\n";
                    this->towerTwo->push(val);
                    this->count2++;
                }
            }
            else if(newT == 3)
            {
                if(this->towerThree->peek() >= val or this->towerThree->peek() == 0)
                {
                    this->towerThree->push(val);
                    this->count3++;
                }
                else
                {
                    std::cout << "Disk is too big" << "\n";
                    this->towerTwo->push(val);
                    this->count2++;
                }
                
            }
            else
            {
                std::cout << "not 1, or 3" << "\n";
                this->towerTwo->push(val);
                this->count2++;
            }
        }
        else
        {
           std::cout << "Pulling from empty tower" << "\n"; 
        }
    }
    else if(origT == 3)
    {
        if(this->towerThree->peek() != 0 or this->towerThree->peek() == 0)
        {
            int val = this->towerThree->pop();
            this->count3--;
            if(newT == 1)
            {
                if(this->towerOne->peek() >= val or this->towerOne->peek() == 0)
                {
                    this->towerOne->push(val);
                    this->count1++;
                }
                else
                {
                    std::cout << "Disk is too big" << "\n";
                    this->towerThree->push(val);
                    this->count3++;
                }
            }
            else if(newT == 2)
            {
                if(this->towerTwo->peek() >= val or this->towerTwo->peek() == 0)
                {
                    this->towerTwo->push(val);
                    this->count2++;
                }
                else
                {
                    std::cout << "Disk is too big" << "\n";
                    this->towerThree->push(val);
                    this->count3++;
                }
            }
            else
            {
                std::cout << "not 1, or 2" << "\n";
                this->towerThree->push(val);
                this->count3++;
            }
        }
        else
        {
            std::cout << "Pulling from empty tower" << "\n";
        }
    }
    else
    {
        std::cout << "not 1, 2, or 3" << "\n";
    } 
}

void tohTry::showTowers()
{
    Stack* one = new Stack();
    Stack* two = new Stack();
    Stack* three = new Stack();
    string collect = "1|";
    int val1 = 0;
    int val2 = 0;
    int val3 = 0;
    for(int i = 0; i < count1; i++)
    {
        val1 = this->towerOne->pop();
        one->push(val1);
    }
    for(int i = 0; i < count2; i++)
    {
        val2 = this->towerTwo->pop();
        two->push(val2);
    }
    for(int i = 0; i < count3; i++)
    {
        val3 = this->towerThree->pop();
        three->push(val3);
    }
    for(int i = 0; i < count1; i++)
    {
        val1 = one->pop();
        towerOne->push(val1); 
        collect += to_string(val1);
    }
    std::cout << collect << "\n";
    collect = "2|";
    for(int i = 0; i < count2; i++)
    {
        val2 = two->pop();
        towerTwo->push(val2);
        collect += to_string(val2);
        
    }
    std::cout << collect << "\n";
    collect = "3|";
    for(int i = 0; i < count3; i++)
    {
        val3 = three->pop();
        towerThree->push(val3);
        collect += to_string(val3);
    }
    std::cout << collect << "\n";
}
void tohTry::playGame()
{
    int val = count1;
    while(count3 < val)
    {
        int a;
        int b;
        printf("Take a disk from what tower?");
        scanf("%d", &a);
        printf("Put the disk on what Tower?");
        scanf("%d", &b);
        if(a == 1 or a == 2 or a == 3)
        {
            if(b == 1 or b == 2 or b == 3)
            {
                if(a != b)
                {
                    this->fromTo(a, b);
                    this->showTowers();
                }
                else
                {
                    this->showTowers();
                    std::cout << "you choose the same tower twice" << "\n";
                }
            }
            else
            {
                this->showTowers();
                std::cout << "didn't choose 1, 2, or 3" << "\n";
            }
            
        }
        else
        {
            this->showTowers();
            std::cout << "didn't choose 1, 2, or 3" << "\n";
        }
    }
    std::cout << "YOU WIN :-)" << "\n";
}