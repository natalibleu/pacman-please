#pragma once
#include "Ghosts.h"

class Blinky : Ghosts
{
private:
	sf::Texture blinkyTexture;
	sf::Sprite blinkySprite;

public:
	void DrawBlinky(sf::RenderWindow& window);
	Blinky();
};

