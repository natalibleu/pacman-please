#include "Food.h"
#include "Map.h"
#include "Constants.h"

void Food::DrawFood(sf::RenderWindow& window)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (maze[i][j] == '.')
			{
				foodSprite.setPosition(sf::Vector2f(static_cast<float>(j * blockSize),
					static_cast<float>(i * blockSize)));
				window.draw(foodSprite);
			}
		}
	}
}

Food::Food() : foodTexture("assets/food.png"), foodSprite(foodTexture)
{
}
