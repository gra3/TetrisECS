#include "BlockGraphicsComponent.h"

#include "BlockContainerComponent.h"

BlockContainerComponent::BlockContainerComponent( const sf::Vector2i& startingPosition, const sf::Vector2i& sizeInBlocks )
{
	InitBlocks( startingPosition, sizeInBlocks );
}

void BlockContainerComponent::InitBlocks( const sf::Vector2i& startingPosition, const sf::Vector2i& sizeInBlocks )
{
	blocks.resize( sizeInBlocks.x );
	for ( int i = 0; i < blocks.size(); i++ )
	{
		for ( int j = 0; j < sizeInBlocks.y; j++ )
		{
			blocks[ i ].emplace_back( Block() );

			auto boardPosition = std::make_unique< BoardPositionComponent >( sf::Vector2i( startingPosition.x + i, startingPosition.y + j ) );
			blocks[ i ][ j ].AddComponent( std::move( boardPosition ) );
		}
	}
}

void BlockContainerComponent::AddBlockGraphicComponent( const sf::Vector2i& position, const sf::Vector2f& size, TetriminoColors color )
{
	auto blockGraphicsComponent = std::make_unique< BlockGraphicsComponent >( size, color );
	blocks[ position.x ][ position.y ].AddComponent( std::move( blockGraphicsComponent ) );
}

void BlockContainerComponent::ActivateBlock( const sf::Vector2i& position )
{
	blocks[ position.x ][ position.y ].Activate();
}

std::vector < std::vector< Block > >* BlockContainerComponent::GetBlocks()
{
	return &blocks;
}

ComponentID  BlockContainerComponent::GetComponentID() const
{
	return Container;
}
