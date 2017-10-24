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
			if ( obj->IsActive() )
			{
				auto componentMask = obj->GetComponentMask();
				auto hasPositionComponent = componentMask & Position;
				auto hasGraphicsComponent = componentMask & Graphics;
				auto hasContainerComponent = componentMask & Container;

				if ( hasPositionComponent && hasGraphicsComponent )
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
						x = startingPosition.x + boardPosition->GetX() * sprite->getTextureRect().width;
						y = startingPosition.y + boardPosition->GetY() * sprite->getTextureRect().height;
					}

					sprite->setPosition( sf::Vector2f( x, y ) );

					renderWindow->draw( *sprite );

				}
				else if ( hasContainerComponent )
				{
					auto blockContainer = dynamic_cast< BlockContainerComponent* >( obj->GetComponent( Container ) );
					auto blocks = blockContainer->GetBlocks();
					for( auto& vec : *blocks )
						for ( auto& block : vec )
						{
							if ( block.IsActive() )
							{
								auto position = dynamic_cast< PositionComponent* >( block.GetComponent( Position ) );
								auto x = position->GetX();
								auto y = position->GetY();

								auto graphics = dynamic_cast< GraphicsComponent* >( block.GetComponent( Graphics ) );
								auto sprite = graphics->GetSprite();

								auto boardPosition = dynamic_cast< BoardPositionComponent* >( position );
								auto startingPosition = tetrisGame->GetStartingPosition();
								if ( boardPosition != nullptr )
								{
									x = startingPosition.x + boardPosition->GetX() * sprite->getTextureRect().width;
									y = startingPosition.y + boardPosition->GetY() * sprite->getTextureRect().height;
								}

								sprite->setPosition( sf::Vector2f( x, y ) );

								renderWindow->draw( *sprite );
							}
						}
				}
			}
		}
	}
}
