#include "Node.h"
#include  <iostream> ;
#include <stdlib.h>
float Node::radius = 50.0f;
Node::Node(int data,float posX,float posY)
{

    circle.setFillColor(sf::Color::Black);
    circle.setRadius(radius);
    circle.setPosition(posX,posY);
    this->posX= posX;
    this->posY= posY;
    value = data;
    izquierdo = NULL;
    derecho = NULL;
    padre  = NULL;


    char chString[32];

    //convert to string
    itoa(data, chString, 10); //stdlib.h
     font.loadFromFile("SugarcubesBold.ttf");
     valueText = sf::Text(chString,font);
     valueText.setPosition(posX+40,posY+25);
     valueText.setColor(sf::Color::Red);

}


Node::~Node()
{
    //dtor
}

 void Node::setColor (sf::Color color)
 {
     circle.setFillColor(color);
 }

 void Node::setColorValue(sf::Color color)
{
    valueText.setColor(color);
}
 void Node::render( sf::RenderWindow *w)
  {
    sf::RenderWindow *window = w;

     window->draw(circle);
     window->draw(valueText);

  }
