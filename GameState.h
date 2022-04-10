#pragma once

#include "GameManager.h"
#include "State.h"
#include "RectangleButton.h"
#include "Grid.h"


class GameState : public State
{
	

	RectangleButton* gameBackbutton;
	Grid *grid;

	bool endGameState();

	//states
	std::stack<State*>* states;

	sf::Event event;
	int size;

public:

	GameState(sf::RenderWindow* window, std::stack<State*>* states, int size);
	~GameState();
	
	void update();

	void render(sf::RenderTarget* target);
	


};
