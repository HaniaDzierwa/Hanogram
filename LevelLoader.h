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
   
	void loadLevel(std::filesystem::directory_entry element);
	
	
public: 

	LevelLoader();
	~LevelLoader();
	bool load(std::string level);
	std::vector<std::vector<TileLoadData*>>* getTilesLoadData();


	int getAmountFullStates();


};
