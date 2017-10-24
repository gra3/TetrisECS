#pragma once

#include "Tetrimino.h"

class LTetrimino :
	public Tetrimino
{
public:
	LTetrimino();

	//TetriminoContract
	virtual void InitTetrimino() override;
};

