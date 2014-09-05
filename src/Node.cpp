#include "Node.h"
#include  <iostream> ;
#include <stdlib.h>
float Node::radius = 50.0f;
Node::Node(int data, float posX, float posY){

    circle.setFillColor(sf::Color::Black);
    circle.setRadius(radius);
    circle.setPosition(posX,posY);
    this->posX= posX;
    this->posY= posY;
    value = data;
    izquierdo = NULL;
    derecho = NULL;
    padre  = NULL;

    key[0] = data;
    key[1] = -1;
    parent = child[0] = child[1] = child[2] = NULL;


    char chString[32];

    //convert to string
    itoa(data, chString, 10); //stdlib.h
     font.loadFromFile("SugarcubesBold.ttf");
     valueText = sf::Text(chString,font);
     valueText.setPosition(posX+40,posY+25);
     valueText.setColor(sf::Color::Red);

}


Node::~Node(){
    //dtor
}

void Node::setColor (sf::Color color){
    circle.setFillColor(color);
}

void Node::setColorValue(sf::Color color){
    valueText.setColor(color);
}

void Node::render( sf::RenderWindow *w){
sf::RenderWindow *window = w;

 window->draw(circle);
 window->draw(valueText);

}

bool Node::isLeaf(){
    return (child[0] == NULL);
}

int Node::sibNumber(){
    for (int i = 0; i < 3; ++i) {
        if (this == parent->child[i]) return i;
    }
    return -1;
}

void Node::insert(Node *newChild, int newSmallest){
    if (child[1] == NULL) insert1Siblings(newChild, newSmallest);
    else if (child[2] == NULL) insert2Siblings(newChild, newSmallest);
    else insert3Siblings(newChild, newSmallest);
}

int Node::getSmallest(){
    Node *node = this;
    while (!node->isLeaf()) node = node->child[0];
    return node->key[0];
}

void Node::insert1Siblings(Node *newChild, int newSmallest){
    int newKey = newChild->key[0];
    newChild->parent = this;

    if (newKey < child[0]->key[0]) {
        // newNode is inserted as first child of root
        child[1] = child[0];
        child[0] = newChild;
        key[0] = child[1]->getSmallest();
    }else {
        // newNode is iserted as second child of root
        child[1] = newChild;
        key[0] = newSmallest;
    }
}

void Node::insert2Siblings(Node *newChild, int newSmallest){
    int newKey = newChild->key[0];
    newChild->parent = this;

    if (newKey < child[0]->key[0]) {
        child[2] = child[1];
        child[1] = child[0];
        child[0] = newChild;

        key[1] = key[0];
        key[0] = child[1]->getSmallest();
        updateParentSmallest(newSmallest);
    }
    else if (newKey < child[1]->key[0]) {
        child[2] = child[1];
        child[1] = newChild;

        key[1] = key[0];
        key[0] = newSmallest;
    }
    else {
        child[2] = newChild;

        key[1] = newSmallest;
    }
}

void Node::insert3Siblings(Node *newChild, int newSmallest){
    int newKey = newChild->key[0];

    int splitSmallest = -1;
    Node *splitNode = new Node(-1, ((1024/2)-Node::radius), 50);
    splitNode->parent = parent;

    if (newKey < child[0]->key[0] || newKey < child[1]->key[0]) {
        // newChild is inserted in current node
        splitSmallest = key[0];
        splitNode->child[0] = child[1];
        splitNode->child[1] = child[2];
        splitNode->key[0] = key[1];

        child[1]->parent = splitNode;
        child[2]->parent = splitNode;
        newChild->parent = this;

        if (newKey < child[0]->key[0]) {
            // newChild is inserted as first child
            child[1] = child[0];
            child[0] = newChild;

            key[0] = child[1]->getSmallest();
            updateParentSmallest(newSmallest);
        }
        else {
            // newChild is inserted as second child
            child[1] = newChild;

            key[0] = newSmallest;
        }
    }
    else {
        // newChild is inserted in split node
        child[2]->parent = splitNode;
        newChild->parent = splitNode;

        if (newKey < child[2]->key[0]) {
            // newChild is inserted as first child
            splitSmallest = newSmallest;
            splitNode->child[0] = newChild;
            splitNode->child[1] = child[2];
            splitNode->key[0] = key[1];
        }
        else {
            // newChild is inserted as second child
            splitSmallest = key[1];
            splitNode->child[0] = child[2];
            splitNode->child[1] = newChild;
            splitNode->key[0] = newSmallest;
        }
    }

    child[2] = NULL;
    key[1] = -1;

    if (parent->parent == NULL) {
        // At root, so new root needs to be created
        Node *newNode = new Node(-1, ((1024/2)-Node::radius), 50);

        parent->child[0] = newNode;
        newNode->parent = parent;
        newNode->child[0] = this;
        parent = newNode;
    }

    parent->insert(splitNode, splitSmallest);
}

void Node::updateParentSmallest(int data){
    switch (sibNumber()){
        case 0: if (parent->parent != NULL) parent->updateParentSmallest(data); break;
        case 1: parent->key[0] = data; break;
        case 2: parent->key[1] = data; break;
    }
}
