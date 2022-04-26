#pragma once


#include "State.h"
#include "GameState.h"
#include "CircleButton.h"
#include "RectangleButton.h"
#include <unordered_map>

//enum Level { Easy="esay", Medium, Hard };

class MenuState : public State
{
	CircleButton* gameStartButton;
	RectangleButton * selectLevelButton;
	RectangleButton* showLevel;
	RectangleButton* level;
	RectangleButton* title;

	//states
	std::stack<State*>* states;


	//level
	std::unordered_map<std::string, int> levelANDsize; 
	std::unordered_map<std::string, int>::iterator it;
	int toReturn;
	
	sf::Event event;

	sf::Texture* titleTexture;
	sf::Texture* selectLevelButtonTexture;

	int gridSize;
	
	bool endGameState();
	int updateLevel();

	void initVariables();
	void initButtons();
	void initLevel();
	

	
	

public:	
	
	
	MenuState(sf::RenderWindow* window, std::stack<State*>* states, TextureManager *textureManager, sf::Event &event);
	~MenuState();

	bool getGameStartButonIsPressed();
	bool getSelectLevelButtonIsPressed();

	void update();
	void render(sf::RenderTarget* target);

	
	


};
