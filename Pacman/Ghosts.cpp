#include "Ghosts.h"
#include "Constants.h"
#include "Map.h"

void Ghosts::Move(float deltaTime)
{

}

void Ghosts::MapSearch(char a, sf::Sprite& sprite)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (maze[i][j] == a)
            {
                float x = static_cast<float>(j * blockSize);
                float y = static_cast<float>(i * blockSize);

                currentTile = nextTile = sf::Vector2f{ x, y };

                sprite.setPosition(currentTile);
            }
        }
    }
}