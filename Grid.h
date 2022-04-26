#pragma once

#include <vector>
#include "Tile.h"
#include "TileClicked.h"
#include "TileNumber.h"
#include <iostream>
#include "TextureManager.h"

using namespace std;

class Grid
{
	vector<vector<Tile*>> tilesClicked; 
	vector<vector<Tile*>> tilesNumber;

	sf::Vector2f gridOffSet;
	int size;

	int tileSize;
	int maxNumbers; // max amount of numbers to fill np 1 2 4 3  to bedzie ilosc 4 
	
	sf::RectangleShape coastlineHorizontal;
	sf::RectangleShape coastlineVertical;

	sf::RectangleShape coastlineHorizontalup;
	sf::RectangleShape coastlineVerticalSide;
	float thicknesCoastline;

	int boxSize;

	void initTiles();
	void initLines();

	TextureManager* textureManager;

	//clock
	sf::Clock clock;
	
	

public: 

	Grid(int size,sf::RenderWindow* window, TextureManager*textureManager);
	~Grid();

	//update
	
	void updateTiles(const sf::Vector2f mousePos, TileStateSelect tileState);
	void update(const sf::Vector2f mousePos, TileStateSelect tileState);

	//render
	void renderLines(sf::RenderTarget* target);
	void renderTilesClicked(sf::RenderTarget* target);
	void renderTilesNumbers(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);


};