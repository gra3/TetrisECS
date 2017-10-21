#include "GameObject.h"

GameObject::GameObject( const sf::Vector2f& size ):
	width{ size.x },
	height{ size.y }
{
}

float GameObject::GetWidth() const
{
	return width;
}

float GameObject::GetHeight() const
{
	return height;
}