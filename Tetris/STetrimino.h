#pragma once

#include "Tetrimino.h"

class STetrimino :
	public Tetrimino
{
public:
	STetrimino();

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

