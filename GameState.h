#pragma once

#include "GameManager.h"
#include "State.h"
#include "RectangleButton.h"
#include "CircleButton.h"
#include "Grid.h"

class GameState : public State
{
	

	RectangleButton* gameBackbutton;
	CircleButton* stateSelectButton;
	Grid *grid;

	sf::Texture* fullStateSprite;
	sf::Texture* crossStateSprite;

	
	bool endGameState();

	//states
	std::stack<State*>* states;

	sf::Event event;
	int size;

	TileStateSelect tileStateSelect;
	sf::Texture texture;
	sf::Texture texture1;

	
	void initButtons();

	void updateStateSelect();
public:

	GameState(sf::RenderWindow* window, std::stack<State*>* states, TextureManager* textureManager, int size);
	~GameState();
	
	void update();

	void render(sf::RenderTarget* target);
	


};
