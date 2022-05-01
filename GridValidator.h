#pragma once
//#include "Grid.h"
#include <vector>
#include "AllTileData.h"
#include <iostream>
#include "TileClicked.h"

// check bool table for game 
class GridValidator
{
	bool** truthTable;
	int size;
	

public:
	GridValidator(std::vector<std::vector<TileLoadData*>>* tilesLoadData,int size);
	~GridValidator();

	int searchForMistakes(std::vector<std::vector<TileClicked*>>* tilesClicked );

};