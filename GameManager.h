#pragma once

#include <iostream>
#include <stack>
#include "MenuState.h"





class GameManager
{

	//window
	sf::RenderWindow* window;   // this is a poniter, cause we want to delete this anytime
	sf::VideoMode videoMode;
	sf::Event event;


	//font
	sf::Font font;

	//if endGame
	bool endGame;

	sf::Vector2i mousePos;
    
	// Game states
	std::stack<State*>states;

	//inits
	void initVariables();
	void initWindow();
	

	void pullEvents();
	

public:

	const bool running() const;
	const bool getEndGame() const;


	GameManager();
	~GameManager();

	void update();
	void render();



};