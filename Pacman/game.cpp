#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Pacman.h"
#include <iostream>

int main()
{
    //creating a window
    sf::RenderWindow window(sf::VideoMode({ 672,672 }), "Pacman");

    //speed of pacman
   // window.setFramerateLimit(200);
    
    //making the objects
    Map map;
    Pacman pacman;

    //keeping the window on
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        //implementing functions
        pacman.Move();
        window.clear();
        map.DrawMap(0, 0, window);
        pacman.DrawPacman(window);
        window.display();
    }
}