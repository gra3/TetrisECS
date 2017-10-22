#include "BlockGraphicsComponent.h"

#include "TetrisBoard.h"

BlockGraphicsComponent::BlockGraphicsComponent( const sf::Vector2f& size, TetriminoColors color ) :
	GraphicsComponent{},
	blockSize{ size },
	color{ color }
{
	LoadSprite();
}

void BlockGraphicsComponent::LoadSprite()
{
	sf::RenderTexture renderTexture;
	auto renderTextureWidth = static_cast< int >( blockSize.x );
	auto renderTextureHeight = static_cast< int >( blockSize.y );
	renderTexture.create( renderTextureWidth , renderTextureHeight  );

	sf::RectangleShape rectangle( blockSize );
	rectangle.setFillColor( GetBlockColor() );
	renderTexture.draw( rectangle );

	*texture = renderTexture.getTexture();
	sprite->setTexture( *texture.get() );
}

sf::Color BlockGraphicsComponent::GetBlockColor() const
{
	sf::Color sfColor = sf::Color::Blue;

	switch ( color )
	{
	case LightBlue:
		sfColor = sf::Color::Cyan;
		break;

	case Blue:
		sfColor = sf::Color::Blue;
		break;

	case Orange:
		sfColor.r = 255;
		sfColor.g = 165;
		sfColor.b = 0;
		break;

	case Yellow:
		sfColor = sf::Color::Yellow;
		break;

	case Green:
		sfColor = sf::Color::Green;
		break;

	case Purple:
		sfColor.r = 128;
		sfColor.g = 0;
		sfColor.b = 128;
		break;

	case Red:
		sfColor = sf::Color::Red;
		break;
	}

	return sfColor;
}