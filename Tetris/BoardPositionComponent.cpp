#include "BoardPositionComponent.h"

BoardPositionComponent::BoardPositionComponent( const sf::Vector2i& startingPosition ):
	position{ startingPosition }
{
}

sf::Vector2i BoardPositionComponent::GetPosition() const
{
	return position;
}

void BoardPositionComponent::SetPosition( const sf::Vector2i& newPosition )
{
	position = newPosition;
}

int BoardPositionComponent::GetX() const
{
	return position.x;
}

int BoardPositionComponent::GetY() const
{
	return position.y;
}
