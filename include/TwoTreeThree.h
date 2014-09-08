#ifndef TWOTREETHREE_H
#define TWOTREETHREE_H

#include "Node.h"

class TwoTreeThree
{
public:
    TwoTreeThree();
    virtual ~TwoTreeThree();

    bool insert(int data);
    void print();

private:
    Node *root;

    Node* findSpot(Node *node, int data);
    void print(Node *node, int tabs = 0);
};

#endif // TWOTREETHREE_H
