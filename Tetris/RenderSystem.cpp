#include "BlockContainerComponent.h"
#include "Component.h"
#include "TetrisBoard.h"
#include "TetrisGame.h"

#include "RenderSystem.h"

RenderSystem::RenderSystem( TetrisGame* tetrisGame, sf::RenderWindow* renderWindow ) :
	renderWindow{ renderWindow },
	tetrisGame{ tetrisGame }
{
}

void RenderSystem::Render( std::vector< std::vector< std::unique_ptr< GameObject > > >& gameObjects )
{
	for ( auto& layer : gameObjects )
	{
		for ( auto& obj : layer )
		{
			DrawGameObject( obj.get() );

			DrawAllContainedGameObjects( obj.get() );
		}
	}
}

bool RenderSystem::HasPositionAndGraphicsComponent( GameObject* object ) const
{
	auto componentMask = object->GetComponentMask();
	auto hasPositionComponent = ( componentMask & Position ) > 0;
	auto hasGraphicsComponent = ( componentMask & Graphics ) > 0;

	return hasPositionComponent && hasGraphicsComponent;
}

bool RenderSystem::HasContainerComponent( GameObject* object ) const
{
	auto componentMask = object->GetComponentMask();
	auto hasContainerComponent = ( componentMask & Container ) > 0;

	return hasContainerComponent;
}

void RenderSystem::DrawGameObject( GameObject* obj )
{
	if ( HasPositionAndGraphicsComponent( obj ) )
	{
		auto position = dynamic_cast< PositionComponent* >( obj->GetComponent( Position ) );
		auto x = position->GetX();
		auto y = position->GetY();

		auto graphics = dynamic_cast< GraphicsComponent* >( obj->GetComponent( Graphics ) );
		auto sprite = graphics->GetSprite();

		auto boardPosition = dynamic_cast< BoardPositionComponent* >( position );
		auto startingPosition = tetrisGame->GetStartingPosition();
		if ( boardPosition != nullptr )
		{
			auto borderThickness = tetrisGame->GetBorderThickness();
			x = startingPosition.x + boardPosition->GetX() * sprite->getTextureRect().width + borderThickness;
			y = startingPosition.y + boardPosition->GetY() * sprite->getTextureRect().height + borderThickness;
		}

		sprite->setPosition( sf::Vector2f( x, y ) );

		renderWindow->draw( *sprite );
	}
}

void RenderSystem::DrawAllContainedGameObjects( GameObject* obj )
{
	if ( HasContainerComponent( obj ) )
	{
		auto blockContainer = dynamic_cast< BlockContainerComponent* >( obj->GetComponent( Container ) );
		auto blocks = blockContainer->GetBlocks();
		for ( auto& block : *blocks )
			DrawGameObject( dynamic_cast< GameObject* >( block.get() ) );
	}
}
