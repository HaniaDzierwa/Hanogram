#include "TileNumber.h"



TileNumber::TileNumber(sf::Vector2f position,  int size) : Tile (position,size)
{
	this->shape.setSize(sf::Vector2f(size, size));
	this->shape.setPosition(position);
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setOutlineColor(outlineColor);
	this->shape.setOutlineThickness(thicknesEdge);
}

TileNumber::~TileNumber()
{
}

void TileNumber::render(sf::RenderTarget* target) // virtualna 
{
	target->draw(this->shape);
}
