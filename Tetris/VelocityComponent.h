#pragma once

#include "SFML\System.hpp"

#include "Component.h"

class VelocityComponent :
	public Component
{
public:
	VelocityComponent( const sf::Time& timeToUpdate );

	sf::Time GetTotalElaspedTime() const;
	void SetTotalElaspedTime( const sf::Time& newTime );
	sf::Time GetTimeToUpdate() const;
	void SetTimeToUpdate( const sf::Time& newTime );

	//Component contract
	virtual ComponentID GetComponentID() const override;

private:
	sf::Time totalElapsedTime;
	sf::Time timeToUpdate;
};

