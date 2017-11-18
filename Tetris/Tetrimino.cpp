#include "Block.h"
#include "BlockContainerComponent.h"
#include "BlockGraphicsComponent.h"
#include "BoardPositionComponent.h"
#include "BodyComponent.h"
#include "VelocityComponent.h"

#include "Tetrimino.h"

Tetrimino::Tetrimino() 
{
	CreateBlockContainer();
}

void Tetrimino::CreateBlockContainer()
{
	AddComponent( std::make_unique< BlockContainerComponent >() );
}

void Tetrimino::AddBlock( const sf::Vector2f& size, const sf::Vector2i& boardPosition, TetriminoColors color )
{
	auto blockContainerComponent = dynamic_cast< BlockContainerComponent* >( GetComponent( Container ) );
	if ( blockContainerComponent != nullptr )
	{
		auto block = std::make_unique< Block >();

		auto boardPositionComponent = std::make_unique< BoardPositionComponent >( boardPosition );
		block->AddComponent( std::move( boardPositionComponent ) );

		auto blockGraphicsComponent = std::make_unique< BlockGraphicsComponent >( size, color );
		block->AddComponent( std::move( blockGraphicsComponent ) );

		auto bodyComponent = std::make_unique< BodyComponent >( size );
		block->AddComponent( std::move( bodyComponent ) );

		auto velocityComponent = std::make_unique< VelocityComponent >( sf::seconds( 0.25 ) );
		block->AddComponent( std::move( velocityComponent ) );

		blockContainerComponent->AddBlock( std::move( block ) );
	}
}
