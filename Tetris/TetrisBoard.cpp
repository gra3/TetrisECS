#include "ITetrimino.h"
#include "LTetrimino.h"
#include "JTetrimino.h"
#include "OTetrimino.h"
#include "STetrimino.h"
#include "TTetrimino.h"
#include "ZTetrimino.h"

#include "TetrisBoard.h"

TetrisBoard::TetrisBoard( const sf::Rect< float >& size, sf::RenderWindow* window ) :
	GameObject( size, window )
{
	InitBoardArray();

	auto tetriminoSize = GetBlockWidth() * 4;
	auto x = GetX() + 3 * GetBlockWidth() + borderThickness;
	auto y = GetY() + borderThickness;
	sf::Rect< float > tetriminoRect( x, y, tetriminoSize, tetriminoSize );
	activeTetrimino = std::make_unique< ZTetrimino >( tetriminoRect, window );
}

void TetrisBoard::InitBoardArray()
{
	blockArray.resize( boardWidthInBlocks );
	for ( int i = 0; i < blockArray.size(); i++ )
	{
		for ( int j = 0; j < boardHeightInBlocks; j++ )
		{
			auto x = GetX() + borderThickness + ( GetBlockWidth() * i );
			auto y = GetY() + borderThickness + ( GetBlockHeight() * j );
			sf::Rect< float > blockRect( x, y, GetBlockWidth(), GetBlockHeight() );
			blockArray[i].emplace_back( Block( blockRect, GetRenderWindow() ) );
		}
	}
}

void TetrisBoard::Draw()
{
	DrawBorder();
	DrawBlocks();
	activeTetrimino->Draw();
	DrawGrid();
}

void TetrisBoard::Update( const sf::Time& elapsedTime )
{
	activeTetrimino->Update(  elapsedTime );
}

void TetrisBoard::DrawBorder()
{
	sf::RectangleShape outerBorder( sf::Vector2f( GetWidth(), GetHeight() ) );
	outerBorder.setPosition( GetX(), GetY() );
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
			blockPosition.x = GetX() + borderThickness + ( blockWidth * i );
			blockPosition.y = GetY() + borderThickness + ( blockHeight * j );
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
