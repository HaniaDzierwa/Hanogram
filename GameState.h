#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "GameManager.h"
#include "State.h"
#include "RectangleButton.h"
#include "Grid.h"


class GameState : public State
{
	

	RectangleButton* gameBackbutton;
	int windowHeight;
	int windowWidth;
	sf::Vector2i windowPossition;
	sf::RenderWindow* window;

	Grid *grid;

	bool endGameState();

	//states
	std::stack<State*>* states;

	sf::Event event;

public:

	GameState(sf::RenderWindow* window, std::stack<State*>* states, sf::Event& event);
	~GameState();
	
	void update();

	void render(sf::RenderTarget* target);
	


};
