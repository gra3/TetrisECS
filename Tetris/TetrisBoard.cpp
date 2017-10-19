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
	GameObject( size, window )
{
	InitBlockArray();

	auto tetriminoSize = sf::Vector2f( GetBlockWidth() * 4, GetBlockHeight() * 4 );
	LTetrimino testrimino( GetStartingTetriminoBoardPosition(), tetriminoSize, window );
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
			blockArray[ x ].emplace_back( Block( boardPosition, size, GetRenderWindow() ) );
		}
	}
}

void TetrisBoard::Draw()
{
	DrawBorder();
	DrawBlocks();
	DrawGrid();
}

void TetrisBoard::Update( const sf::Time& elapsedTime )
{
}

void TetrisBoard::DrawBorder()
{
	sf::RectangleShape outerBorder( sf::Vector2f( GetWidth(), GetHeight() ) );
	//outerBorder.setPosition( GetX(), GetY() );
	outerBorder.setFillColor( sf::Color::Black );
	outerBorder.setOutlineThickness( borderThickness );
	outerBorder.setOutlineColor( sf::Color::White );

	auto renderWindow = GetRenderWindow();
	renderWindow->draw( outerBorder );
}

void TetrisBoard::DrawGrid()
{
	auto blockWidth =   GetBlockWidth();
	auto blockHeight =  GetBlockHeight();
	auto renderWindow = GetRenderWindow();

	for ( int i = 0; i < boardWidthInBlocks; i++ )
		for ( int j = 0; j < boardHeightInBlocks; j++ )
		{
			sf::RectangleShape block( sf::Vector2f( blockWidth, blockHeight ) );
			block.setFillColor( sf::Color::Transparent );
			block.setOutlineThickness( 1 );
			block.setOutlineColor( sf::Color::White );
			sf::Vector2f blockPosition;
			//blockPosition.x = GetX() + borderThickness + ( blockWidth * i );
			//blockPosition.y = GetY() + borderThickness + ( blockHeight * j );
			block.setPosition( blockPosition );

			renderWindow->draw( block );
		}
}

void TetrisBoard::DrawBlocks()
{
	for ( auto& vec : blockArray )
		for ( auto& block : vec )
			block.Draw();
}

float TetrisBoard::GetBlockWidth()
{
	return ( GetWidth() - 2 * borderThickness ) / boardWidthInBlocks;
}

float TetrisBoard::GetBlockHeight()
{
	return ( GetHeight() - 2 * borderThickness ) / boardHeightInBlocks;
}

BoardPositionComponent TetrisBoard::GetStartingTetriminoBoardPosition() const
{
	return BoardPositionComponent( sf::Vector2i( 4, 0 ) );
}
