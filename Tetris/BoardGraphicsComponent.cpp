#include <wtypes.h>

#include "TetrisBoard.h"

#include "BoardGraphicsComponent.h"

BoardGraphicsComponent::BoardGraphicsComponent( TetrisBoard* board ):
	GraphicsComponent{},
	tetrisBoard{ board }
{
	LoadSprite();
}

void BoardGraphicsComponent::LoadSprite()
{
	sf::RenderTexture renderTexture;
	auto boardWidth = static_cast< UINT >( tetrisBoard->GetWidth() );
	auto boardHeight = static_cast< UINT >( tetrisBoard->GetHeight() );
	sf::Vector2i boardSize( boardWidth, boardHeight );
	renderTexture.create( boardWidth, boardHeight );

	DrawBorder( &renderTexture );
	DrawGrid( &renderTexture );

	*texture = renderTexture.getTexture();
	sprite->setTexture( *texture.get() );
}

void BoardGraphicsComponent::DrawBorder( sf::RenderTexture* renderTexture ) const
{
	auto textureSize = renderTexture->getSize();
	auto boardWidth = static_cast< float >( textureSize.x );
	auto boardHeight = static_cast< float >( textureSize.y );

	sf::RectangleShape outerBorder( sf::Vector2f( boardWidth, boardHeight ) );

	outerBorder.setFillColor( sf::Color::Transparent );
	outerBorder.setOutlineThickness( -borderThickness );
	outerBorder.setOutlineColor( sf::Color::White );

	renderTexture->draw( outerBorder );
}

void BoardGraphicsComponent::DrawGrid( sf::RenderTexture* renderTexture ) const
{
	auto textureSize = renderTexture->getSize();
	auto boardWidth = textureSize.x;
	auto boardHeight = textureSize.y;
	auto blockWidth = tetrisBoard->GetBlockWidth();
	auto blockHeight = tetrisBoard->GetBlockHeight();

	for ( int i = 0; i < tetrisBoard->GetBoardWidthInBlocks(); i++ )
		for ( int j = 0; j < tetrisBoard->GetBoardHeightInBlocks(); j++ )
		{
			sf::RectangleShape block( sf::Vector2f( blockWidth, blockHeight ) );
			block.setFillColor( sf::Color::Transparent );
			block.setOutlineThickness( 1 );
			block.setOutlineColor( sf::Color::White );
			sf::Vector2f blockPosition;
			blockPosition.x = borderThickness + ( blockWidth * i );
			blockPosition.y = borderThickness + ( blockHeight * j );
			block.setPosition( blockPosition );

			renderTexture->draw( block );
		}
}
