#include <memory>
#include <time.h>

#include "Block.h"
#include "BlockContainerComponent.h"
#include "BlockGraphicsComponent.h"
#include "BoardGraphicsComponent.h"
#include "BoardPositionComponent.h"
#include "Component.h"
#include "PhysicsSystem.h"
#include "PositionComponent.h"
#include "RenderSystem.h"
#include "TetriminoBuilder.h"
#include "TetriminoColors.h"
#include "TetrisBoard.h"

#include "TetrisGame.h"

TetrisGame::TetrisGame():
	renderWindow{ std::make_unique< sf::RenderWindow >( sf::VideoMode( 500, 800 ), "Tetris" ) },
	boardSize{ 300, 590 },
	boardStartingPosition{ 100, 100 },
	tetriminoStartingPosition{ 3, 0 }
{
	gameObjects.resize( 2 );
}

void TetrisGame::Start()
{
	srand( static_cast< int >( time( nullptr ) ) );

	CreateTetrisBoard();
	CreateTetrimino();

	RenderSystem renderSystem( this, renderWindow.get() );
	PhysicsSystem physicsSystem;

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

		physicsSystem.DoPhysics( gameObjects, elaspedTime );

		renderSystem.Render( gameObjects );

		renderWindow->display();

		lastTime = currentTime;
	}
}

void TetrisGame::CreateTetrisBoard()
{
	auto tetrisBoard = std::make_unique< TetrisBoard >();

	auto positionComponent = std::make_unique< PositionComponent >( boardStartingPosition );
	tetrisBoard->AddComponent( std::move( positionComponent ) );

	auto graphicsComponent = std::make_unique< BoardGraphicsComponent >( boardSize, GetBoardSizeInBlocks(), GetBorderThickness() );
	tetrisBoard->AddComponent( std::move( graphicsComponent ) );

	gameObjects[ Top ].emplace_back( std::move( tetrisBoard ) );
}

void TetrisGame::CreateTetrimino()
{
	auto randomTetrimino = static_cast< TetriminoBuilder::TetriminoType >( rand() % 6 );
	auto position = sf::Vector2i( tetriminoStartingPosition.x, tetriminoStartingPosition.y );
	TetriminoBuilder tetriminoBuilder( position, GetBlockSize() );
	auto tetrimino = std::move( tetriminoBuilder.BuildTetrimino( randomTetrimino ) );
	gameObjects[ Bottom ].emplace_back( std::move( tetrimino ) );
}

sf::Vector2f TetrisGame::GetStartingPosition() const
{
	return boardStartingPosition;
}

sf::Vector2f TetrisGame::GetBlockSize() const
{
	return sf::Vector2f( static_cast< float >( ( boardSize.x - 2 * borderThickness ) / boardWidthInBlocks ), 
								static_cast< float >( ( boardSize.y - 2 * borderThickness ) / boardHeightInBlocks ) );
}

sf::Vector2i TetrisGame::GetBoardSizeInBlocks() const
{
	return sf::Vector2i( boardWidthInBlocks, boardHeightInBlocks );
}

int TetrisGame::GetBorderThickness() const
{
	return borderThickness;
}
