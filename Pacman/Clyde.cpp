#include "Clyde.h"

void Clyde::DrawClyde(sf::RenderWindow& window)
{
	window.draw(clydeSprite);
}

Clyde::Clyde() : clydeTexture("assets/clyde1.png"), clydeSprite(clydeTexture, sf::IntRect{ {0,0}, {32,32} })
{
	MapSearch('3', clydeSprite);
}
