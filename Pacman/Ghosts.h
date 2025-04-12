#pragma once
#include <array>
#include <SFML/Graphics.hpp>

class Ghosts
{
private:
	float x, y;

public:
	Ghosts();
	void Move(float deltaTime);
};

