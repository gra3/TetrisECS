#pragma once

#include "SFML\Graphics.hpp"

#include "Component.h"

class BodyComponent :
	public Component
{
public:
	BodyComponent( const sf::Vector2f& body, bool inclusive = true );
	
	sf::Vector2f GetBody() const;
	bool IsInclusive() const;

	//Component contract
	virtual ComponentID GetComponentID() const override;

private:
	sf::Vector2f body;
	bool isInclusive;
};

