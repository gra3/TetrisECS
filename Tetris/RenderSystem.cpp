#include "TetrisBoard.h"

#include "RenderSystem.h"

RenderSystem::RenderSystem( sf::RenderWindow* renderWindow ) :
	renderWindow{ renderWindow }
{
}

void RenderSystem::Render( std::vector< std::unique_ptr< GameObject > >& gameObjects )
{
	for ( auto& obj : gameObjects )
	{
		auto tetrisBoard = dynamic_cast< TetrisBoard* >( obj.get() );
		if ( tetrisBoard != nullptr )
		{
			auto position = tetrisBoard->GetPositionComponent();
			auto graphics = tetrisBoard->GetGraphicsComponent();

			auto sprite = graphics->GetSprite();
			sprite->setPosition( position->GetPosition() );
			
			renderWindow->draw( *sprite );
		}
	}
}
