#include "JTetrimino.h"

JTetrimino::JTetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window ):
	Tetrimino( rect, window )
{
	InitTetrimino();
}

void JTetrimino::InitTetrimino()
{
	ActivateBlock( 0, 0, Blue );
	ActivateBlock( 0, 1, Blue );
	ActivateBlock( 1, 1, Blue );
	ActivateBlock( 2, 1, Blue );
}
