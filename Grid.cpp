#include "Grid.h"



void Grid::initTiles()
{
	
	for (int i = maxNumbers*tileSize; i < size * tileSize; i +=tileSize)
	{
		std::vector<Tile*> rowC;
		for (int j = maxNumbers*tileSize; j < size * tileSize; j += tileSize)
		{
			rowC.push_back(new TileClicked(sf::Vector2f(j+gridOffSet.x, i+gridOffSet.y), sf::Color(0,0,0),tileSize, textureManager));
		}
		this->tilesClicked.push_back(rowC);

	}

	for (int i = 0; i < size * tileSize; i += tileSize)
	{
		std::vector<Tile*> rowN;
		for (int j = 0; j < size * tileSize; j += tileSize)
		{
			{
				rowN.push_back(new TileNumber(sf::Vector2f(j + gridOffSet.x, i + gridOffSet.y), tileSize, 6));
			}
			
		}
		this->tilesNumber.push_back(rowN);

	}

	
}

void Grid::initLines()
{
	
	this->thicknesCoastline = 5.f;
	this->coastlineHorizontal.setSize(sf::Vector2f(((float)this->size * tileSize), thicknesCoastline));
	this->coastlineHorizontal.setFillColor(sf::Color::Black);

	this->coastlineVertical.setSize(sf::Vector2f(((float)this->size * tileSize), thicknesCoastline));
	this->coastlineVertical.setFillColor(sf::Color::Black);

 this->coastlineHorizontalup.setSize(sf::Vector2f(((float)(this->size-maxNumbers) * tileSize), thicknesCoastline));
 this->coastlineHorizontalup.setFillColor(sf::Color::Black);

 this->coastlineVerticalSide.setSize(sf::Vector2f(((float)(this->size-maxNumbers) * tileSize), thicknesCoastline));
 this->coastlineVerticalSide.setFillColor(sf::Color::Black);
}

Grid::Grid(int Levelsize, sf::RenderWindow* window, TextureManager *textureManager)
{
	this->textureManager = textureManager;
	this->maxNumbers = 4; // read from file
	this->size = Levelsize+maxNumbers;
	tileSize = AllTileData::tileSize / this->size;
	this->gridOffSet = sf::Vector2f((window->getSize().x-this->size*this->tileSize)/2 , (window->getSize().y - this->size *this->tileSize)/ 2 );
	initTiles();
	initLines();
	this->boxSize = AllTileData::boxSize; 
	
	
	
}

Grid::~Grid()
{
	// destructor tileClicked
	for (int i = 0; i < tilesClicked.size(); i++)
	{
		for (int j = 0; j < tilesClicked[i].size(); j++)
		{
			delete this->tilesClicked[i][j];
		}
	}
	// desctructor tileNumber
	for (int i = 0; i < tilesNumber.size(); i++)
	{
		for (int j = 0; j < tilesNumber[i].size(); j++)
		{
			delete this->tilesNumber[i][j];
		}

	}

	
	

}

void Grid::updateTiles(const sf::Vector2f mousePos, TileStateSelect tileStateSelect)
{
    for (int i = 0; i < tilesClicked.size(); i++)
	{
		for (int j = 0; j < tilesClicked[i].size(); j++)
		{
			tilesClicked[i][j]->update(mousePos,&(this->clock), tileStateSelect);

		}
	}
	
}
void Grid::update(const sf::Vector2f mousePos, TileStateSelect tileStateSelect)
{
	updateTiles(mousePos,tileStateSelect);
	
}
void Grid::renderLines(sf::RenderTarget* target)
{
	this->coastlineHorizontalup.setPosition(sf::Vector2f(gridOffSet.x +maxNumbers*tileSize,  gridOffSet.y));
	target->draw(this->coastlineHorizontalup);

	this->coastlineVerticalSide.setPosition(sf::Vector2f( gridOffSet.x, gridOffSet.y + maxNumbers * tileSize));
	this->coastlineVerticalSide.setRotation(90);
	target->draw(this->coastlineVerticalSide);

	for (int i = maxNumbers*tileSize ; i< ((this->size+1) * this->tileSize); i += this->tileSize)
	{
		
		if ((i - (maxNumbers * tileSize)) % (this->boxSize* this->tileSize ) == 0 )   
		{
			this->coastlineHorizontal.setPosition(sf::Vector2f(gridOffSet.x , i+gridOffSet.y));
			target->draw(this->coastlineHorizontal);
			
			this->coastlineVertical.setPosition(sf::Vector2f(i+gridOffSet.x, gridOffSet.y));
			this->coastlineVertical.setRotation(90);
			target->draw(this->coastlineVertical);
		}
		

	}
	
}

void Grid::renderTilesClicked(sf::RenderTarget* target)
{
	for (int i =0 ; i < this->size - maxNumbers ; i ++)
	{
		for (int j =0 ; j < this->size- maxNumbers; j ++)
		{
				tilesClicked[i][j]->render(target);
		}	
	}


	
}
void Grid::renderTilesNumbers(sf::RenderTarget* target)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (!(i >= 0 and i < maxNumbers and j >= 0 and j < maxNumbers))
			tilesNumber[i][j]->render(target);
		}
	}
}


void Grid::render(sf::RenderTarget* target)
{
	renderTilesNumbers(target);
	renderTilesClicked(target);
	renderLines(target);
	
}
