#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <stack>
#include <iostream>
#include "TextureManager.h"

class State {

protected:

	sf::Text text;
	sf::Font font;

	
	sf::RenderWindow* window;
	std::stack<State*>* states;
	
	//clock
	sf::Clock clock;
	sf::Time time = sf::seconds(0.3);

	//textures
	TextureManager* textureManager;

	void initFonts();
	void initText();

public: 
	
	State(sf::RenderWindow *window ,std::stack<State*>* states, TextureManager *textureManager);
	virtual ~State() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderTarget* target) = 0;


	virtual bool endGameState() = 0;


};
