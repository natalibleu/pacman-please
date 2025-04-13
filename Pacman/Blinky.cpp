#include "Blinky.h"

void Blinky::DrawBlinky(sf::RenderWindow& window)
{
	window.draw(blinkySprite);
}

Blinky::Blinky() : blinkyTexture("assets/blinky1.png"), blinkySprite(blinkyTexture, sf::IntRect{ {0,0}, {32,32} })
{
	//start position
	MapSearch('0', blinkySprite);
}
