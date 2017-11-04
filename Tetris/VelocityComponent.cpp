#include "VelocityComponent.h"

VelocityComponent::VelocityComponent( const sf::Time& timeToUpdate ) :
	totalElapsedTime{ sf::Time::Zero },
	timeToUpdate{ timeToUpdate }
{
}

sf::Time VelocityComponent::GetTotalElaspedTime() const
{
	return totalElapsedTime;
}

void VelocityComponent::SetTotalElaspedTime( const sf::Time& newTime )
{
	totalElapsedTime = newTime;
}

sf::Time VelocityComponent::GetTimeToUpdate() const
{
	return timeToUpdate;
}

void VelocityComponent::SetTimeToUpdate( const sf::Time& newTime )
{
	timeToUpdate = newTime;
}

ComponentID VelocityComponent::GetComponentID() const
{
	return Velocity;
}
