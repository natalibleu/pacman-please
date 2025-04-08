#pragma once
#include <SFML/Graphics.hpp>

class Food
{
private:
	int collectedFood = 0;

	sf::Sprite foodSprite;
	sf::Texture foodTexture;

public: 
	void DrawFood(sf::RenderWindow& window);
	Food();
};

