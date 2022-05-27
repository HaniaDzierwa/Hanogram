#include "LevelLoader.h"
#include "invalidRGBvalueExceptionsh.h"

LevelLoader::LevelLoader()
{
	this->pathToLevels = "C:\\Users\\hania\\Desktop\\Hanogram2\\Hanogram2\\Hanogram2\\Level";
	
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
	return &(this->tilesLoadData);
}

int LevelLoader::getMaxAmountOfNumberGeneral()
{
	return this->maxAmountOfNumbersGeneral;
}

std::vector<std::vector<int>>* LevelLoader::getRowsNumbers()
{
	return &(this->rowsNumbers);
}

std::vector<std::vector<int>>* LevelLoader::getColumnsNumbers()
{
	return &(this->columnsNumbers);
}

int LevelLoader::getAmountFullStates()
{
	return this->amountFullStates;
}

bool LevelLoader::load( std::string level)
{
	

	for (auto const& dir_entry : std::filesystem::directory_iterator(this->pathToLevels))
	{
		if (dir_entry.exists() and dir_entry.path().filename().generic_string() == level)
		{
			for (auto& element : std::filesystem::directory_iterator(dir_entry))
			{
				if (element.exists() && element.path().extension() == ".txt")


					//todo 
					//losowo wybierany plik o rozszerzeniu .txt 
				{
					try 
					{ 
						loadLevel(element);
					}
					catch (invalidRGBvalueExcepions e)
					{
						
						throw;
					}
					
				}
				else
					std::cout << " Couldn't load level \n";//throw exception

			}
		}

	}
	
	std::cout << "Level loaded\n";

	return true; 

}


void  LevelLoader::loadLevel(std::filesystem::directory_entry element)
{
	std::fstream file;
	file.open(element);
	std::string line;
	int counter = 0;
	int variables[5] = { 0 };
	int currentVal = 0;
	int size = 0;
	int i = 0;
	int j = 0;

   std::regex reg("^([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])$");

	file >> size; 

	for (int i = 0; i < size; i++)
	{
		std::vector<TileLoadData*> vec;
		for (int j = 0; j < size*dataPerRow; j++)
		{
			file >> currentVal;
			if(!(std::regex_match(std::to_string(currentVal), reg)))  
			{
				file.close();
				int position = i * size + vec.size() +1 ; // ustalenie numeru wiersza
				position *= 2; // korekta pustych linii w pliku wejciowym
				position += 1; // korekta naglowku z rozmiarem wczytywanej tablicy
				throw  invalidRGBvalueExcepions(element.path().string(), position, currentVal);
			}

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
	file >> maxAmountOfNumbersGeneral;
	
	for (int i = 0; i < size; i++)
	{
		std::vector<int> numbers;
		for (int j = 0; j < maxAmountOfNumbersGeneral; j++)
		{
			int number;
			file >> number;
			numbers.push_back(number);
		}
		rowsNumbers.push_back(numbers);
	}

	for (int i = 0; i < size; i++)
	{
		std::vector<int> numbers;
		for (int j = 0; j < maxAmountOfNumbersGeneral;j++)
		{
			int number;
			file >> number;
			numbers.push_back(number);
		}
		columnsNumbers.push_back(numbers);
	}
	
	file.close();
}



	

