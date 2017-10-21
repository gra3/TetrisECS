#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent():
	sprite{ std::make_unique< sf::Sprite >() },
	texture{ std::make_unique< sf::Texture >() }
{
}

sf::Sprite* GraphicsComponent::GetSprite() const
{
	return sprite.get();
}
