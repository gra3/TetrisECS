#include "Block.h"

Block::Block( const BoardPositionComponent& initialBoardPosition, const sf::Vector2f size ):
	GameObject{ size },
	boardPosition{ initialBoardPosition }
{
}

void Block::SetColor( TetriminoColors color )
{
	this->color = color;
}

void Block::Activate()
{
	active = true;
}

void Block::Deactivate()
{
	active = false;
}

void Block::Update( const sf::Time& elapsedTime )
{
}

sf::Color Block::GetBlockColor() const
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
