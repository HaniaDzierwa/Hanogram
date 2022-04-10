#include "GameState.h"

bool GameState::endGameState()
{
	return this->gameBackbutton->isPressed();
}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, int size) : State(window, states), size(size)
{
	this->window = window;
	this->states = states;
	this->gameBackbutton = new RectangleButton(550, 50, 200, 100, 0,
		&this->font, "BACK",
		sf::Color(177, 196, 242), sf::Color::White, sf::Color::Green);

	
	this->grid = new Grid(size, window);


}
GameState::~GameState()
{
	
	delete this->gameBackbutton;
	delete this->grid;
	
	
}

void GameState::update()
{
	// tutaj bedzie text box do wpisanie maial aby obrazek sie tam przeslal , email sprawdzany regexem czy poprawny
	/*while (window->pollEvent(event)) 
	{
		if (event.type == sf::Event::KeyPressed) {
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 128) {
					input += static_cast<char>(event.text.unicode);
					output.setFillColor(Color::White);
					output.setString(input);
				}
			}
		}
	}*/

	
	this->text.setString("Game");


	auto mousePosWindow = sf::Mouse::getPosition(*this->window);
	auto mousePosFloat = this->window->mapPixelToCoords(mousePosWindow);
	this->gameBackbutton->update(mousePosFloat);


	if (gameBackbutton->isPressed())
	{
		State* toDelete = this->states->top();
		this->states->pop();
		delete toDelete; 

	}

}



void GameState::render(sf::RenderTarget* target)
{

	this->gameBackbutton->render(window);
	this->grid->render(window);
	
}
