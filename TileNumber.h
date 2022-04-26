#pragma once
#include "Tile.h"

class TileNumber : public Tile {
	
	int number;
	
public :
	TileNumber(sf::Vector2f position, int size, int number);
	~TileNumber();


	void render(sf::RenderTarget* target);
	void update(const sf::Vector2f mousePos,sf::Clock *clock, TileStateSelect tileStateSelect);
};