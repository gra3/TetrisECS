#include "BlockContainerComponent.h"
#include "BoardPositionComponent.h"
#include "VelocityComponent.h"

#include "PhysicsSystem.h"

PhysicsSystem::PhysicsSystem()
{
}

void PhysicsSystem::DoPhysics( std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects, const sf::Time& elapsedTime )
{
	for ( auto& layer : gameObjects )
	{
		for ( auto& obj : layer )
		{
			HandlePhysics( obj.get(), elapsedTime );

			HandlePhysicsForAllContainedObjects( obj.get(), elapsedTime );
		}
	}
}

void PhysicsSystem::HandlePhysics( const GameObject* obj, const sf::Time& elapsedTime )
{
	if ( HasPositionAndVelocityComponents( obj ) )
	{
		auto velocityComponent = dynamic_cast< VelocityComponent* >( obj->GetComponent( Velocity ) );
		auto totalElapsedTime = velocityComponent->GetTotalElaspedTime();
		auto timeToUpdate = velocityComponent->GetTimeToUpdate();

		totalElapsedTime += elapsedTime;
		if ( totalElapsedTime >= timeToUpdate )
		{
			auto positionComponent = dynamic_cast< BoardPositionComponent* >( obj->GetComponent( Position ) );
			auto y = positionComponent->GetY();
			positionComponent->SetY( y + 1 );

			totalElapsedTime -= timeToUpdate;
		}

		velocityComponent->SetTotalElaspedTime( totalElapsedTime );
	}
}

void PhysicsSystem::HandlePhysicsForAllContainedObjects( const GameObject* obj, const sf::Time& elapsedTime )
{
	if ( HasContainerComponent( obj ) )
	{
		auto blockContainer = dynamic_cast< BlockContainerComponent* >( obj->GetComponent( Container ) );
		auto blocks = blockContainer->GetBlocks();
		for ( auto& block : *blocks )
			HandlePhysics( dynamic_cast< GameObject* >( block.get() ), elapsedTime );
	}
}

bool PhysicsSystem::HasPositionAndVelocityComponents( const GameObject* object )
{
	auto componentMask = object->GetComponentMask();
	auto hasPositionComponent = ( componentMask & Position ) > 0;
	auto hasVelocityComponent = ( componentMask & Velocity ) > 0;

	return hasPositionComponent && hasVelocityComponent;
}

bool PhysicsSystem::HasContainerComponent( const GameObject* object ) const
{
	auto componentMask = object->GetComponentMask();
	auto hasContainerComponent = ( componentMask & Container ) > 0;

	return hasContainerComponent;
}
