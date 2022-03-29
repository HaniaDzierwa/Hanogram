#include "Tile.h"

Tile::Tile(sf::Vector2f position, sf::Color endStateColor)
{
	
	this->size = TileData::tileSize;
	this->position = position;
	this->endStateColor = endStateColor;
	//this->defaultColor = TileData::blankStateColor;

	this->shape.setSize(sf::Vector2f(size,size));
	this->shape.setPosition(position);
	this->shape.setFillColor(defaultColor);
	this->shape.setOutlineColor(blackColor);
	this->shape.setOutlineThickness(1.f);


}

Tile::~Tile()
{
}

void Tile::update(const sf::Vector2f mousePos)
{

	// update na odpowiedni color 
}

void Tile::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

