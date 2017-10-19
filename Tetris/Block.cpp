#include "Block.h"

Block::Block( const BoardPositionComponent& initialBoardPosition, const sf::Vector2f size, sf::RenderWindow* window ):
	GameObject{ size, window },
	boardPosition{ initialBoardPosition },
	active{ false },
	color{ TetriminoColors::Blue }
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

void Block::Draw()
{
	if ( active )
	{
		sf::RectangleShape block( sf::Vector2f( GetWidth(), GetHeight() ) );
		//block.setFillColor( GetBlockColor() );
		//block.setPosition( sf::Vector2f( GetX(), GetY() ) );

		auto renderWindow = GetRenderWindow();
		renderWindow->draw( block );
	}
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
