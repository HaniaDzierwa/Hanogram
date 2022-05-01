#include "GameState.h"

bool GameState::endGameState()
{
	return this->gameBackbutton->isPressed();
}

void GameState::initButtons()
{

	this->gameBackbutton = new RectangleButton(550, 50, 200, 100, 0,
		&this->font, "BACK",
		sf::Color(177, 196, 242), sf::Color::White, sf::Color::Green);

	this->stateSelectButton = new CircleButton(250, 820, 70, 0,
		&this->font, "",
		sf::Color::White, sf::Color(180, 180, 180), sf::Color(100, 100, 100));
	this->stateSelectButton->setTexture(fullStateSprite);
}

void GameState::updateStateSelect()
{

	 if (stateSelectButton->isPressed() and clock.getElapsedTime() > time)
	 {
		 clock.restart();

		 if (this->tileStateSelect == cross)
		 {
			this->stateSelectButton->setTexture(fullStateSprite);
			 this->tileStateSelect = full;
		 }
		 else
		 {
			this->stateSelectButton->setTexture(crossStateSprite);
			 this-> tileStateSelect = cross;
		 }

	 }
}

sf::Vector2f GameState::updateMousePos()
{
	auto mousePosWindow = sf::Mouse::getPosition(*this->window);
	auto mousePosFloat = this->window->mapPixelToCoords(mousePosWindow);

	return mousePosFloat;

}

void GameState::updateButtons(sf::Vector2f mousePosFloat)
{
	this->stateSelectButton->update(mousePosFloat);
	this->gameBackbutton->update(mousePosFloat);


	if (gameBackbutton->isPressed())
	{
		State* toDelete = this->states->top();
		this->states->pop();
		delete toDelete;
	}
}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, TextureManager *textureManager, std::pair<std::string,int> levelANDsize) : State(window, states,textureManager), levelANDsize(levelANDsize)
{
	this->states = states;
	this->textureManager = textureManager;

	this->fullStateSprite = textureManager->getTexture("fullState");
	this->crossStateSprite = textureManager->getTexture("crossState");

	initButtons();

	this->levelANDsize = levelANDsize;
	this->tileStateSelect = full;
	this->grid = new Grid( window, textureManager, levelANDsize,&font);


}
GameState::~GameState()
{
	delete this->stateSelectButton;
	delete this->gameBackbutton;
	delete this->grid;
	
}

void GameState::update()
{
	auto mousePosFloat = updateMousePos();
	this->grid->update(mousePosFloat,tileStateSelect);
	this->updateStateSelect();
	this->text.setString("Game");
	this->updateButtons(mousePosFloat);

}

void GameState::render(sf::RenderTarget* target)
{
	this->grid->render(window);
	this->stateSelectButton->render(window);
	this->gameBackbutton->render(window);
	
	
}
