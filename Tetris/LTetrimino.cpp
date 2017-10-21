#include "LTetrimino.h"

LTetrimino::LTetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size ) :
	Tetrimino( boardPosition, size )
{
	InitTetrimino();
}

void LTetrimino::InitTetrimino()
{
	ActivateBlock( 2, 0, Orange );
	ActivateBlock( 0, 1, Orange );
	ActivateBlock( 1, 1, Orange );
	ActivateBlock( 2, 1, Orange );
}
