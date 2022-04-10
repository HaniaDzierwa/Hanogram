#pragma once


#include "State.h"
#include "GameState.h"
#include "CircleButton.h"
#include "RectangleButton.h"
#include <unordered_map>

//enum Level { Easy="esay", Medium, Hard };

class MenuState : public State
{
	CircleButton* gameStartbutton;
	RectangleButton * selectLevelbutton;
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

	int gridSize;
	
	bool endGameState();
	int updateLevel();

	void initButtons();
	void initLevel();

	//clock
	sf::Clock clock;
	sf::Time time = sf::seconds(0.3);
	

public:	
	
	
	MenuState(sf::RenderWindow* window, std::stack<State*>* states, sf::Event &event);
	~MenuState();

	bool getGameStartButonIsPressed();
	bool getSelectLevelButtonIsPressed();

	void update();
	void render(sf::RenderTarget* target);

	
	


};
