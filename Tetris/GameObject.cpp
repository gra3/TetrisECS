#include "GameObject.h"

GameObject::GameObject( const sf::Vector2f& size, sf::RenderWindow* window ):
	window{ window },
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

sf::RenderWindow* GameObject::GetRenderWindow() const
{
	return window;
}
