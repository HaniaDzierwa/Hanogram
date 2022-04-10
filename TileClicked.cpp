#pragma once

#include "TileClicked.h"

TileClicked::TileClicked(sf::Vector2f position, sf::Color endStateColor, int size) : Tile(position, size)
{
	this->shape.setSize(sf::Vector2f(size, size));
	this->shape.setPosition(position);
	this->shape.setFillColor(emptyColorTile); 
	this->shape.setOutlineColor(outlineColor);
	this->shape.setOutlineThickness(thicknesEdge);
	this->endStateColor = endStateColor;
	this->fullColorTile = sf::Color::Black;
}

TileClicked::~TileClicked()
{
}

void TileClicked::update(const sf::Vector2f mousePos)
{
}

void TileClicked::render(sf::RenderTarget* target) // virtualna 
{
	target->draw(this->shape);
}