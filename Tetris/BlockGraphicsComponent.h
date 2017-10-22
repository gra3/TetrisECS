#pragma once

#include "GraphicsComponent.h"
#include "TetriminoColors.h"

class BlockGraphicsComponent :
	public GraphicsComponent
{
public:
	BlockGraphicsComponent( const sf::Vector2f& size, TetriminoColors color );

protected:
	//GraphicsComponent contract
	virtual void LoadSprite() override;

private:
	sf::Vector2f blockSize;
	TetriminoColors color;

	sf::Color GetBlockColor() const;
};

