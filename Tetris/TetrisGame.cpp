#include <memory>

#include "Block.h"
#include "BlockContainerComponent.h"
#include "BlockGraphicsComponent.h"
#include "BoardGraphicsComponent.h"
#include "BoardPositionComponent.h"
#include "Component.h"
#include "PositionComponent.h"
#include "RenderSystem.h"
#include "TetriminoBuilder.h"
#include "TetriminoColors.h"
#include "TetrisBoard.h"

#include "TetrisGame.h"

TetrisGame::TetrisGame():
	renderWindow{ std::make_unique< sf::RenderWindow >( sf::VideoMode( 500, 800 ), "Tetris" ) },
	boardSize{ 300, 600 },
	boardStartingPosition{ 100, 100 },
	tetriminoStartingPosition{ 3, 0 }
{
	gameObjects.resize( 2 );
}

void TetrisGame::Start()
{
	CreateTetrisBoard();
	CreateTetrimino();

	RenderSystem renderSystem( this, renderWindow.get() );

	sf::Clock clock;
	clock.restart();
	sf::Time lastTime = clock.getElapsedTime();

	while ( renderWindow->isOpen() )
	{
		renderWindow->clear();

		sf::Time currentTime = clock.getElapsedTime();
		sf::Time elaspedTime = currentTime - lastTime;

		sf::Event event;
		while ( renderWindow->pollEvent( event ) )
		{
			if ( event.type == sf::Event::Closed )
				renderWindow->close();
		}

		renderSystem.Render( gameObjects );

		renderWindow->display();

		lastTime = currentTime;
	}
}

void TetrisGame::CreateTetrisBoard()
{
	auto tetrisBoard = std::make_unique< TetrisBoard >( renderWindow.get() );

	auto positionComponent = std::make_unique< PositionComponent >( boardStartingPosition );
	tetrisBoard->AddComponent( std::move( positionComponent ) );

	auto graphicsComponent = std::make_unique< BoardGraphicsComponent >( boardSize, boardWidthInBlocks, boardHeightInBlocks );
	tetrisBoard->AddComponent( std::move( graphicsComponent ) );

	gameObjects[ Top ].emplace_back( std::move( tetrisBoard ) );
}

void TetrisGame::CreateTetrimino()
{
	auto position = sf::Vector2i( tetriminoStartingPosition.x, tetriminoStartingPosition.y );
	TetriminoBuilder tetriminoBuilder( position, GetBlockSize() );
	auto tetrimino = std::move( tetriminoBuilder.BuildTetrimino( TetriminoBuilder::TTetrimino ) );
	gameObjects[ Bottom ].emplace_back( std::move( tetrimino ) );
}

sf::Vector2f TetrisGame::GetStartingPosition() const
{
	return boardStartingPosition;
}

sf::Vector2f TetrisGame::GetBlockSize() const
{
	return sf::Vector2f( static_cast< float >( ( boardSize.x - 2 * 5 ) / boardWidthInBlocks ), 
								static_cast< float >( ( boardSize.y - 2 * 5 ) / boardHeightInBlocks ) );
}
