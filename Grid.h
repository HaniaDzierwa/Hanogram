#pragma once

#include <vector>
#include <iostream>

#include "Tile.h"
#include "TileClicked.h"
#include "TileNumber.h"

#include "TextureManager.h"
#include "LevelLoader.h"
#include "GridValidator.h"
#include "RectangleButton.h"

using namespace std;

class Grid
{
	vector<vector<TileClicked*>> tilesClicked; 
	vector<vector<TileNumber*>> tilesNumber;

	sf::Vector2f gridOffSet;

	int tileSize;
	int maxNumbers; // max amount of numbers to fill np 
	int size;   //1 2 4 3  to bedzie ilosc 4 
	
	sf::RectangleShape coastlineHorizontal;
	sf::RectangleShape coastlineVertical;

	sf::RectangleShape coastlineHorizontalup;
	sf::RectangleShape coastlineVerticalSide;
	float thicknesCoastline;

	int boxSize;

	void initTiles();
	void initLines();

	TextureManager* textureManager;
	
	GridValidator* gridValidator;

	//clock
	sf::Clock clock;
	
	std::vector<std::vector<TileLoadData*>>* tilesLoadData;
	
	int amountFullStatesNOW = 0;
	int amountFullStatesFINISH;

	int mistakes;

	RectangleButton* fullTileSquare;
	RectangleButton* amountTilesClickedandToClick;

	sf::Font font;

	bool end = false;

public: 

	Grid(sf::RenderWindow* window, TextureManager* textureManager, pair<string, int> levelANDsize, sf::Font *font, std::vector<std::vector<TileLoadData*>>* tilesLoadData,int amountFullStatesFINISH);
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