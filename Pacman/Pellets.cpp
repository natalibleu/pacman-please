#include "Pellets.h"
#include "Map.h"
#include "Constants.h"

void Pellets::DrawPellets(sf::RenderWindow& window)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (maze[i][j] == '.')
			{
				// Calculate the center of the block
				float blockCenterX = j * blockSize + blockSize / 2.0f;
				float blockCenterY = i * blockSize + blockSize / 2.0f;

				// Get the size of the food sprite
				sf::Vector2u pelletsTextureSize = pelletsTexture.getSize(); //16px
				float spriteWidth = pelletsTextureSize.x;
				float spriteHeight = pelletsTextureSize.y;

				// Adjust the position so the center of the sprite aligns with the center of the block
				float spritePosX = blockCenterX - spriteWidth / 2.0f;
				float spritePosY = blockCenterY - spriteHeight / 2.0f;

				pelletsSprite.setPosition(sf::Vector2f(spritePosX, spritePosY));

				window.draw(pelletsSprite);
			}
		}
	}
}

Pellets::Pellets() : pelletsTexture("assets/food16.png"), pelletsSprite(pelletsTexture)
{

}
