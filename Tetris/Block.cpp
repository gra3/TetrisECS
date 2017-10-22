#include "Block.h"

Block::Block():
	GameObject{}
{
}

void Block::SetColor( TetriminoColors color )
{
	this->color = color;
}

void Block::Activate()
{
	active = true;
}

void Block::Deactivate()
{
	active = false;
}

void Block::Update( const sf::Time& elapsedTime )
{
}
