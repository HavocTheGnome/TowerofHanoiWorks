#include "NodeTOH.hpp"
#include <iostream>

class Stack
{
    private:
        int counter;
        Node* top;
    public:
        Stack();
        void push(int payload);
        int pop();
        int peek();
        void display();
        void addto(int val, int newT);
        void fromTo(int origT, int newT);
        void showTowers();
};