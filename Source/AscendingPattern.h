#pragma once
#include "Pattern.h"
class AscendingPattern :
	public Pattern
{
public:
	AscendingPattern();
	~AscendingPattern();
	void buildCells(const bool noteOns[], vector<vector<Cell> > &grid);
};

