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
	return endGame;
}

pair<string,int> MenuState::updateLevel()
{
	
	if (getSelectLevelButtonIsPressed() and clock.getElapsedTime() > this->time)
	{
		showLevelTextBox->setText(it->first);
		showLevelTextBox->setTextPosition();
		toReturn = make_pair(it->first, it->second);
		it++;
		clock.restart();

	}
		
	if (it == levelANDsizeAll.end())
		{
			it = levelANDsizeAll.begin();
		}
		
    return toReturn;
	
}



void MenuState::initLevel()
{
	levelANDsizeAll["EASY"] = 10;
	levelANDsizeAll["MEDIUM"] = 10;
	levelANDsizeAll["HARD"] = 15;

	this->it = levelANDsizeAll.begin();
	this->toReturn = make_pair(levelANDsizeAll.begin()->first, levelANDsizeAll.begin()->second);
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


	this->showLevelTextBox = new RectangleButton(250, 400, 300, 100, 0,
		&this->font, "EASY",
		sf::Color(183, 54, 170), sf::Color::Blue, sf::Color::White);


	this->levelTextBox = new RectangleButton(250, 300, 300, 100, 0,
		&this->font, "POZIOM :",
		sf::Color::Transparent, sf::Color::Blue, sf::Color::White);

	
	this->titleTextBox = new RectangleButton(50, 100, 700, 150, 0,
		&this->font, "",
		sf::Color::White, sf::Color::White, sf::Color::White);
	this->titleTextBox->setTexture(this->titleTexture);

}

MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* states, TextureManager* textureManager, sf::Event& event, bool endGame) : State(window, states, textureManager), event(event), endGame(endGame)
{
	this->window = window;
	this->states = states;
	this->textureManager = textureManager;
	this->endGame = endGame;
	initVariables();
	initButtons();
	initLevel();
}


MenuState::~MenuState()
{
	//text boxes
	delete this->titleTextBox;
	delete this->showLevelTextBox;
	delete this->levelTextBox;

	//buttons
	delete this->gameStartButton;
	delete this->selectLevelButton;
}

void MenuState::update()
{
	auto mousePosWindow = sf::Mouse::getPosition(*this->window);
	auto mousePosFloat = this->window->mapPixelToCoords(mousePosWindow);
	
	this->gameStartButton->update(mousePosFloat);
	this->selectLevelButton->update(mousePosFloat);

	this->levelANDsize = this->updateLevel();

	if (gameStartButton->isPressed())
	{
		std::cout << "weszlismy\n";
		GameState* gameState = new GameState(this->window, this->states, this->textureManager, this->levelANDsize);
		if (!gameState->initialize())
		{
			delete gameState;
			return;
		}

		this->states->push(gameState);
		
	
	}

}

void  MenuState::render(sf::RenderTarget* target)
{
	//text boxes
	this->showLevelTextBox->render(window);
	this->levelTextBox->render(window);
	this->titleTextBox->render(window);

	//buttons
	this->gameStartButton->render(window);
	this->selectLevelButton->render(window);
}



