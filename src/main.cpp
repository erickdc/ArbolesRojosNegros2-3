#include "main.h"
#include "Node.h"
#include <SFML/Graphics.hpp>
#include "Edge.h"
#include "RedBlackTree.h"


 static int screenWidth= 1024;
 static int screenHeight = 768 ;
int main()
{
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Arboles");


    RedBlackTree tree;
    tree.insertar(4);
    tree.insertar(9);
    tree.insertar(5);
     tree.insertar(3);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);


        tree.render(&window);
        window.display();
    }

    return 0;
}
