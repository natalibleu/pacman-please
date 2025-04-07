#include "Pacman.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include "Constants.h"

void Pacman::EatFruits()
{
	//insert collision eating fruits
}

void Pacman::EatGhost()
{
	//insert collision with ghosts only during booster
}

void Pacman::DrawPacman(sf::RenderWindow& window) //self explanatory
{
	window.draw(pacmanSprite);
}

void Pacman::Move() //need to clean later
{

    sf::Vector2f currentPosition = pacmanSprite.getPosition();
    sf::Vector2f movement(0.0f, 0.0f);

    //key bindings
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        movement.y = -0.2f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        movement.y = 0.2f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        movement.x = -0.2f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        movement.x = 0.2f;
    }

    //four corners of my sprite
    sf::Vector2f offsets[] = { {4,4},{28,4}, {4, 28}, {28,28} };

    bool canMove = true;

    for (sf::Vector2f offset : offsets)
    {
        sf::Vector2 newPosition = currentPosition + movement + offset;

        int newColumns = newPosition.x / blockSize;
        int newRows = newPosition.y / blockSize;

        //collision with wall; marking pacman's maze and allowed places to go

        //if (newRows >= 0 && newRows < rows && newColumns >= 0 && newColumns < columns)
        {
            if (maze[newRows][newColumns] == '#')
            {
                canMove = false;
                break;
            }
        }
    }

    if (canMove)
    {
        pacmanSprite.move(movement);
    }

    //updating x and y to reflect on the sprite's position
    sf::Vector2f position = pacmanSprite.getPosition();
    x = std::fmodf(position.x + screenWidth, screenWidth);
    y = std::fmodf(position.y + screenHeight, screenHeight);

    pacmanSprite.setPosition(sf::Vector2f(x, y));
}

void Pacman::Die()
{
	//collision with ghosts always when not in booster
}

Pacman::Pacman() : pacmanTexture("assets/Pacman.png"), pacmanSprite(pacmanTexture, sf::IntRect{{0,0}, {16,16}})
{
	//beginnig position when spawned
	for(int i = 0; i < rows; i++)
	{
		for (int j= 0; j < columns; j++)
		{
			if (maze[i][j] == 'P')
			{
				pacmanSprite.setPosition(sf::Vector2f(static_cast<float>(j *blockSize),
					static_cast<float>( i * blockSize)));
			    x = j * blockSize;
				y = i * blockSize;
			}
		}
	}

	//making my sprite twice bigger since it's only 16 p and it won't fit the map
	pacmanSprite.setScale(sf::Vector2f(static_cast<float>(2.0f), static_cast<float>(2.0f)));

}
