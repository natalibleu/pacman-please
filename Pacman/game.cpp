#include "Map.h"
#include "Pacman.h"
#include "Food.h"

#include <SFML/Graphics.hpp>

int main()
{
    //creating a window
    sf::RenderWindow window(sf::VideoMode({ 672,672 }), "Pacman");

    sf::Clock clock;

    //speed of pacman
   // window.setFramerateLimit(200);
    
    //making the objects
    Map map;
    Pacman pacman;
    Food food;

    //keeping the window on
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        sf::Time elapsedTime = clock.restart();

        //implementing functions
        pacman.Move(elapsedTime.asSeconds());
        window.clear();
        map.DrawMap(0, 0, window);
        pacman.DrawPacman(window);
        food.DrawFood(window);
        window.display();
    }
}