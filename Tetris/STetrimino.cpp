#include "STetrimino.h"

STetrimino::STetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size, sf::RenderWindow* window ):
	Tetrimino( boardPosition, size, window )
{
	InitTetrimino();
}

void STetrimino::InitTetrimino()
{
	ActivateBlock( 1, 0, Green );
	ActivateBlock( 2, 0, Green );
	ActivateBlock( 0, 1, Green );
	ActivateBlock( 1, 1, Green );
}
