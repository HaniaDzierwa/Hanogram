#include "MenuState.h"


bool MenuState::getGameStartButonIsPressed()
{
	return gameStartButton->isPressed();
}

bool MenuState::getSelectLevelButtonIsPressed()
{
	return selectLevelButton->isPressed();
}

bool MenuState::endGameState()
{
	return false;
}
int MenuState::updateLevel()
{
	
	if (getSelectLevelButtonIsPressed() and clock.getElapsedTime() > this->time)
	{
		showLevel->setText(it->first);
		showLevel->setTextPosition();
		toReturn = it->second;
		it++;
		clock.restart();

	}
		
	if (it == levelANDsize.end())
		{
			it = levelANDsize.begin();
		}
		
    return toReturn;
	
}



void MenuState::initLevel()
{
	levelANDsize["EASY"] = 10;
	levelANDsize["MEDIUM"] = 10;
	levelANDsize["HARD"] = 15;

	this->it = levelANDsize.begin();
	this->toReturn = levelANDsize.begin()->second;
}


void MenuState::initVariables()
{
	this->titleTexture = textureManager->getTexture("title");
	this->selectLevelButtonTexture = textureManager->getTexture("selectLevelButton");
}

void MenuState::initButtons()
{
	
	this->gameStartButton = new CircleButton(250, 600, 80, 0,
		&this->font, "START",
		sf::Color(177, 214, 242), sf::Color::White, sf::Color::Black);
	this->gameStartButton->getShape().setOutlineThickness(2.f);
	this->gameStartButton->getShape().setOutlineColor(sf::Color(15, 4, 135));


	this->selectLevelButton = new RectangleButton(650, 400, 100, 100, 90,
		&this->font, "",
		sf::Color::White, sf::Color(235, 194, 231), sf::Color(213, 131, 205));
	  this->selectLevelButton->setTexture(this->selectLevelButtonTexture);


	this->showLevel = new RectangleButton(250, 400, 300, 100, 0,
		&this->font, "EASY",
		sf::Color(183, 54, 170), sf::Color::Blue, sf::Color::White);


	this->level = new RectangleButton(250, 300, 300, 100, 0,
		&this->font, "POZIOM :",
		sf::Color::Transparent, sf::Color::Blue, sf::Color::White);

	
	this->title = new RectangleButton(50, 100, 700, 150, 0,
		&this->font, "",
		sf::Color::White, sf::Color::White, sf::Color::White);
	this->title->setTexture(this->titleTexture);

}

MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* states, TextureManager* textureManager, sf::Event& event) : State(window, states, textureManager), event(event)
{
	this->window = window;
	this->states = states;
	this->textureManager = textureManager;
	initVariables();
	initButtons();
	initLevel();
}


MenuState::~MenuState()
{
	delete this->gameStartButton;
	delete this->title;
	delete this->selectLevelButton;
	delete this->showLevel;
	delete this->level;
	
}

void MenuState::update()
{
	auto mousePosWindow = sf::Mouse::getPosition(*this->window);
	auto mousePosFloat = this->window->mapPixelToCoords(mousePosWindow);
	
	this->gameStartButton->update(mousePosFloat);
	this->selectLevelButton->update(mousePosFloat);

	this->gridSize = this->updateLevel();

	if (gameStartButton->isPressed())
	{
		states->push(new GameState(this->window, this->states, this->textureManager,this->gridSize));
	}

}

void  MenuState::render(sf::RenderTarget* target)
{
	this->showLevel->render(window);
	this->selectLevelButton->render(window);
	this->level->render(window);
	this->title->render(window);
	this->gameStartButton->render(window);
	
}



