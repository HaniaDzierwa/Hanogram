#pragma once

#include <vector>
#include <iostream>

#include "Tile.h"
#include "TileClickable.h"
#include "TileNumber.h"

#include "TextureManager.h"
#include "LevelLoader.h"
#include "GridValidator.h"
#include "RectangleButton.h"
#include "CircleButton.h"
#include "PopUpMistake.h"


using namespace std;

class Grid
{
	//tiles
	vector<vector<TileClickable*>> tilesClickable; 
	vector<vector<TileNumber*>> tilesWithNumberRow;
	vector<vector<TileNumber*>> tilesWithNumberColumns;



	sf::Vector2f gridOffSet;

	int tileSize;
	int maxNumbersInRowAndColumns;
	int size;   
	int tableSize;
	
	//lines 
	sf::RectangleShape coastlineHorizontal;
	sf::RectangleShape coastlineVertical;

	sf::RectangleShape coastlineHorizontalup;
	sf::RectangleShape coastlineVerticalSide;
	float thicknesCoastline;

	int boxSize;

	
	TextureManager* textureManager;
	GridValidator* gridValidator;

	//clock
	sf::Clock clock;
	sf::Time tileClickDelay = sf::seconds(0.3);


	std::vector<std::vector<TileLoadData*>>* tilesLoadData;
	
	int amountFullStatesNOW = 0;
	int amountFullStatesFINISH;

	int totalMistakes;

	RectangleButton* fullTileSquare;
	RectangleButton* amountTilesClickedandToClick;

	// select state 
	CircleButton* stateSelectButton;
	TileStateSelect tileStateSelect;

	//textures
	sf::Texture* fullStateSprite;
	sf::Texture* crossStateSprite;


	sf::Font font;
	bool end = false;

	bool showPopUp = false;
	bool wait = false; 

	PopUpMistake* popUpMistakeWindow;


	std::vector<std::vector<int>>* rowsNumbers;
	std::vector<std::vector<int>>* columnsNumbers;

	//init
	void initTiles();
	void initTilesWithNumber();
	void initTilesClickable();
	void initLines();
	void initUI();
	
	//update
	void updatePopUp(const sf::Vector2f mousePos);
	void updateStateSelect(const sf::Vector2f mousePos);
	void setTilesStatesToEndState(const sf::Vector2f mousePos);
	void updateTiles(const sf::Vector2f mousePos, TileStateSelect tileState);
	

	//render
	void renderLines(sf::RenderTarget* target);
	void renderTilesClicked(sf::RenderTarget* target);
	void renderTilesNumbers(sf::RenderTarget* target);
	void renderTilesClickedEND(sf::RenderTarget* target);


	int calculateMistakes();

public: 

	Grid(sf::RenderWindow* window, TextureManager* textureManager, pair<string, int> levelANDsize, sf::Font *font, std::vector<std::vector<TileLoadData*>>* tilesLoadData,
		int amountFullStatesFINISH, int maxAmountOfNumbersGeneral, std::vector<std::vector<int>>* columnsNumbers, std::vector<std::vector<int>>* rowsNumbers);
	~Grid();

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

	bool getEndGame();


};