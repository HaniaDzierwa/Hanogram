#pragma once

#include "GameManager.h"
#include "State.h"
#include "RectangleButton.h"
#include "CircleButton.h"
#include "Grid.h"


class GameState : public State
{
	//buttons
	RectangleButton* gameBackbutton;
	CircleButton* stateSelectButton;

	Grid* grid;
	std::pair<std::string, int> levelANDsize;
	
	//textures
	sf::Texture* fullStateSprite;
	sf::Texture* crossStateSprite;

	
	bool endGameState();

	//states
	std::stack<State*>* states;

	sf::Event event;
	

	TileStateSelect tileStateSelect;
	
	
	void initButtons();
	void updateStateSelect();
	sf::Vector2f updateMousePos();
	void updateButtons(sf::Vector2f mousePosFloat);
public:

	GameState(sf::RenderWindow* window, std::stack<State*>* states, TextureManager* textureManager,pair<string,int> levelANDsize);
	~GameState();
	
	void update();

	void render(sf::RenderTarget* target);
	


};
