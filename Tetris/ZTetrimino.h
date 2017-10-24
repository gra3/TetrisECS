#pragma once

#include "Tetrimino.h"

class ZTetrimino :
	public Tetrimino
{
public:
	ZTetrimino();

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

