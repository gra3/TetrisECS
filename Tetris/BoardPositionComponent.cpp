#include "BoardPositionComponent.h"

BoardPositionComponent::BoardPositionComponent( const sf::Vector2i& startingPosition ) :
	PositionComponent{ static_cast< sf::Vector2f >( startingPosition ) }
{
}

sf::Vector2i BoardPositionComponent::GetPosition() const
{
	return static_cast< sf::Vector2i >( position );
}

void BoardPositionComponent::SetPosition( const sf::Vector2i& newPosition )
{
	position = static_cast< sf::Vector2f >( newPosition );
}

int BoardPositionComponent::GetX() const
{
	return static_cast< int >( position.x );
}

int BoardPositionComponent::GetY() const
{
	return static_cast< int >( position.y );
}

void BoardPositionComponent::SetY( int newY )
{
	position.y = newY;
}
