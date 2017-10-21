#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject( const sf::Vector2f& size );

	virtual void Update( const sf::Time& elapsedTime ) = 0;

	float GetWidth() const;
	float GetHeight() const;

private:
	float width;
	float height;
};

