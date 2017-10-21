#pragma once
#include <memory>

#include "SFML\Graphics.hpp"

#include "GameObject.h"

class RenderSystem
{
public:
	RenderSystem( sf::RenderWindow* renderWindow );

	void Render( std::vector< std::unique_ptr< GameObject > >& gameObjects );

private:
	sf::RenderWindow* renderWindow;
};

