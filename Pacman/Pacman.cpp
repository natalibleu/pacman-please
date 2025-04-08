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

sf::Vector2f WrapCoords(const sf::Vector2f& p)
{
    float sw = static_cast<float>(screenWidth);
    float sh = static_cast<float>(screenHeight);

    return { std::fmod(p.x + sw, sw), std::fmod(p.y + sh, sh) };
}

// Return true if the tile is not blocked
bool CanMove(sf::Vector2f p)
{
    p = WrapCoords(p); // Wrap-around.

    int c = static_cast<int>(p.x) / blockSize;
    int r = static_cast<int>(p.y) / blockSize;

    // Grid cells with a # are walls.
    return maze[r][c] != '#' && maze[r][c] != '=';
}


bool Pacman::MoveTo(float deltaTime)
{
    interpolationTimer += deltaTime;

    if (interpolationTime > 0.0f)
    {
        float t = std::min(1.0f, interpolationTimer / interpolationTime);
        sf::Vector2f newPosition = currentTile + t * (nextTile - currentTile);
        pacmanSprite.setPosition(WrapCoords(newPosition));
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
    if (MoveTo(deltaTime))
    {
        currentTile = WrapCoords(nextTile);
        if (CanMove(currentTile + GetNextTile(nextMoveDirection)))
        {
            // Change direction.
            nextTile = currentTile + GetNextTile(nextMoveDirection);
            currentMoveDirection = nextMoveDirection;
        }
        else if (CanMove(currentTile + GetNextTile(currentMoveDirection)))
        {
            nextTile = currentTile + GetNextTile(currentMoveDirection);
        }

        interpolationTime = (nextTile - pacmanSprite.getPosition()).length() / moveSpeed;
        interpolationTimer = 0.0f;
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
