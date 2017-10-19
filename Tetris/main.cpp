#include <iostream>

#include <SFML/Graphics.hpp>

#include "TetrisBoard.h"

int main()
{
	sf::RenderWindow window( sf::VideoMode( 500, 800 ), "Tetris" );
	TetrisBoard board( sf::Vector2f( 300, 590 ), &window );

	sf::Clock clock;
	clock.restart();
	sf::Time lastTime = clock.getElapsedTime();

	while ( window.isOpen() )
	{
		sf::Time currentTime = clock.getElapsedTime();
		sf::Time elaspedTime = currentTime - lastTime;

		sf::Event event;
		while ( window.pollEvent( event ) )
		{
			if ( event.type == sf::Event::Closed )
				window.close();
		}

		board.Update( elaspedTime );

		window.clear();
		board.Draw();
		window.display();

		lastTime = currentTime;
	}

	return 0;
}