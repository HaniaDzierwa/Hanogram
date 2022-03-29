#include "MenuState.h"

bool MenuState::getGameStartButonIsPressed()
{
	return gameStartbutton->isPressed();
}

bool MenuState::getSelectLevelButtonIsPressed()
{
	return selectLevelbutton->isPressed();
}

bool MenuState::endGameState()
{
	return false;
}

void MenuState::updateLevel()
{
	if (this->mouseHeld == false)
	{
		this->mouseHeld = true;
		if (it == levelANDsize.end())
		{
			it = levelANDsize.begin();
		}


		if (getSelectLevelButtonIsPressed())
		{
			showLevel->setText(it->first);
			showLevel->setTextPosition();
			it++;


		}

	}
	else
		this->mouseHeld = false;

}



MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* states, sf::Event& event) : window(window), states(states), event(event)
{
	this->windowHeight = window->getSize().x;
	this->windowWidth = window->getSize().y;
	this->windowPossition = window->getPosition();


	this->gameStartbutton = new CircleButton(250, 600, 80,0,
		&this->font, "START",
		sf::Color(195,223,250) , sf::Color::White, sf::Color::Green);


	this->selectLevelbutton = new RectangleButton(650, 400, 100, 100,90,
		&this->font, "",
		sf::Color::White, sf::Color(235, 194, 231), sf::Color(213, 131, 205));
	this->selectLevelbutton->setSprite("strzalka.png");


	this->showLevel = new RectangleButton(250, 400, 300, 100, 0,
		&this->font, "EASY",
		sf::Color(183,54,170), sf::Color::Blue, sf::Color::White);


	this->level = new RectangleButton(250, 300, 300, 100, 0,
		&this->font, "POZIOM :",
		sf::Color::Transparent, sf::Color::Blue, sf::Color::White);
	
	this->title = new RectangleButton(50, 100, 700, 150, 0,
		&this->font, "",
		sf::Color::White, sf::Color::White, sf::Color::White);
	this->title->setSprite("tytul.png");
	

	levelANDsize["EASY"]= 10;
	levelANDsize["MEDIUM"] = 10;
	levelANDsize["HARD"] = 15;

	it = levelANDsize.begin();

    mouseHeld = false;


}


MenuState::~MenuState()
{

	// instal onother program to check memory leaks  //
	
	//delete this->window;
	
	delete this->gameStartbutton;
	//delete this->gameState;
	
	//check?

	//delete this->states->top();
	//delete (this->states);
	
}

void MenuState::update()
{

	this->text.setString("Menu");
	auto mousePosWindow = sf::Mouse::getPosition(*this->window);
	auto mousePosFloat = this->window->mapPixelToCoords(mousePosWindow);
	this->gameStartbutton->update(mousePosFloat);
	this->updateLevel();
	this->selectLevelbutton->update(mousePosFloat);
	


	if (gameStartbutton->isPressed())
	{
		states->push(new GameState(this->window, this->states, event));
	}
	

}

void  MenuState::render(sf::RenderTarget* target)
{
	this->showLevel->render(window);
	this->gameStartbutton->render(window);
	
	this->selectLevelbutton->render(window);
	this->level->render(window);
	this->title->render(window);

	target->draw(this->text);
}



