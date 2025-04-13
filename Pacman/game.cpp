#include "Map.h"
#include "Pacman.h"
#include "Pellets.h"
#include "Energizer.h"
#include "Score.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Inky.h"
#include "Clyde.h"

#include <SFML/Graphics.hpp>

int main()
{
    //creating a window
    sf::RenderWindow window(sf::VideoMode({ 672,672 }), "Pacman");

    sf::Clock clock;

    //speed of pacman
    //window.setFramerateLimit(200);
    
    //making the objects
    Map map;
    Score score;
    Pacman pacman;
    Pellets pellet;
    Energizer energizer;
    Blinky blinky;
    Pinky pinky;
    Inky inky;
    Clyde clyde;

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
        pellet.DrawPellets(window);
        energizer.DrawEnergizer(window);
        pacman.DrawPacman(window);
        blinky.DrawBlinky(window);
        pinky.DrawPinky(window);
        inky.DrawInky(window);
        clyde.DrawClyde(window);

        score.UpdateScore(window);

        window.display();
    }
}