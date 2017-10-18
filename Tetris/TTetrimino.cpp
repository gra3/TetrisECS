#include "TTetrimino.h"

TTetrimino::TTetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window ):
	Tetrimino( rect, window )
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
