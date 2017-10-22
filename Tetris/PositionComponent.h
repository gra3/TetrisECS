#pragma once

#include "SFML\System.hpp"

#include "Component.h"

class PositionComponent:
	public Component
{

public:
	PositionComponent( const sf::Vector2f& startingPosition );

	sf::Vector2f GetPosition() const;
	float GetX() const;
	float GetY() const;

	//Component contract
	virtual ComponentID GetComponentID() const override;
	
protected:
	sf::Vector2f position;
};

