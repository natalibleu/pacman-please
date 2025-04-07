#pragma once
#include <SFML/Graphics.hpp>

enum class MoveDirection
{
    None,
    Up,
    Down,
    Left,
    Right
};

class Pacman
{
private:
    sf::Texture pacmanTexture;
    sf::Sprite pacmanSprite;

    // Pacman's current direction.
    MoveDirection currentMoveDirection = MoveDirection::None;
    // Pacman's desired direction.
    MoveDirection nextMoveDirection = MoveDirection::None;

    // The tile pacman is currently in.
    sf::Vector2f currentTile;
    // The tile pacman is moving to.
    sf::Vector2f nextTile;

    // How long it takes to move between tiles.
    float interpolationTime = 0.0f;
    float interpolationTimer = 0.0f;
    float moveSpeed = 180.0f;

    // Move packman towards the next tile.
    // Return true if pacman reached the next tile.
    bool MoveTo(float deltaTime);

public:
    void EatFruits();
    void EatGhost();
    void Move(float deltaTime);
    void DrawPacman(sf::RenderWindow& window);
    void Die();
    Pacman();
};

