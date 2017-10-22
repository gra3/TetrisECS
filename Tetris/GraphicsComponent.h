#pragma once

#include <memory>

#include "SFML\Graphics.hpp"

#include "Component.h"

class GraphicsComponent:
	public Component
{
public:
	GraphicsComponent();

	sf::Sprite* GetSprite() const;

	//Component contract
	virtual ComponentID GetComponentID() const override;

protected:
	std::unique_ptr< sf::Texture > texture;
	std::unique_ptr< sf::Sprite > sprite;

	virtual void LoadSprite() = 0;
};

