#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "Block.h"
#include "BoardGraphicsComponent.h"
#include "GameObject.h"
#include "PositionComponent.h"
#include "Tetrimino.h"

class TetrisBoard :
	public GameObject
{
public:
	TetrisBoard();
};

