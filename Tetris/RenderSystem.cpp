#include "Component.h"
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
		auto componentMask = obj->GetComponentMask();
		auto hasPositionComponent = componentMask & ( Position | Graphics );
		auto hasGraphicsComponent = componentMask & Graphics;

		if ( hasPositionComponent && hasGraphicsComponent )
		{
			auto position = dynamic_cast< PositionComponent* >( obj->GetComponent( Position ) );
			auto graphics = dynamic_cast< GraphicsComponent* >( obj->GetComponent( Graphics ) );

			auto sprite = graphics->GetSprite();
			sprite->setPosition( position->GetPosition() );
			
			renderWindow->draw( *sprite );
		}
	}
}
