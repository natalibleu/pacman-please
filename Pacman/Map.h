#pragma once
#include <string>
#include <SFML/Graphics.hpp>

//map directions
const int rows = 22;
const int columns = 22;
extern char maze[rows][columns];

class Map {
private: 	
	sf::Texture texture;
	sf::Sprite wallSprite;
public:
	Map();
	void DrawMap(unsigned int x, unsigned int y, sf::RenderWindow& window);
};