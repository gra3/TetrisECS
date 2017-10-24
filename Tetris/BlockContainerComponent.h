#pragma once
#include <memory>
#include <vector>

#include "Block.h"
#include "Component.h"

class BlockContainerComponent :
	public Component
{
public:
	BlockContainerComponent( const sf::Vector2i& startingPosition, const sf::Vector2i& sizeInBlocks );

	void InitBlocks( const sf::Vector2i& startingPosition, const sf::Vector2i& sizeInBlocks );
	void AddBlockGraphicComponent( const sf::Vector2i& position, const sf::Vector2f& size, TetriminoColors color );
	void ActivateBlock( const sf::Vector2i& position );
	std::vector < std::vector< Block > >* GetBlocks();

	//Component contract
	virtual ComponentID GetComponentID() const override;

private:
	std::vector < std::vector< Block > > blocks;
};

