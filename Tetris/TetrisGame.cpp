#include <memory>

#include "BoardGraphicsComponent.h"
#include "Component.h"
#include "PositionComponent.h"
#include "RenderSystem.h"
#include "TetrisBoard.h"

#include "TetrisGame.h"

TetrisGame::TetrisGame():
	renderWindow{ std::make_unique< sf::RenderWindow >( sf::VideoMode( 500, 800 ), "Tetris" ) }
{
}

void TetrisGame::Start()
{
	std::vector< std::unique_ptr< GameObject > > gameObjects;

	auto tetrisBoard = std::make_unique< TetrisBoard >( sf::Vector2f( 300, 600 ), renderWindow.get() );

	auto positionComponent = std::make_unique< PositionComponent >( sf::Vector2f( 100, 100 ) );
	tetrisBoard->AddComponent(  std::move( positionComponent ) );

	auto graphicsComponent = std::make_unique< BoardGraphicsComponent >( tetrisBoard.get() );
	tetrisBoard->AddComponent( std::move( graphicsComponent ) );

	gameObjects.emplace_back( std::move( tetrisBoard ) );

	RenderSystem renderSystem( renderWindow.get() );

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
