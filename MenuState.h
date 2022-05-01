#pragma once


#include "State.h"
#include "GameState.h"
#include "CircleButton.h"
#include "RectangleButton.h"
#include <unordered_map>

class MenuState : public State
{
	//buttons
	CircleButton* gameStartButton;
	RectangleButton * selectLevelButton;
	RectangleButton* showLevelTextBox;
	RectangleButton* levelTextBox;
	RectangleButton* titleTextBox;

	//states
	std::stack<State*>* states;


	//level
	std::unordered_map<std::string, int> levelANDsizeAll; 
	std::unordered_map<std::string, int>::iterator it;

	std::pair<std::string, int> toReturn;
	
	sf::Event event;

	//textures
	sf::Texture* titleTexture;
	sf::Texture* selectLevelButtonTexture;

	std::pair<std::string, int> levelANDsize;


	//inits
	void initVariables();
	void initButtons();
	void initLevel();
	
	bool endGameState();
	std::pair<std::string, int> updateLevel();
	

public:	
	
	MenuState(sf::RenderWindow* window, std::stack<State*>* states, TextureManager *textureManager, sf::Event &event);
	~MenuState();

	bool getGameStartButonIsPressed();
	bool getSelectLevelButtonIsPressed();

	void update();
	void render(sf::RenderTarget* target);

};
