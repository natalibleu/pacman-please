#include "Pacman.h"
#include "Pacman.h"
#include "Map.h"
#include "Constants.h"

void Pacman::EatFruits()
{
    //insert collision eating fruits
}

void Pacman::EatGhost()
{
    //insert collision with ghosts only during booster
}

void Pacman::DrawPacman(sf::RenderWindow& window) //self explanatory
{
    // Draw the pacman sprite at its current position.
    window.draw(pacmanSprite);

    // Draw a 2nd sprite that "wraps around" to the left side of the screen.
    auto currentPosition = pacmanSprite.getPosition();
    pacmanSprite.setPosition(pacmanSprite.getPosition() - sf::Vector2f{ static_cast<float>(screenWidth), 0.0f });
    window.draw(pacmanSprite);

    // Restore the sprite's current position.
    pacmanSprite.setPosition(currentPosition);
}

sf::Vector2f GetNextTile(MoveDirection dir)
{
    switch (dir)
    {
    case MoveDirection::None:
        return { 0, 0 };
    case MoveDirection::Up:
        return { 0, -32 };
    case MoveDirection::Down:
        return { 0, 32 };
    case MoveDirection::Left:
        return { -32, 0 };
    case MoveDirection::Right:
        return { 32, 0 };
    }

    return { 0, 0 };
}

// Return true if the tile is blocked
bool CanMove(const sf::Vector2f& p)
{
    int c = static_cast<int>(p.x) / blockSize;
    int r = static_cast<int>(p.y) / blockSize;

    // Check grid bounds.
    if (r < 0 || r >= rows || c < 0 || c >= columns) return false;

    // Grid cells with a # are walls.
    return maze[r][c] != '#';
}

bool Pacman::MoveTo(float deltaTime)
{
    interpolationTimer += deltaTime;

    if (interpolationTime > 0.0f)
    {
        float t = std::min(1.0f, interpolationTimer / interpolationTime);
        sf::Vector2f newPosition = currentTile + t * (nextTile - currentTile);
        pacmanSprite.setPosition(newPosition);
    }

    return interpolationTimer >= interpolationTime;
}

void Pacman::Move(float deltaTime)
{
    // Update pacman's next move direction.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        nextMoveDirection = MoveDirection::Up;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        nextMoveDirection = MoveDirection::Down;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        nextMoveDirection = MoveDirection::Left;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        nextMoveDirection = MoveDirection::Right;

    // Move pacman towards the next tile.
    if (MoveTo(deltaTime) || nextMoveDirection != currentMoveDirection)
    {
        currentTile = nextTile;
        // Check if pacman can move to the next tile.
        sf::Vector2f desiredTile = GetNextTile(nextMoveDirection);
        if (CanMove(currentTile + desiredTile))
        {
            nextTile = currentTile + desiredTile;

            interpolationTime = (nextTile - pacmanSprite.getPosition()).length() / moveSpeed;
            interpolationTimer = 0.0f;
            currentMoveDirection = nextMoveDirection;
        }
    }
}

void Pacman::Die()
{
    //collision with ghosts always when not in booster
}

Pacman::Pacman() : pacmanTexture("assets/Pacman.png"), pacmanSprite(pacmanTexture, sf::IntRect{ {0,0}, {32,32} })
{
    //beginnig position when spawned
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (maze[i][j] == 'P')
            {
                float x = static_cast<float>(j * blockSize);
                float y = static_cast<float>(i * blockSize);

                currentTile = nextTile = sf::Vector2f{ x, y };

                pacmanSprite.setPosition(currentTile);
            }
        }
    }
}
