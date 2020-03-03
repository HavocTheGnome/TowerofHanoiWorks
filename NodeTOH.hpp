#ifndef Node_hpp
#define Node_hpp
#include <iostream>

class Node 
{
private:
    int payload;
    Node* nextNode; //Node nextNode - java treats this as a Node* automatically
    Node* lastNode;
public:
    Node(int payload);
    int getPayload();
    Node* getNextNode();
    Node* getLastNode();
    void setNextNode(Node* n);
    void setLastNode(Node* n);
    
};
#endif /* NodeHW8_hpp */
