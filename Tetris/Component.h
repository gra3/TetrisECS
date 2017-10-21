#pragma once

#include "ComponentIDs.h"

class Component
{
public:
	Component();

	virtual ComponentID GetComponentID() const = 0;
};

