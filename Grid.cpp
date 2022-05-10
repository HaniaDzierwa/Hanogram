#include "Grid.h"



void Grid::initTiles()
{
	
	for (int i = maxNumbers*tileSize, n=0; i < size * tileSize; i +=tileSize)
	{
		std::vector<TileClicked*> rowC;
		for (int j = maxNumbers*tileSize, m=0; j < size * tileSize; j += tileSize)
		{
			rowC.push_back(new TileClicked(sf::Vector2f(j+gridOffSet.x, i+gridOffSet.y), (*tilesLoadData)[n][m],tileSize, textureManager));
			m++;
		}
		this->tilesClicked.push_back(rowC);
		n++;
	}

	for (int i = 0; i < size * tileSize; i += tileSize)
	{
		std::vector<TileNumber*> rowN;
		for (int j = 0; j < size * tileSize; j += tileSize)
		{
			{
				rowN.push_back(new TileNumber(sf::Vector2f(j + gridOffSet.x, i + gridOffSet.y), tileSize, 6));
			}
			
		}
		this->tilesNumber.push_back(rowN);

	}

	
}

void Grid::initLines()
{
	
	this->thicknesCoastline = 5.f;
	this->coastlineHorizontal.setSize(sf::Vector2f(((float)this->size * tileSize), thicknesCoastline));
	this->coastlineHorizontal.setFillColor(sf::Color::Black);

	this->coastlineVertical.setSize(sf::Vector2f(((float)this->size * tileSize), thicknesCoastline));
	this->coastlineVertical.setFillColor(sf::Color::Black);

 this->coastlineHorizontalup.setSize(sf::Vector2f(((float)(this->size-maxNumbers) * tileSize), thicknesCoastline));
 this->coastlineHorizontalup.setFillColor(sf::Color::Black);

 this->coastlineVerticalSide.setSize(sf::Vector2f(((float)(this->size-maxNumbers) * tileSize), thicknesCoastline));
 this->coastlineVerticalSide.setFillColor(sf::Color::Black);
}

Grid::Grid( sf::RenderWindow* window, TextureManager *textureManager, pair<string,int> levelANDsize, sf::Font* font, std::vector<std::vector<TileLoadData*>>* tilesLoadData, int amountFullStatesFINISH)
{
	this->textureManager = textureManager;
	
	this->tilesLoadData = tilesLoadData;
	
	// load file with informations about game

	this->maxNumbers = 4; // read from file
	this->size = levelANDsize.second +maxNumbers;
	tileSize = AllTileData::tileSize / this->size;
	this->gridOffSet = sf::Vector2f((window->getSize().x-this->size*this->tileSize)/2 , (window->getSize().y - this->size *this->tileSize)/ 2 );
	
	this->boxSize = AllTileData::boxSize; 

	this->gridValidator = new GridValidator(this->tilesLoadData, levelANDsize.second);
	
	this->amountFullStatesFINISH = amountFullStatesFINISH;
	this->font = *font;

	initTiles();
	initLines();

	this-> fullTileSquare = new RectangleButton(300, 80, 40, 40, 0,
		&this->font, "",
		sf::Color(54, 54, 54), sf::Color::White, sf::Color::Green);

	this->amountTilesClickedandToClick = new RectangleButton(360, 75, 120, 50, 0,
		&this->font, "0/0",
		sf::Color::Transparent, sf::Color::White, sf::Color::Green);
	
}

Grid::~Grid()
{
	// destructor tileClicked
	for (int i = 0; i < tilesClicked.size(); i++)
	{
		for (int j = 0; j < tilesClicked[i].size(); j++)
		{
			delete this->tilesClicked[i][j];
		}
	}
	// desctructor tileNumber
	for (int i = 0; i < tilesNumber.size(); i++)
	{
		for (int j = 0; j < tilesNumber[i].size(); j++)
		{
			delete this->tilesNumber[i][j];
		}

	}



	delete this->gridValidator;
	
	delete this->amountTilesClickedandToClick;
	delete this->fullTileSquare;
	
	

}

void Grid::updateTiles(const sf::Vector2f mousePos, TileStateSelect tileStateSelect)
{
	if (this->amountFullStatesNOW == this->amountFullStatesFINISH)
	{
		mistakes = this->gridValidator->searchForMistakes(&this->tilesClicked);  // int ilosc bledow, =0 to dobrze i koniec gry , !=0 wyswietl komunikat 	, narazie wyswietla w ciagu komunikaty
		if (mistakes == 0)
		{
			end = true;
			std::cout << "dobrze";

			for (int i = 0; i < tilesClicked.size(); i++)
			{
				for (int j = 0; j < tilesClicked[i].size(); j++)
				{
					this->tilesClicked[i][j]->setTileState(endState); 

				}
			}

			
		}

		else
			std::cout << "zle";
	}

	
	// count amount of fullStates

	this->amountFullStatesNOW = 0;
    for (int i = 0; i < tilesClicked.size(); i++)
	{
		for (int j = 0; j < tilesClicked[i].size(); j++)
		{
			this->tilesClicked[i][j]->update(mousePos,&(this->clock), tileStateSelect);

			if (this->tilesClicked[i][j]->getTileState() == fullState)
			{
				//wyswietl na ekran update textbox
				this->amountFullStatesNOW++;
			}
		}
	}

	
	
	
}
void Grid::update(const sf::Vector2f mousePos, TileStateSelect tileStateSelect)
{
	if (!end)
	{
		updateTiles(mousePos, tileStateSelect);
	}
		std::string text;
		text = to_string(amountFullStatesNOW) + " /" + to_string(amountFullStatesFINISH);
		this->amountTilesClickedandToClick->setText(text);
	
}
void Grid::renderLines(sf::RenderTarget* target)
{
	this->coastlineHorizontalup.setPosition(sf::Vector2f(gridOffSet.x +maxNumbers*tileSize,  gridOffSet.y));
	target->draw(this->coastlineHorizontalup);

	this->coastlineVerticalSide.setPosition(sf::Vector2f( gridOffSet.x, gridOffSet.y + maxNumbers * tileSize));
	this->coastlineVerticalSide.setRotation(90);
	target->draw(this->coastlineVerticalSide);

	for (int i = maxNumbers*tileSize ; i< ((this->size+1) * this->tileSize); i += this->tileSize)
	{
		
		if ((i - (maxNumbers * tileSize)) % (this->boxSize* this->tileSize ) == 0 )   
		{
			this->coastlineHorizontal.setPosition(sf::Vector2f(gridOffSet.x , i+gridOffSet.y));
			target->draw(this->coastlineHorizontal);
			
			this->coastlineVertical.setPosition(sf::Vector2f(i+gridOffSet.x, gridOffSet.y));
			this->coastlineVertical.setRotation(90);
			target->draw(this->coastlineVertical);
		}
		

	}
	
}

void Grid::renderTilesClicked(sf::RenderTarget* target)
{
	for (int i =0 ; i < this->size - maxNumbers ; i ++)
	{
		for (int j =0 ; j < this->size- maxNumbers; j ++)
		{
				tilesClicked[i][j]->render(target);
		}	
	}


	
}
void Grid::renderTilesNumbers(sf::RenderTarget* target)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (!(i >= 0 and i < maxNumbers and j >= 0 and j < maxNumbers))
			tilesNumber[i][j]->render(target);
		}
	}
}


void Grid::render(sf::RenderTarget* target)
{
	renderTilesNumbers(target);
	renderTilesClicked(target);
	renderLines(target);
	
	this->fullTileSquare->render(target);
	this->amountTilesClickedandToClick->render(target);
}
