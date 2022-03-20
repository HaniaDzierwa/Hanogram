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




class GameManager
{


	sf::RenderWindow* window;   // this is a poniter, cause we want to delete this anytime
	sf::VideoMode videoMode;
	sf::Event event;

	Button* gameStatebutton;

	sf::Font font;
	bool endGame;

	sf::Vector2i mousePos;


	std::stack<State*>states;

	void initVariables();
	void initWindow();
	void initFonts();

public:

	const bool running() const;
	const bool getEndGame() const;
	GameManager();
	~GameManager();




	void update();
	void render();



};