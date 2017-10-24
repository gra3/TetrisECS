#pragma once

#include "Tetrimino.h"

class ITetrimino :
	public Tetrimino
{
public:
	ITetrimino();

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

