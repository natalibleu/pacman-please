#pragma once
#include "Ghosts.h"

class Pinky : Ghosts
{
private:
	sf::Texture pinkyTexture;
	sf::Sprite pinkySprite; 

public:
	void DrawPinky(sf::RenderWindow& window);
	Pinky();
};

