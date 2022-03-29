#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "State.h"
#include "GameManager.h"
#include "CircleButton.h"
#include "RectangleButton.h"
#include  "GameState.h"

//enum Level { Easy="esay", Medium, Hard };

class MenuState : public State
{
	CircleButton* gameStartbutton;
	RectangleButton * selectLevelbutton;
	RectangleButton* showLevel;
	RectangleButton* level;
	RectangleButton* title;

	

	//window
	int windowHeight;
	int windowWidth;
	sf::Vector2i windowPossition;
	sf::RenderWindow* window;
	bool mouseHeld;

	//states
	std::stack<State*>* states;


	//level
	std::map<std::string, int> levelANDsize;
	std::map<std::string, int>::iterator it;
	
	sf::Event event;
	
	bool endGameState();
	void updateLevel();

public:	
	
	
	MenuState(sf::RenderWindow* window, std::stack<State*>* states, sf::Event &event);
	~MenuState();

	bool getGameStartButonIsPressed();
	bool getSelectLevelButtonIsPressed();

	void update();
	void render(sf::RenderTarget* target);

	
	


};
