#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

#include "AllTileData.h"
#include <regex>

class LevelLoader {

	std::string pathToLevels;
	int amountFullStates = 0;
	const int dataPerRow = 5;
	std::vector<std::vector<TileLoadData*>> tilesLoadData;

 
	int maxAmountOfNumbersGeneral;
	std::vector<std::vector<int>> rowsNumbers;
	std::vector<std::vector<int>> columnsNumbers;

	void loadLevel(std::filesystem::directory_entry element);
	
	
	
public: 

	LevelLoader();
	~LevelLoader();
	bool load(std::string level);
	std::vector<std::vector<TileLoadData*>>* getTilesLoadData();

	int getMaxAmountOfNumberGeneral();

	std::vector<std::vector<int>>* getRowsNumbers();
	std::vector<std::vector<int>>* getColumnsNumbers();

	int getAmountFullStates();


};
