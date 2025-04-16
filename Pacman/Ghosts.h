#pragma once
#include <SFML/Graphics.hpp>

enum class RandomDirection
{
	None,
	Up,
	Down,
	Left,
	Right
};

class Ghosts
{
private:
	// Ghost's current direction.
	RandomDirection currentMoveDirection = RandomDirection::None;
	// Ghost's desired direction.
	RandomDirection nextMoveDirection = RandomDirection::None;

	// The tile ghost is currently in.
	sf::Vector2f currentTile;
	// The tile ghost is moving to.
	sf::Vector2f nextTile;

	//setTargetPosition(sf::Vector2f pacmanPos); override n every ghost, declare here and define in every ghost

	float interpolationTime = 0.0f;
	float interpolationTimer = 0.0f;
	float moveSpeed = 150.0f;

	float animationTimer = 0.0f;
	float animationEndTime = 0.1f; // Animation frame duration
	int currentFrame = 0;

	bool scatterMode = false;

protected:
	sf::Texture ghostTexture;
	sf::Sprite ghostSprite;
	Ghosts(const std::string& texturePath, char a);

public:
	RandomDirection OppositeDirection();
	void Move(float deltaTime, const sf::Vector2f& pacmanPos, const sf::Vector2f& ghostPos = {0.f, 0.f});
	bool MoveTo(float deltaTime);
	void MapSearch(char a, sf::Sprite& sprite);
	void Draw(sf::RenderWindow& window);
	virtual sf::Vector2f getTargetPosition(const sf::Vector2f& pacmanPos, const sf::Vector2f& pos2) const = 0;
	sf::Vector2f getPosition() const;
	bool Scatter();
};

