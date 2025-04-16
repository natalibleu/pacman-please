#include "Inky.h"

bool Inky::Scatter()
{
	return true;
}

sf::Vector2f Inky::getTargetPosition(const sf::Vector2f& pacmanPos, const sf::Vector2f& pos2) const
{
	return sf::Vector2f();
}

Inky::Inky() : Ghosts("assets/inky1.png", '2')
{
}

