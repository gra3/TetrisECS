#include "STetrimino.h"

STetrimino::STetrimino( const sf::Rect< float >& rect, sf::RenderWindow* window ) :
	Tetrimino( rect, window )
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
