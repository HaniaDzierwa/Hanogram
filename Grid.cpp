#include "Grid.h"

void Grid::initTilesWithNumber()
{
	// init rows 
	for (int i = maxNumbersInRowAndColumns * tileSize, n = 0; i < size * tileSize; i += tileSize)  // od 3 do rownej badz mniej niz 13     10 wartosc 
	{
		std::vector<TileNumber*> rowNRows;
		for (int j = 0, m = 0; j < maxNumbersInRowAndColumns * tileSize; j += tileSize)  // maxnumbers*tileSize  // od 0 do mniej niz 3 do 2 0,1,2
		{
			int number = 0;
			if (n < size - maxNumbersInRowAndColumns and m < maxNumbersInRowAndColumns)
				number = (*rowsNumbers)[n][m];

			rowNRows.push_back(new TileNumber(sf::Vector2f(j + gridOffSet.x, i + gridOffSet.y), tileSize, number));
			m++;
		}
		this->tilesWithNumberRow.push_back(rowNRows);
		n++;
	}

	// init columns
	for (int j = maxNumbersInRowAndColumns * tileSize, m = 0; j < size * tileSize; j += tileSize)  // maxnumbers*tileSize  // od 0 do mniej niz 3 do 2 0,1,2
	{
		std::vector<TileNumber*> rowNColumns;
		for (int i = 0, n = 0; i < maxNumbersInRowAndColumns * tileSize; i += tileSize)  // od 3 do rownej badz mniej niz 13     10 wartosc 
		{
			int number = 0;

			if (m < size - maxNumbersInRowAndColumns and n < maxNumbersInRowAndColumns)
				number = (*columnsNumbers)[m][n];

			rowNColumns.push_back(new TileNumber(sf::Vector2f(j + gridOffSet.x, i + gridOffSet.y), tileSize, number));
			n++;
		}
		this->tilesWithNumberColumns.push_back(rowNColumns);
		m++;
	}
}

void Grid::initTilesClickable()
{

	for (int i = maxNumbersInRowAndColumns * tileSize, n = 0; i < size * tileSize; i += tileSize)
	{
		std::vector<TileClickable*> rowC;
		for (int j = maxNumbersInRowAndColumns * tileSize, m = 0; j < size * tileSize; j += tileSize)
		{
			rowC.push_back(new TileClickable(sf::Vector2f(j + gridOffSet.x, i + gridOffSet.y), (*tilesLoadData)[n][m], tileSize, textureManager));
			m++;
		}
		this->tilesClickable.push_back(rowC);
		n++;
	}
}

void Grid::initTiles()
{
	this->initTilesClickable();
	this->initTilesWithNumber();
}

void Grid::initLines()
{

	this->thicknesCoastline = 5.f;
	this->coastlineHorizontal.setSize(sf::Vector2f(((float)this->size * tileSize), thicknesCoastline));
	this->coastlineHorizontal.setFillColor(sf::Color::Black);

	this->coastlineVertical.setSize(sf::Vector2f(((float)this->size * tileSize), thicknesCoastline));
	this->coastlineVertical.setFillColor(sf::Color::Black);

	this->coastlineHorizontalup.setSize(sf::Vector2f(((float)(this->size - maxNumbersInRowAndColumns) * tileSize), thicknesCoastline));
	this->coastlineHorizontalup.setFillColor(sf::Color::Black);

	this->coastlineVerticalSide.setSize(sf::Vector2f(((float)(this->size - maxNumbersInRowAndColumns) * tileSize), thicknesCoastline));
	this->coastlineVerticalSide.setFillColor(sf::Color::Black);
}

void Grid::initUI()
{
	this->fullTileSquare = new RectangleButton(300, 80, 40, 40, 0,
		&this->font, "",
		sf::Color(54, 54, 54), sf::Color::White, sf::Color::Green);

	this->amountTilesClickedandToClick = new RectangleButton(360, 75, 120, 50, 0,
		&this->font, "0/0",
		sf::Color::Transparent, sf::Color::White, sf::Color::Green);

	this->stateSelectButton = new CircleButton(250, 820, 70, 0,
		&this->font, "",
		sf::Color::White, sf::Color(180, 180, 180), sf::Color(100, 100, 100));
	this->stateSelectButton->setTexture(fullStateSprite);
}

Grid::Grid(sf::RenderWindow* window, TextureManager* textureManager, pair<string, int> levelANDsize, sf::Font* font, std::vector<std::vector<TileLoadData*>>* tilesLoadData,
	int amountFullStatesFINISH, int maxAmountOfNumbersGeneral, std::vector<std::vector<int>>* columnsNumbers, std::vector<std::vector<int>>* rowsNumbers)
{
	// textures
	this->textureManager = textureManager;
	this->fullStateSprite = textureManager->getTexture("fullState");
	this->crossStateSprite = textureManager->getTexture("crossState");

	// load file with informations about game
	this->tilesLoadData = tilesLoadData;
	this->columnsNumbers = columnsNumbers;
	this->rowsNumbers = rowsNumbers;
	this->maxNumbersInRowAndColumns = maxAmountOfNumbersGeneral;


	this->size = levelANDsize.second + maxNumbersInRowAndColumns;
	tileSize = AllTileData::tileSize / this->size;
	this->gridOffSet = sf::Vector2f((window->getSize().x - this->size * this->tileSize) / 2, (window->getSize().y - this->size * this->tileSize) / 2);

	this->tableSize = levelANDsize.second;
	this->boxSize = AllTileData::boxSize;

	this->gridValidator = new GridValidator(this->tilesLoadData, levelANDsize.second);

	this->amountFullStatesFINISH = amountFullStatesFINISH;
	this->font = *font;
	this->tileStateSelect = full;

	this->popUpMistakeWindow = new PopUpMistake(&this->font);

	initTiles();
	initLines();
	initUI();


}

bool Grid::getEndGame()
{
	return this->end;
}

Grid::~Grid()
{
	// destructor tileClicked
	for (int i = 0; i < tilesClickable.size(); i++)
	{
		for (int j = 0; j < tilesClickable[i].size(); j++)
		{
			delete this->tilesClickable[i][j];
		}
	}
	// desctructor tileNumberRow
	for (int i = 0; i < tilesWithNumberRow.size(); i++)
	{
		for (int j = 0; j < tilesWithNumberRow[i].size(); j++)
		{
			delete this->tilesWithNumberRow[i][j];
		}

	}
	// desctructor tileNumberColumns
	for (int i = 0; i < tilesWithNumberColumns.size(); i++)
	{
		for (int j = 0; j < tilesWithNumberColumns[i].size(); j++)
		{
			delete this->tilesWithNumberColumns[i][j];
		}

	}

	delete this->gridValidator;
	delete this->amountTilesClickedandToClick;
	delete this->fullTileSquare;
	delete this->stateSelectButton;

	delete this->popUpMistakeWindow;
}

void Grid::updateStateSelect(const sf::Vector2f mousePos)
{

	if (stateSelectButton->isPressed() and clock.getElapsedTime() > tileClickDelay)
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
			this->tileStateSelect = cross;
		}

	}
}

void Grid::updateTiles(const sf::Vector2f mousePos, TileStateSelect tileStateSelect)
{
	this->amountFullStatesNOW = 0;

	for (int i = 0; i < tilesClickable.size(); i++)
	{
		for (int j = 0; j < tilesClickable[i].size(); j++)
		{
			this->tilesClickable[i][j]->update(mousePos, &(this->clock), tileStateSelect);

			if (this->tilesClickable[i][j]->getTileState() == fullState)
			{
				this->amountFullStatesNOW++;
			}
		}
	}

}
void Grid::updatePopUp(const sf::Vector2f mousePos)
{
	this->popUpMistakeWindow->update(mousePos);

	if (this->popUpMistakeWindow->restartButtonClicked() and clock.getElapsedTime() > tileClickDelay)
	{
		clock.restart();

		for (int i = 0; i < tilesClickable.size(); i++)
		{
			for (int j = 0; j < tilesClickable[i].size(); j++)
			{
				delete this->tilesClickable[i][j];
			}
		}
		tilesClickable.clear();

		initTiles();
		this->amountFullStatesNOW = 0;
		this->showPopUp = false;
		return;
	}

	if (this->popUpMistakeWindow->continueButtonClicked() and clock.getElapsedTime() > tileClickDelay)
	{
		clock.restart();
		this->showPopUp = false;
		this->wait = true;
		return;
	}

	if (!this->popUpMistakeWindow->continueButtonClicked() and !this->popUpMistakeWindow->restartButtonClicked() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->showPopUp = true;
		return;
	}

}

int Grid::calculateMistakes()
{
	int arraySizeForThreadOne = this->tableSize / 2;
	int arraySizeForThreadSecond = this->tableSize - arraySizeForThreadOne;
	std::promise<int> amountOfMistakesFromThreadOne, amountOfMistakesFromThreadSecond;

	std::thread threadOne(&GridValidator::searchForMistakes, gridValidator, &this->tilesClickable,
		0, (arraySizeForThreadOne), ref(amountOfMistakesFromThreadOne));
	std::thread threadTwo(&GridValidator::searchForMistakes, gridValidator, &this->tilesClickable,
		(arraySizeForThreadSecond), (this->tableSize), ref(amountOfMistakesFromThreadSecond));

	this->totalMistakes =
		amountOfMistakesFromThreadOne.get_future().get() +
		amountOfMistakesFromThreadSecond.get_future().get();

	threadOne.join();
	threadTwo.join();

	return this->totalMistakes;
}


void Grid::setTilesStatesToEndState(const sf::Vector2f mousePos)
{
	for (int i = 0; i < tilesClickable.size(); i++)
	{
		for (int j = 0; j < tilesClickable[i].size(); j++)
		{
			this->tilesClickable[i][j]->setTileState(endState);
			this->tilesClickable[i][j]->setColorBasedOnTileState();

		}
	}


}



void Grid::update(const sf::Vector2f mousePos)
{
	if (wait and amountFullStatesNOW < amountFullStatesFINISH) {
		wait = false;
	}

	if (amountFullStatesNOW == amountFullStatesFINISH and !end) {
		if (calculateMistakes() == 0) {
			this->end = true;
			this->setTilesStatesToEndState(mousePos);
		}
		else {
			this->popUpMistakeWindow->setNumberOfMistakes(this->totalMistakes);
		}
	}

	if (this->showPopUp) {
		this->updatePopUp(mousePos);
		return;
	}


	if (!end) {
		updateTiles(mousePos, this->tileStateSelect);
	}

	if (amountFullStatesNOW < amountFullStatesFINISH) {
		this->showPopUp = false;
	}
	if (amountFullStatesNOW == amountFullStatesFINISH and !wait) {
		this->showPopUp = true;
	}

	std::string text;
	text = to_string(amountFullStatesNOW) + " /" + to_string(amountFullStatesFINISH);
	this->amountTilesClickedandToClick->setText(text);
	this->stateSelectButton->update(mousePos);
	this->updateStateSelect(mousePos);
}
void Grid::renderLines(sf::RenderTarget* target)
{
	this->coastlineHorizontalup.setPosition(sf::Vector2f(gridOffSet.x + maxNumbersInRowAndColumns * tileSize, gridOffSet.y));
	target->draw(this->coastlineHorizontalup);

	this->coastlineVerticalSide.setPosition(sf::Vector2f(gridOffSet.x, gridOffSet.y + maxNumbersInRowAndColumns * tileSize));
	this->coastlineVerticalSide.setRotation(90);
	target->draw(this->coastlineVerticalSide);

	for (int i = maxNumbersInRowAndColumns * tileSize; i < ((this->size + 1) * this->tileSize); i += this->tileSize)
	{
		if ((i - (maxNumbersInRowAndColumns * tileSize)) % (this->boxSize * this->tileSize) == 0)
		{
			this->coastlineHorizontal.setPosition(sf::Vector2f(gridOffSet.x, i + gridOffSet.y));
			target->draw(this->coastlineHorizontal);

			this->coastlineVertical.setPosition(sf::Vector2f(i + gridOffSet.x, gridOffSet.y));
			this->coastlineVertical.setRotation(90);
			target->draw(this->coastlineVertical);
		}
	}
}


void Grid::renderTilesClicked(sf::RenderTarget* target)
{
	for (int i = 0; i < this->size - maxNumbersInRowAndColumns; i++) {
		for (int j = 0; j < this->size - maxNumbersInRowAndColumns; j++) {
			tilesClickable[i][j]->render(target);
		}
	}
}
void Grid::renderTilesClickedEND(sf::RenderTarget* target)
{
	for (int i = 0; i < this->size - this->maxNumbersInRowAndColumns; i++) {
		for (int j = 0; j < this->size - this->maxNumbersInRowAndColumns; j++) {
			tilesClickable[i][j]->setPosition(sf::Vector2f(j * tileSize + (gridOffSet.x + ((maxNumbersInRowAndColumns * tileSize) / 2)),
				i * tileSize + (gridOffSet.y + ((maxNumbersInRowAndColumns * tileSize) / 2))));
			tilesClickable[i][j]->render(target);
		}
	}
}

void Grid::renderTilesNumbers(sf::RenderTarget* target)
{
	// row 
	for (int i = 0; i < size - maxNumbersInRowAndColumns; i++)
	{
		for (int j = 0; j < maxNumbersInRowAndColumns; j++)
		{
			tilesWithNumberRow[i][j]->render(target);
		}
	}

	//column
	for (int i = 0; i < size - maxNumbersInRowAndColumns; i++)
	{
		for (int j = 0; j < maxNumbersInRowAndColumns; j++)
		{
			tilesWithNumberColumns[i][j]->render(target);
		}
	}
}


void Grid::render(sf::RenderTarget* target)
{
	if (end)
	{
		renderTilesClickedEND(target);
		return;
	}

	renderTilesNumbers(target);
	renderTilesClicked(target);
	renderLines(target);

	this->fullTileSquare->render(target);
	this->amountTilesClickedandToClick->render(target);
	this->stateSelectButton->render(target);
	if (this->showPopUp)
	{
		this->popUpMistakeWindow->render(target);
	}

}

