#include "Grid.h"
#include "TileData.h"

void Grid::initTiles()
{
	for (int i = 0; i < size * TileData::tileSize; i += TileData::tileSize)
	{
		std::vector<Tile*> row;
		for (int j = 0; j < size * TileData::tileSize; j += TileData::tileSize)
		{
			row.push_back(new Tile(sf::Vector2f(j+gridOffSet.x, i+gridOffSet.y), sf::Color(0,0,0)));
		}
		this->tiles.push_back(row);

	}

}

void Grid::initLines()
{
	
	this->thicknesCoastline = 5.f;
	this->coastlineHorizontal.setSize(sf::Vector2f(((float)this->size * TileData::tileSize), thicknesCoastline));
	this->coastlineHorizontal.setFillColor(sf::Color::Black);

	this->coastlineVertical.setSize(sf::Vector2f(((float)this->size * TileData::tileSize), thicknesCoastline));
	this->coastlineVertical.setFillColor(sf::Color::Black);

}

Grid::Grid(int size, sf::RenderWindow* window)
{
	this->size = size;
	this->gridOffSet = sf::Vector2f((window->getSize().x-size*TileData::tileSize)/2 , (window->getSize().y - size * TileData::tileSize)/ 2 );
	initTiles();
	initLines();
	this->boxSize = 5; // size of the big blocks to make game easier ( squares 5x5 with boarder line)

}

Grid::~Grid()
{
}

void Grid::updateTiles(const sf::Vector2f mousePos)
{
	
}
void Grid::update(const sf::Vector2f mousePos)
{
	
}
void Grid::renderLines(sf::RenderTarget* target)
{
	for (int i = 0; i < (size +1) * TileData::tileSize; i += TileData::tileSize)
	{
		if (i % (this->boxSize*TileData::tileSize) == 0 )
		{
			this->coastlineHorizontal.setPosition(sf::Vector2f(gridOffSet.x, i+gridOffSet.y));
			target->draw(this->coastlineHorizontal);
			
			this->coastlineVertical.setPosition(sf::Vector2f(i+gridOffSet.x, gridOffSet.y));
			this->coastlineVertical.setRotation(90);
			target->draw(this->coastlineVertical);
		}
		

	}
	
}

void Grid::renderTiles(sf::RenderTarget* target)
{
	for (int i = 0; i < size ; i ++)
	{
		for (int j = 0; j < size; j ++)
		{
			tiles[i][j]->render(target);

		}	
	}
}



void Grid::render(sf::RenderTarget* target)
{
	
	renderTiles(target);
	renderLines(target);
	
}
