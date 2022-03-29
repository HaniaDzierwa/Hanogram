#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <stack>
#include "Button.h"
#include "State.h"
#include "GameState.h"
#include "MenuState.h"
#include"CircleButton.h"




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
	void initFonts();

	void pullEvents();
	

public:

	const bool running() const;
	const bool getEndGame() const;


	GameManager();
	~GameManager();

	bool mouseButtonReleased();

	void update();
	void render();



};