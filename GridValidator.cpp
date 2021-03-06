#include "GridValidator.h"


GridValidator::GridValidator(std::vector<std::vector<TileLoadData*>>* tilesLoadData,int size)
{
	this->size = size;
	this->truthTable = new bool* [size];
	for (int i = 0; i < size ; i++)
	{
		this->truthTable[i] = new bool[size];

		for (int j = 0; j < size; j++)
		{
			this->truthTable[i][j] = (*tilesLoadData)[i][j]->endState;
		}
	}
	std::cout << "Loaded truth table\n";

}
	

GridValidator::~GridValidator()
{
	for (int i=0; i < this->size; i++)
		delete[] truthTable[i]; 
	delete[] truthTable; 
	truthTable = NULL;
}

void GridValidator::searchForMistakes(std::vector<std::vector<TileClickable*>>* tilesClicked, int first, int last, std::promise<int>& pr )
{
	bool stateTilesClicked= 0;
    int mistake = 0;

	//debbug bool table
	/*for (int i = 0; i < size; i++)
	{


		for (int j = 0; j < size; j++)
		{
			std::cout << (*tilesClicked)[i][j]->getTileState() << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n";*/


	for (int i = first; i < last; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((*tilesClicked)[i][j]->getTileState() == fullState)
				stateTilesClicked = true;
			else
				stateTilesClicked = false;

			if (this->truthTable[i][j] != stateTilesClicked)
				mistake++;
			
		}
	}
	pr.set_value(mistake);
}


