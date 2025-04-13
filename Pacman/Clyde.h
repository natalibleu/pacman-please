#pragma once
#include "Ghosts.h"

class Clyde : Ghosts
{
private:
	sf::Texture clydeTexture;
	sf::Sprite clydeSprite;
public:
	void DrawClyde(sf::RenderWindow& window);
	Clyde();
};

