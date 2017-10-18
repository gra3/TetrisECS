#include "OTetrimino.h"

OTetrimino::OTetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window ) :
	Tetrimino( rect, window )
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
