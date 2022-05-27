#pragma once
//#include "Grid.h"
#include <vector>
#include "AllTileData.h"
#include <iostream>
#include "TileClickable.h"
#include <future>

// check bool table for game 
class GridValidator
{
	bool** truthTable;
	int size;
	

public:
	GridValidator(std::vector<std::vector<TileLoadData*>>* tilesLoadData,int size);
	~GridValidator();

	void searchForMistakes(std::vector<std::vector<TileClickable*>>* tilesClicked, int first, int last, std::promise<int>& pr);

};