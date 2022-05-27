#include "GameState.h"
#include "invalidRGBvalueExceptionsh.h"
#include <future>

bool GameState::endGameState()
{
	return this->gameBackbutton->isPressed();
}

void GameState::initButtons()
{

	this->gameBackbutton = new RectangleButton(550, 50, 200, 100, 0,
		&this->font, "BACK",
		sf::Color(177, 196, 242), sf::Color::White, sf::Color::Green);

}



sf::Vector2f GameState::updateMousePos()
{
	auto mousePosWindow = sf::Mouse::getPosition(*this->window);
	auto mousePosFloat = this->window->mapPixelToCoords(mousePosWindow);

	return mousePosFloat;

}

void GameState::updateButtons(sf::Vector2f mousePosFloat)
{
	
	this->gameBackbutton->update(mousePosFloat);


	if (gameBackbutton->isPressed())
	{
		State* toDelete = this->states->top();
		this->states->pop();
		delete toDelete;
	}
}

void GameState::initPopUpMotivationQuits()
{

	PopUpMotivation* popUpMotivation =  new PopUpMotivation(50, 80, &font, "Keep going!", sf::Color(176, 93, 136));
	this->popUpMotivationsQuots.push_back(popUpMotivation);
	popUpMotivation = new PopUpMotivation(60, 80, &font, "Excelent!", sf::Color(176, 93, 136));
	this->popUpMotivationsQuots.push_back(popUpMotivation);
	popUpMotivation = new PopUpMotivation(50, 80, &font, "You're great!", sf::Color(176, 93, 136));
	this->popUpMotivationsQuots.push_back(popUpMotivation);
	popUpMotivation = new PopUpMotivation(50, 80, &font, "Don't stress!", sf::Color(176, 93, 136));
	this->popUpMotivationsQuots.push_back(popUpMotivation);

}

 void GameState::renderPopUpMotivationBox(sf::RenderTarget* target)
{
	 if (this->motivationalPopUpCloak.getElapsedTime() < this->motivationalPopUpInterval) //  opoznienie startu 
		 return;

	if (!this->motivationalPopUpRenderingFlag)
	{
		this->motivationalPopUpRenderingFlag = true;
		this->motivationalPopUpRenderStartTime = this->motivationalPopUpCloak.getElapsedTime();
	}

	
	this->popUpMotivationsQuots[popUpMotivationCounter]->update();
	this->popUpMotivationsQuots[popUpMotivationCounter]->render(target);
	
	
	if ((this->motivationalPopUpCloak.getElapsedTime() >= this->motivationalPopUpRenderStartTime)
		and this->popUpMotivationsQuots[popUpMotivationCounter]->ifPopUpMotivationEnd())
	{
		this->motivationalPopUpRenderingFlag = false;
		this->motivationalPopUpCloak.restart();

		this->motivationalPopUpRenderEndTime = this->motivationalPopUpCloak.getElapsedTime();
		this->popUpMotivationCounter++;


		if (this->popUpMotivationCounter == this->popUpMotivationsQuots.size())
			this->popUpMotivationCounter = 0;

		this->popUpMotivationsQuots[this->popUpMotivationCounter]->setPopUpMotivationEnd(false);
	}

}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, TextureManager* textureManager, std::pair<std::string, int> levelANDsize) : State(window, states, textureManager), levelANDsize(levelANDsize)
{
	this->states = states;
	this->textureManager = textureManager;

	initButtons();

	this->levelANDsize = levelANDsize;
	this->levelLoader = new LevelLoader();

	this->initPopUpMotivationQuits();
}


GameState::~GameState()
{
	delete this->gameBackbutton;
	delete this->grid;
	delete this->levelLoader;

	for (int i = 0; i < this->popUpMotivationsQuots.size(); i++)
	{
		delete this->popUpMotivationsQuots[i];
	}
	popUpMotivationsQuots.clear();
}

bool GameState::initialize()
{
	try 
	{
		this->levelLoader->load(levelANDsize.first);
	}
	catch(invalidRGBvalueExcepions e)
	{
		std::cerr << e.what();
		return false;
	}


	this->tilesLoadData = levelLoader->getTilesLoadData();
	this->amountFullStatesFINISH = levelLoader->getAmountFullStates();
	this->maxAmountOfNumbersGeneral = levelLoader->getMaxAmountOfNumberGeneral();
	this->columnsNumbers = levelLoader->getColumnsNumbers();
	this->rowsNumbers = levelLoader->getRowsNumbers();

	this->grid = new Grid(window, textureManager, levelANDsize, &font, tilesLoadData, 
		amountFullStatesFINISH, maxAmountOfNumbersGeneral, columnsNumbers,rowsNumbers);
	return true;
}

void GameState::update()
{
	auto mousePosFloat = updateMousePos();
	this->grid->update(mousePosFloat);
	this->updateButtons(mousePosFloat);
}

void GameState::render(sf::RenderTarget* target)
{
	this->grid->render(target);
	this->gameBackbutton->render(target);

	if(!this->popUpMotivationsQuots[popUpMotivationCounter]->ifPopUpMotivationEnd() and  grid->getEndGame()==false)
	this->renderPopUpMotivationBox(target);
	
}
