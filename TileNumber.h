#pragma once
#include "Tile.h"

class TileNumber : public Tile {
	
	
public :
	TileNumber(sf::Vector2f position, int size);
	~TileNumber();


	void render(sf::RenderTarget* target);
};