#include "Pinky.h"
#include "Pacman.h"
#include "Constants.h"

sf::Vector2f Pinky::getTargetPosition(const sf::Vector2f& pacmanPos, const sf::Vector2f& pos2) const 
{
	pacmanPos =  + sf::Vector2f(static_cast<float>(4 * blockSize), 0.f);

	return sf::Vector2f(pacmanPos);
}

Pinky::Pinky() : Ghosts("assets/pinky1.png", '1')
{
	
}
