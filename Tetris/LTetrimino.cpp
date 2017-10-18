#include "LTetrimino.h"

LTetrimino::LTetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window ):
	Tetrimino( rect, window )
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
