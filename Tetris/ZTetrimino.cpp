#include "ZTetrimino.h"

ZTetrimino::ZTetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size ) :
	Tetrimino( boardPosition, size )
{
	InitTetrimino();
}

void ZTetrimino::InitTetrimino()
{
	ActivateBlock( 0, 0, Red );
	ActivateBlock( 1, 0, Red );
	ActivateBlock( 1, 1, Red );
	ActivateBlock( 2, 1, Red );
}
