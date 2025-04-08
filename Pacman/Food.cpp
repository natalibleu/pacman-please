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
				float x = static_cast<float>(j * blockSize);
				float y = static_cast<float>(i * blockSize);

				foodSprite.setPosition(sf::Vector2f(x, y));

				window.draw(foodSprite);
			}
		}
	}
}

Food::Food() : foodTexture("assets/food16.png"), foodSprite(foodTexture)
{
}
