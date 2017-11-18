#include "BodyComponent.h"

BodyComponent::BodyComponent( const sf::Vector2f& body, bool inclusive ) :
	body{ body },
	isInclusive{ inclusive }
{
}

sf::Vector2f BodyComponent::GetBody() const
{
	return body;
}

bool BodyComponent::IsInclusive() const
{
	return isInclusive;
}

ComponentID BodyComponent::GetComponentID() const
{
	return Body;
}
