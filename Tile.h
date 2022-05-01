#pragma once
#include <SFML/Graphics.hpp>
#include "AllTileData.h"
#include <iostream>


class Tile
{

protected:
	
	sf::Vector2f position;
	sf::RectangleShape shape;
	int size;

	sf::Color emptyColorTile;

	bool endState;

	sf::Color outlineColor;
	float thicknesEdge;

	TileLoadData* tileLoadData;

	
public:
	Tile(sf::Vector2f position,int size);
	~Tile();

	virtual void render(sf::RenderTarget* target)= 0;
	virtual void update(const sf::Vector2f mousePos,sf::Clock *clock, TileStateSelect tileStateSelect) = 0;
	
};