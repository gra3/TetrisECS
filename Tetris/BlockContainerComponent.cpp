#include "BlockGraphicsComponent.h"

#include "BlockContainerComponent.h"

BlockContainerComponent::BlockContainerComponent()
{
}

void BlockContainerComponent::AddBlock( std::unique_ptr< Block > block )
{
	blocks.emplace_back( std::move( block ) );
}

std::vector < std::unique_ptr< Block > >* BlockContainerComponent::GetBlocks()
{
	return &blocks;
}

ComponentID  BlockContainerComponent::GetComponentID() const
{
	return Container;
}
