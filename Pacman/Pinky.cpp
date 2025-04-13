#include "Pinky.h"

void Pinky::DrawPinky(sf::RenderWindow& window)
{
	window.draw(pinkySprite);
}

Pinky::Pinky() : pinkyTexture("assets/pinky1.png"), pinkySprite(pinkyTexture, sf::IntRect{ {0,0}, {32,32} })
{
	MapSearch('1', pinkySprite);
}
