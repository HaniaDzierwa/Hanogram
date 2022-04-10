#include "Tile.h"

Tile::Tile(sf::Vector2f position, int size)
{
	this->size = size;
	this->position = position;
	this-> thicknesEdge = AllTileData::thicknes;
	this->emptyColorTile = sf::Color::White;
	this->outlineColor = sf::Color::Black;
}

Tile::~Tile()
{
}




