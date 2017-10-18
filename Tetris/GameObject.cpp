#include "GameObject.h"

GameObject::GameObject( const sf::Rect< float >& rect, sf::RenderWindow* window ):
	window{ window },
	x{ rect.left },
	y{ rect.top },
	width{ rect.width },
	height{ rect.height }
{
}

float GameObject::GetX() const
{
	return x;
}

void GameObject::SetX( float x )
{
	this->x = x;
}

float GameObject::GetY() const
{
	return y;
}

void GameObject::SetY( float y )
{
	this->y = y;
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
