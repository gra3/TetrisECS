#include "PositionComponent.h"

PositionComponent::PositionComponent( const sf::Vector2f& startingPosition ):
	position{ startingPosition }
{
}

sf::Vector2f PositionComponent::GetPosition() const
{
	return position;
}

float PositionComponent::GetX() const
{
	return position.x;
}

float PositionComponent::Gety() const
{
	return position.y;
}

ComponentID PositionComponent::GetComponentID() const
{
	return Position;
}
