#include "main.h"
#include "Node.h"
#include <SFML/Graphics.hpp>
#include "Edge.h"

 static int screenWidth= 1024;
 static int screenHeight = 768 ;

int main()
{
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Arboles");

    Node n(4,((screenWidth/2)-Node::radius),50,sf::Color::Black);
     Node n1(8,350,100,sf::Color::Black);
      Node n2(2,150,100,sf::Color::Black);
       Node n3(12,450,200,sf::Color::Black);
       Edge e(250,100,200,100);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        n.render(&window);
        n1.render(&window);
        n2.render(&window);
        n3.render(&window);
        e.render(&window);
        window.display();
    }

    return 0;
}
