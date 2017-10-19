#pragma once

#include "SFML\System.hpp"

class BoardPositionComponent
{
public:
	BoardPositionComponent( const sf::Vector2i& startingPosition );

	sf::Vector2i GetPosition() const;
	void SetPosition( const sf::Vector2i& newPosition );
	int GetX() const;
	int GetY() const;

private:
	sf::Vector2i position;
};

