#pragma once
#include "Ghosts.h"

class Pinky : public Ghosts
{
public:
	sf::Vector2f getTargetPosition(const sf::Vector2f& pacmanPos, const sf::Vector2f& pos2) const override; //overriding
	Pinky();
};

