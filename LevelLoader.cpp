#include "LevelLoader.h"

LevelLoader::LevelLoader(std::string level)
{
	this->pathToLevels = "C:\\Users\\hania\\Desktop\\Hanogram2\\Hanogram2\\Hanogram2\\Level";
	load(pathToLevels, level);
}

LevelLoader::~LevelLoader()
{
	for (int i = 0; i < tilesLoadData.size(); i++)
	{
		for (int j = 0; j < tilesLoadData[i].size(); j++)
		{
			delete this->tilesLoadData[i][j];
		}
	}
}

std::vector<std::vector<TileLoadData*>>* LevelLoader::getTilesLoadData()
{
	return &(tilesLoadData);
}

int LevelLoader::getAmountFullStates()
{
	return this->amountFullStates;
}

void LevelLoader::load(std::string pathToLevels, std::string level)
{
	for (auto const& dir_entry : std::filesystem::directory_iterator(pathToLevels))
	{
		if (dir_entry.exists() and dir_entry.path().filename().generic_string() == level)
		{
			for (auto& element : std::filesystem::directory_iterator(dir_entry))
			{
				if (element.exists() && element.path().extension() == ".txt")


					//todo 
					//losowo wybierany plik o rozszerzeniu .txt preferowany krzys.txt
				{
					loadLevel(element);

				}
				else
					std::cout << " Couldn't load level \n";//throw exception

			}
		}

	}
	std::cout << "Level loaded";


}


void LevelLoader::loadLevel(std::filesystem::directory_entry element)
{
	std::fstream file;
	file.open(element);
	std::string line;
	int counter = 0;
	int variables[5] = { 0 };
	int currentVal = 0;
	int size = 0;
	

	file >> size; 

	int i = 0;
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		std::vector<TileLoadData*> vec;

		for (int j = 0; j < size*dataPerRow; j++)
		{
			file >> currentVal;

			variables[counter] = currentVal;
			counter++;

			if (counter == dataPerRow)
			{
				counter = 0;
				sf::Color color(variables[0], variables[1], variables[2]);
				vec.push_back(new TileLoadData(color, (bool) variables[3], (bool)variables[4]));

			}
	
		}
		this->tilesLoadData.push_back(vec);
	}

	file >> amountFullStates;
}



	

