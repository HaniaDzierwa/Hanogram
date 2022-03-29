#include "GameState.h"

bool GameState::endGameState()
{
	return this->gameBackbutton->isPressed();
}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, sf::Event& event) : window(window), states(states), event(event)
{
	this->gameBackbutton = new RectangleButton(600, 50, 100, 70,0,
		&this->font, "BACK",
		sf::Color::Blue, sf::Color::White, sf::Color::Green);

	this->windowHeight = window->getSize().x;
	this->windowWidth = window->getSize().y;
	this->windowPossition = window->getPosition();

	this->grid = new Grid(15, window);
	

}
GameState::~GameState()
{
	
	//delete this->window;
	delete this->gameBackbutton;
	// check?
	//delete this->states->top();
	//delete this->states;

	
}

void GameState::update()
{
	this->text.setString("Game");


	auto mousePosWindow = sf::Mouse::getPosition(*this->window);
	auto mousePosFloat = this->window->mapPixelToCoords(mousePosWindow);
	this->gameBackbutton->update(mousePosFloat);


	if (gameBackbutton->isPressed())
	{
		State* toDelete = this->states->top();
		this->states->pop();
		delete toDelete; 
		//this->states->pop();
	}

}



void GameState::render(sf::RenderTarget* target)
{

	this->gameBackbutton->render(window);
	this->grid->render(window);
	target->draw(this->text);
}
