#include "Tetrimino.h"

#include "TetriminoBuilder.h"

TetriminoBuilder::TetriminoBuilder( const sf::Vector2i& startingPosition, const sf::Vector2f& tetriminoSize ) :
	startingPosition{ startingPosition },
	size{ tetriminoSize }
{
}

std::unique_ptr< Tetrimino > TetriminoBuilder::BuildTetrimino( TetriminoType type ) const
{
	auto tetrimino = std::make_unique< Tetrimino >();

	switch ( type )
	{
		case ITetrimino:
			tetrimino->AddBlock( size, GetBoardPosition( 0, 0 ), LightBlue );
			tetrimino->AddBlock( size, GetBoardPosition( 1, 0 ), LightBlue );
			tetrimino->AddBlock( size, GetBoardPosition( 2, 0 ), LightBlue );
			tetrimino->AddBlock( size, GetBoardPosition( 3, 0 ), LightBlue );
			break;

		case LTetrimino:
			tetrimino->AddBlock( size, GetBoardPosition( 0, 1 ), Orange );
			tetrimino->AddBlock( size, GetBoardPosition( 1, 1 ), Orange );
			tetrimino->AddBlock( size, GetBoardPosition( 2, 1 ), Orange );
			tetrimino->AddBlock( size, GetBoardPosition( 2, 0 ), Orange );
			break;

		case JTetrimino:
			tetrimino->AddBlock( size, GetBoardPosition( 0, 1 ), Blue );
			tetrimino->AddBlock( size, GetBoardPosition( 1, 1 ), Blue );
			tetrimino->AddBlock( size, GetBoardPosition( 2, 1 ), Blue );
			tetrimino->AddBlock( size, GetBoardPosition( 0, 0 ), Blue );
			break;

		case OTetrimino:
			tetrimino->AddBlock( size, GetBoardPosition( 1, 1 ), Yellow );
			tetrimino->AddBlock( size, GetBoardPosition( 2, 1 ), Yellow );
			tetrimino->AddBlock( size, GetBoardPosition( 1, 0 ), Yellow );
			tetrimino->AddBlock( size, GetBoardPosition( 2, 0 ), Yellow );
			break;

		case ZTetrimino:
			tetrimino->AddBlock( size, GetBoardPosition( 1, 1 ), Red );
			tetrimino->AddBlock( size, GetBoardPosition( 2, 1 ), Red );
			tetrimino->AddBlock( size, GetBoardPosition( 0, 0 ), Red );
			tetrimino->AddBlock( size, GetBoardPosition( 1, 0 ), Red );
			break;

		case STetrimino:
			tetrimino->AddBlock( size, GetBoardPosition( 0, 1 ), Green );
			tetrimino->AddBlock( size, GetBoardPosition( 1, 1 ), Green );
			tetrimino->AddBlock( size, GetBoardPosition( 1, 0 ), Green );
			tetrimino->AddBlock( size, GetBoardPosition( 2, 0 ), Green );
			break;

		case TTetrimino:
			tetrimino->AddBlock( size, GetBoardPosition( 0, 1 ), Purple );
			tetrimino->AddBlock( size, GetBoardPosition( 1, 1 ), Purple );
			tetrimino->AddBlock( size, GetBoardPosition( 2, 1 ), Purple );
			tetrimino->AddBlock( size, GetBoardPosition( 1, 0 ), Purple );
			break;
	}

	return std::move( tetrimino );
}

sf::Vector2i TetriminoBuilder::GetBoardPosition( int x, int y ) const
{
	return sf::Vector2i( startingPosition.x + x, startingPosition.y + y );
}
