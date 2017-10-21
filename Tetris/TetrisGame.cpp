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
	gameObjects.emplace_back( std::make_unique< TetrisBoard >( sf::Vector2f( 300, 600 ), renderWindow.get() ) );

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
