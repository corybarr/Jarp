#pragma once
#include <vector>
#include "Cell.h"
using std::vector;

class Pattern
{
public:
	Pattern();
	~Pattern();
	 virtual void buildCells(const bool noteOns[], vector<vector<Cell> > &grid) = 0;
};

