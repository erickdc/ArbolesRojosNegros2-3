#ifndef NODE_H
#define NODE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include <CircleShape.hpp>

class Node
{

    public:
        static float radius ;
        float posX,posY;
        sf::CircleShape circle;
        sf::Font font;
        sf::Text valueText;

        int value;
        Node* left;       // left child
        Node* right;      // right child
        Node* p;
        char color[];        // parent
        Node(int data, float posX,float posY,sf::Color color);

        void render( sf::RenderWindow* w);
        void setColor (sf::Color color);
        void setColorValue(sf::Color color); //Color del Texto
        virtual ~Node();
    protected:
    private:
};

#endif // NODE_H
