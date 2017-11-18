#include "BlockContainerComponent.h"
#include "BoardPositionComponent.h"
#include "TetrisGame.h"
#include "VelocityComponent.h"

#include "PhysicsSystem.h"

PhysicsSystem::PhysicsSystem( TetrisGame* game ) :
	tetrisGame{ game },
	collisionSystem{ game },
	stop{ false }
{
}

void PhysicsSystem::DoPhysics( std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects, const sf::Time& elapsedTime )
{
	stop = false;
	for ( auto& layer : gameObjects )
	{
		if ( stop )
			return;

		for ( auto& obj : layer )
		{
			if ( !stop )
			{
				HandlePhysics( obj.get(), elapsedTime, gameObjects );

				HandlePhysicsForAllContainedObjects( obj.get(), elapsedTime, gameObjects );
				if ( stop )
					return;
			}
			else return;
		}
	}

	stop = false;
}

void PhysicsSystem::HandlePhysics( const GameObject* obj, const sf::Time& elapsedTime, std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects )
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

			if ( collisionSystem.DetectCollision( obj, gameObjects ) )
			{
				positionComponent->SetY( y );
				tetrisGame->MoveBlocksOfActiveTetriminoAndDestroy();
				stop = true;
			}

			totalElapsedTime -= timeToUpdate;
		}

		velocityComponent->SetTotalElaspedTime( totalElapsedTime );
	}
}

void PhysicsSystem::HandlePhysicsForAllContainedObjects( const GameObject* obj, const sf::Time& elapsedTime, std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects )
{
	if ( HasContainerComponent( obj ) )
	{
		auto blockContainer = dynamic_cast< BlockContainerComponent* >( obj->GetComponent( Container ) );
		auto blocks = blockContainer->GetBlocks();
		std::vector< Block* > rawBlockPointers;
		for ( auto& block : *blocks )
			rawBlockPointers.emplace_back( block.get() );
		for ( auto block : rawBlockPointers )
		{
			if( !stop )
				HandlePhysics( dynamic_cast< GameObject* >( block ), elapsedTime, gameObjects );
		}
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
