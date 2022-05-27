#pragma once

#include "GameManager.h"
#include "State.h"
#include "RectangleButton.h"
#include "CircleButton.h"
#include "Grid.h"
#include "PopUpMotivation.h"
#include <chrono>


class GameState : public State
{
	//buttons
	RectangleButton* gameBackbutton;
	
	//grid 
	Grid* grid;
	std::pair<std::string, int> levelANDsize;
	
	
	// level
	LevelLoader* levelLoader;
	std::vector<std::vector<TileLoadData*>>* tilesLoadData;
	int amountFullStatesFINISH;
	int maxAmountOfNumbersGeneral;
	std::vector<std::vector<int>>* rowsNumbers;
	std::vector<std::vector<int>>* columnsNumbers;


	bool endGameState();

	//states
	std::stack<State*>* states;

	sf::Event event;

	//motivation quots
	std::vector<PopUpMotivation*> popUpMotivationsQuots; 
	bool motivationalPopUpRenderingFlag = false;
	sf::Time motivationalPopUpRenderStartTime;
	sf::Time motivationalPopUpRenderEndTime;
	sf::Clock motivationalPopUpCloak;
	sf::Time motivationalPopUpInterval = sf::seconds(2);  //it should be bigger 

	int popUpMotivationCounter = 0;
	

	void initPopUpMotivationQuits();
	void initButtons();
	sf::Vector2f updateMousePos();
	void updateButtons(sf::Vector2f mousePosFloat);

	void renderPopUpMotivationBox(sf::RenderTarget* target);

public:

	GameState(sf::RenderWindow* window, std::stack<State*>* states, TextureManager* textureManager,pair<string,int> levelANDsize);
	~GameState();
	
	bool initialize();
	void update();
	void render(sf::RenderTarget* target);
	


};
