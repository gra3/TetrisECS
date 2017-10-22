#include <memory>

#include "Block.h"
#include "BlockGraphicsComponent.h"
#include "BoardGraphicsComponent.h"
#include "Component.h"
#include "PositionComponent.h"
#include "RenderSystem.h"
#include "TetriminoColors.h"
#include "TetrisBoard.h"

#include "TetrisGame.h"

TetrisGame::TetrisGame():
	renderWindow{ std::make_unique< sf::RenderWindow >( sf::VideoMode( 500, 800 ), "Tetris" ) },
	boardStartingPosition{ 100, 100 },
	boardSize{ 300, 600 }
{
	gameObjects.resize( 2 );
}

void TetrisGame::Start()
{
	CreateTetrisBoard();
	CreateBlocks();

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

void TetrisGame::CreateBlocks()
{
	for ( int x = 0; x < boardWidthInBlocks; x++ )
	{
		for ( int y = 0; y < boardHeightInBlocks; y++ )
		{
			auto block = std::make_unique< Block >();

			auto boardPositionComponent = std::make_unique< BoardPositionComponent >( sf::Vector2i( x, y ) );
			block->AddComponent( std::move( boardPositionComponent ) );

			auto blockWidth = static_cast< float >( boardSize.x / boardWidthInBlocks );
			auto blockHeight = static_cast< float >( boardSize.y / boardHeightInBlocks );
			sf::Vector2f blockSize( blockWidth, blockHeight );
			auto blockGraphicsComponent = std::make_unique< BlockGraphicsComponent >( blockSize, TetriminoColors::Blue );
			block->AddComponent( std::move( blockGraphicsComponent ) );

			block->Activate();

			gameObjects[ Bottom ].emplace_back( std::move( block ) );
		}
	}
}

sf::Vector2f TetrisGame::GetStartingPosition() const
{
	return boardStartingPosition;
}
