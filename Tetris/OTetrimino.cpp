#include "OTetrimino.h"

OTetrimino::OTetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size ) :
	Tetrimino( boardPosition, size )
{
	InitTetrimino();
}

void OTetrimino::InitTetrimino()
{
	ActivateBlock( 1, 0, Yellow );
	ActivateBlock( 1, 1, Yellow );
	ActivateBlock( 2, 0, Yellow );
	ActivateBlock( 2, 1, Yellow );
}
