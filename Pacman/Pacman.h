#pragma once
#include <string>
#include <SFML/Graphics.hpp>

//for user input
enum Buttons
{
	ButtonUp,
	ButtonDown, 
	ButtonLeft, 
	ButtonRight
};

class Pacman
{
private:
	float x, y;
	sf::Texture pacmanTexture;
	sf::Sprite pacmanSprite;

public:
	void EatFruits();
	void EatGhost();
	void Move();
	void DrawPacman(sf::RenderWindow& window);
	void Die();
	Pacman();
};

