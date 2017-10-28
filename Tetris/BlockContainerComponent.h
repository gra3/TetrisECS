#pragma once
#include <memory>
#include <vector>

#include "Block.h"
#include "Component.h"

class BlockContainerComponent :
	public Component
{
public:
	BlockContainerComponent();

	void AddBlock( std::unique_ptr< Block > block );
	std::vector < std::unique_ptr< Block > >* GetBlocks();

	//Component contract
	virtual ComponentID GetComponentID() const override;

private:
	std::vector < std::unique_ptr< Block > > blocks;
};

