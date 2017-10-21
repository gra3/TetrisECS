#include "ITetrimino.h"

ITetrimino::ITetrimino( const BoardPositionComponent& boardPosition, const sf::Vector2f& size ):
	Tetrimino( boardPosition, size )
{
	InitTetrimino();
}

void ITetrimino::InitTetrimino()
{
	ActivateBlock( 0, 0, LightBlue );
	ActivateBlock( 1, 0, LightBlue );
	ActivateBlock( 2, 0, LightBlue );
	ActivateBlock( 3, 0, LightBlue );
}
