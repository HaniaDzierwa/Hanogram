#pragma once
#include <SFML/Graphics.hpp>
#include "AllTileData.h"

class Tile
{

protected:
	
	sf::Vector2f position;
	sf::RectangleShape shape;
	int size;

	sf::Color emptyColorTile;
	sf::Color outlineColor;
	float thicknesEdge;

	
public:
	Tile(sf::Vector2f position,int size);
	~Tile();

	virtual void render(sf::RenderTarget* target)= 0 ;
	
};