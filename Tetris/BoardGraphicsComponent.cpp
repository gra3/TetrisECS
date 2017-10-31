#include <wtypes.h>

#include "TetrisBoard.h"

#include "BoardGraphicsComponent.h"

BoardGraphicsComponent::BoardGraphicsComponent( const sf::Vector2i size, const sf::Vector2i& boardSizeInBlocks, int borderThickness ) :
	GraphicsComponent{},
	borderThickness{ static_cast< float >( borderThickness ) },
	boardSize{ size },
	boardSizeInBlocks{ boardSizeInBlocks }
{
	LoadSprite();
}

void BoardGraphicsComponent::LoadSprite()
{
	sf::RenderTexture renderTexture;
	renderTexture.create( boardSize.x, boardSize.y );

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

	auto blockWidth = ( boardSize.x - 2 * borderThickness ) / boardSizeInBlocks.x;
	auto blockHeight = ( boardSize.y - 2 * borderThickness ) / boardSizeInBlocks.y;

	for ( int i = 0; i < boardSizeInBlocks.x; i++ )
		for ( int j = 0; j < boardSizeInBlocks.y; j++ )
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
