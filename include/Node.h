#ifndef NODE_H
#define NODE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
//#include <CircleShape.hpp>

class Node
{

    public:
        static float radius ;
        float posX,posY;
        sf::CircleShape circle;
        sf::Font font;
        sf::Text valueText;

        int key[2];
        Node *parent, *child[3];

        int value;
        Node* izquierdo;       // left child
        Node* derecho;      // right child
        Node* padre;
        std::string color;        // parent
        Node(int data, float posX,float posY);

        void render( sf::RenderWindow* w);
        void setColor (sf::Color color);
        void setColorValue(sf::Color color); //Color del Texto

        bool isLeaf();
        int sibNumber();
        void insert(Node *newChild, int newSmallest);

        virtual ~Node();
    protected:
    private:
        int getSmallest();
        void insert1Siblings(Node *newChild, int newSmallest);
        void insert2Siblings(Node *newChild, int newSmallest);
        void insert3Siblings(Node *newChild, int newSmallest);
        void updateParentSmallest(int data);
};

#endif // NODE_H
