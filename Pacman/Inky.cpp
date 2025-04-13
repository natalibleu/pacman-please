#include "Inky.h"

void Inky::DrawInky(sf::RenderWindow& window)
{
	window.draw(inkySprite);
}

Inky::Inky() : inkyTexture("assets/inky1.png"), inkySprite(inkyTexture, sf::IntRect{ {0,0}, {32,32} })
{
	MapSearch('2', inkySprite);
}
