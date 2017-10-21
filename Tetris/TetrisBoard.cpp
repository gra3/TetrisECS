#include "BoardPositionComponent.h"
#include "ITetrimino.h"
#include "LTetrimino.h"
#include "JTetrimino.h"
#include "OTetrimino.h"
#include "STetrimino.h"
#include "TTetrimino.h"
#include "ZTetrimino.h"

#include "TetrisBoard.h"

TetrisBoard::TetrisBoard( const sf::Vector2f& size, sf::RenderWindow* window ) :
	GameObject( size )
{
	InitBlockArray();

	auto tetriminoSize = sf::Vector2f( GetBlockWidth() * 4, GetBlockHeight() * 4 );
	LTetrimino testrimino( GetStartingTetriminoBoardPosition(), tetriminoSize );
}

void TetrisBoard::InitBlockArray()
{
	blockArray.resize( boardWidthInBlocks );
	for ( int x = 0; x < blockArray.size(); x++ )
	{
		for ( int y = 0; y < boardHeightInBlocks; y++ )
		{
			auto boardPosition = BoardPositionComponent( sf::Vector2i( x, y ) );
			auto size = sf::Vector2f( GetBlockWidth(), GetBlockHeight() );
			blockArray[ x ].emplace_back( Block( boardPosition, size ) );
		}
	}
}

void TetrisBoard::Update( const sf::Time& elapsedTime )
{
}

float TetrisBoard::GetBlockWidth() const
{
	return ( GetWidth() - 2 * borderThickness ) / boardWidthInBlocks;
}

float TetrisBoard::GetBlockHeight() const
{
	return ( GetHeight() - 2 * borderThickness ) / boardHeightInBlocks;
}

int TetrisBoard::GetBoardWidthInBlocks() const
{
	return boardWidthInBlocks;
}

int TetrisBoard::GetBoardHeightInBlocks() const
{
	return boardHeightInBlocks;
}

BoardPositionComponent TetrisBoard::GetStartingTetriminoBoardPosition() const
{
	return BoardPositionComponent( sf::Vector2i( 4, 0 ) );
}
