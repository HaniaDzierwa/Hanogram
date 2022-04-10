#pragma once

#include "Tile.h"

class TileClicked : public Tile
{
	sf::Color endStateColor;
	sf::Color fullColorTile;

	//to bedzie X xd 
/*sf::Vertex line[2] =
{
	sf::Vertex(sf::Vector2f(10, 10)),
	sf::Vertex(sf::Vector2f(150, 150))
};*/


public :
	TileClicked(sf::Vector2f position, sf::Color endStateColor, int size);
	~TileClicked();

    void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};