#ifndef NODE_H
#define NODE_H

struct Node 
{
    int value;
    Node* next;

    Node(const int& val, Node *nextPtr) 
    {
        value = val;
        next = nextPtr;
    }
};

#endif