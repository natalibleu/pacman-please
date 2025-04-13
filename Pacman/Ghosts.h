#pragma once
#include <array>
#include <SFML/Graphics.hpp>

class Ghosts
{
private:
	// The tile pacman is currently in.
	sf::Vector2f currentTile;
	// The tile pacman is moving to.
	sf::Vector2f nextTile;

public:
	void Move(float deltaTime);
	void MapSearch(char a, sf::Sprite& sprite);
};

