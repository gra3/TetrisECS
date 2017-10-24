#pragma once

#include "Tetrimino.h"

class JTetrimino :
	public Tetrimino
{
public:
	JTetrimino();

	//Tetrimino contract
	virtual void InitTetrimino() override;
};

