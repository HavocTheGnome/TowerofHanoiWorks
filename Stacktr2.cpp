#include "Stacktry2.hpp"
#include <iostream>
#include <string>

Stack::Stack()
{
    this->top = 0;
    this->counter = 0;
}
void Stack::push(int payload)
{
    Node* n = new Node(payload);
    if(this->top)
    {
        n->setNextNode(this->top);
        this->top = n;
    }
    else
    {
        this->top = n;
    }
    this->counter++;
    
}
int Stack::pop()
{
    if(counter == 1)
    {
        int valueToReturn = this->top->getPayload();
        this->top = 0;
        this->counter--;
        return valueToReturn; 
    }
    else if(counter > 0)
    {
        int valueToReturn = this->top->getPayload();
        Node* temp = this->top;
        top = top->getNextNode();
        temp->setNextNode(0);
        delete temp;
        this->counter--;
        return valueToReturn; 
    }
    else
    {
        return 0;
    }
        
}
int Stack::peek()
{
    if(this->top)
    {
        return this->top->getPayload();
    }
    else
    {
        return 0;
    }
}
void Stack::display()
{
    if(this->top)
    {
        Node* currNode = this->top;
        while(currNode)
        {
            std::cout << currNode->getPayload() << "\n";
            currNode = currNode->getNextNode();
        }
    }
    else
    {
        std::cout << "Empty Stack" << "\n";
    }
}


