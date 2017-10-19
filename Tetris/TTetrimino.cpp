#include "TTetrimino.h"

TTetrimino::TTetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size, sf::RenderWindow* window ):
	Tetrimino( boardPosition, size, window )
{
	InitTetrimino();
}

void TTetrimino::InitTetrimino()
{
	ActivateBlock( 1, 0, Purple );
	ActivateBlock( 0, 1, Purple );
	ActivateBlock( 1, 1, Purple );
	ActivateBlock( 2, 1, Purple );
}
