#pragma once

#include "SFML\System.hpp"

class PositionComponent
{

public:
	PositionComponent( const sf::Vector2f& startingPosition );

	sf::Vector2f GetPosition() const;
	float GetX() const;
	float Gety() const;
	
protected:
	sf::Vector2f position;
};

