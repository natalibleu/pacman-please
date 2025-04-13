#pragma once
#include "Ghosts.h"

class Inky : Ghosts
{
private:
	sf::Texture inkyTexture;
	sf::Sprite inkySprite;

public:
	void DrawInky(sf::RenderWindow& window);
	Inky();
};

