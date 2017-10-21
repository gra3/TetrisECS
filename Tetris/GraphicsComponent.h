#pragma once

#include <memory>

#include "SFML\Graphics.hpp"

class GraphicsComponent
{
public:
	GraphicsComponent();

	virtual void LoadSprite() = 0;
	sf::Sprite* GetSprite() const;

protected:
	std::unique_ptr< sf::Texture > texture;
	std::unique_ptr< sf::Sprite > sprite;
};

