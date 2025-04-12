#pragma once
#include <SFML/Graphics.hpp>

sf::Sprite loadSpriteFromFile(const std::string& filePath) {
    sf::Texture texture;
    if (texture.loadFromFile(filePath)) {
        return sf::Sprite(texture);
    }
    return sf::Sprite();
}