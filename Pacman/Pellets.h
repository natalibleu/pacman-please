#pragma once
#include <SFML/Graphics.hpp>

class Pellets 
{
private:
	int collectedFood = 0;

	sf::Texture pelletsTexture;
	sf::Sprite pelletsSprite;

public: 
	void DrawPellets(sf::RenderWindow& window);
	Pellets();
};

