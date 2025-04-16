#include "Blinky.h"
#include "Pacman.h"
#include "Constants.h"

Blinky::Blinky() : Ghosts("assets/blinky1.png", '0')
{

}

sf::Vector2f Blinky::getTargetPosition(const sf::Vector2f& pacmanPos, const sf::Vector2f& pos2) const
{
	return pacmanPos;
}
