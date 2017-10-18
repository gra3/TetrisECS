#include "ZTetrimino.h"

ZTetrimino::ZTetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window ):
	Tetrimino( rect, window )
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
