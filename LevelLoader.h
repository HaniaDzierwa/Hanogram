#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

#include "AllTileData.h"

class LevelLoader {

	std::string pathToLevels;
	int amountFullStates = 0;
	const int dataPerRow = 5;
	std::vector<std::vector<TileLoadData*>> tilesLoadData;
    void load(std::string pathToLevels, std::string level);
	void loadLevel(std::filesystem::directory_entry element);
	
public: 

	LevelLoader(std::string level);
	~LevelLoader();

	std::vector<std::vector<TileLoadData*>>* getTilesLoadData();


	int getAmountFullStates();


};
