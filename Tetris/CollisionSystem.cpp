#include "BoardPositionComponent.h"
#include "BodyComponent.h"
#include "TetrisGame.h"

#include "CollisionSystem.h"

CollisionSystem::CollisionSystem( TetrisGame* game ) :
	tetrisGame{ game }
{
}

bool CollisionSystem::DetectCollision( const GameObject* objectInQuestion, std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects ) const
{
	for ( auto& layer : gameObjects )
	{
		for ( auto& obj : layer )
		{
			if ( objectInQuestion != obj.get() && HasBodyAndPositionComponents( objectInQuestion ) && HasBodyAndPositionComponents( obj.get() ) )
			{
				if ( DoObjectsCollide( objectInQuestion, obj.get() ) )
					return true;
			}
		}
	}

	return false;
}

bool CollisionSystem::DoObjectsCollide( const GameObject* objectOne, const GameObject* objectTwo ) const
{
	auto collides = false;

	auto rectOne = GetObjectRect( objectOne );
	auto rectTwo = GetObjectRect( objectTwo );

	auto inclusiveOne = IsInclusive( objectOne );
	auto inclusiveTwo = IsInclusive( objectTwo );

	if ( inclusiveOne && inclusiveTwo )
		collides = rectOne.intersects( rectTwo );
	else if ( !inclusiveTwo && !inclusiveOne )
		collides = !rectOne.intersects( rectTwo );
	if ( !inclusiveOne || !inclusiveTwo )
		collides = !rectTwo.intersects( rectOne );

	return collides;
}

sf::FloatRect CollisionSystem::GetObjectRect( const GameObject* object ) const
{
	auto bodyComponent = dynamic_cast< BodyComponent* >( object->GetComponent( Body ) );
	auto body = bodyComponent->GetBody();

	auto positionComponent = dynamic_cast< PositionComponent* >( object->GetComponent( Position ) );
	auto x = positionComponent->GetX();
	auto y = positionComponent->GetY();

	auto boardPosition = dynamic_cast< BoardPositionComponent* >( positionComponent );
	if ( boardPosition != nullptr )
	{
		auto startingPosition = tetrisGame->GetStartingPosition();
		auto borderThickness = tetrisGame->GetBorderThickness();
		x = startingPosition.x + boardPosition->GetX() * body.x + borderThickness;
		y = startingPosition.y + boardPosition->GetY() * body.y + borderThickness;
	}

	return sf::FloatRect( x, y, body.x, body.y );
}

bool CollisionSystem::IsInclusive( const GameObject* object ) const
{
	auto bodyComponent = dynamic_cast< BodyComponent* >( object->GetComponent( Body ) );

	return bodyComponent->IsInclusive();
}

bool CollisionSystem::HasBodyAndPositionComponents( const GameObject* gameObject ) const
{
	auto componentMask = gameObject->GetComponentMask();
	auto hasPositionComponent = ( componentMask & Position ) > 0;
	auto hasBodyComponent = ( componentMask & Body ) > 0;

	return hasPositionComponent && hasBodyComponent;
}
