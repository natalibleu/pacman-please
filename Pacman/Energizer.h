#pragma once
#include <SFML/Graphics.hpp>

class Energizer 
{
private:
	sf::Texture energizerTexture;
	sf::Sprite energizerSprite;
public:
	void DrawEnergizer(sf::RenderWindow& window);
	Energizer();
};

