#pragma once

#include "Tetrimino.h"

class OTetrimino :
	public Tetrimino
{
public:
	OTetrimino();

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

