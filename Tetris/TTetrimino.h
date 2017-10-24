#pragma once

#include "Tetrimino.h"

class TTetrimino :
	public Tetrimino
{
public:
	TTetrimino();

	//TetriminoContract
	virtual void InitTetrimino() override;
};

