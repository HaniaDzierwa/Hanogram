#pragma once

#include "TileClicked.h"

void TileClicked::updateFullStateClicked(const sf::Vector2f mousePos, sf::Clock *clock)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and this->shape.getGlobalBounds().contains(mousePos) and this->tileState != crossState)
	{
		clock->restart();

		if (this->tileState != fullState)
			this->tileState = fullState;
		else
			this->tileState = blankState;
	}
}

void TileClicked::updateCrossStateClicked(sf::Vector2f mousePos, sf::Clock* clock)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and this->shape.getGlobalBounds().contains(mousePos) and this->tileState != fullState)
	{
		clock->restart();

		if (this->tileState != crossState)
			this->tileState = crossState;
		else
		{
			this->tileState = blankState;
		}
	}
}
	
void TileClicked::updateHoverState(const sf::Vector2f mousePos)
{
	if (this->tileState == hovered)
		this->tileState = blankState;

	if (this->shape.getGlobalBounds().contains(mousePos) and this->tileState != crossState and this->tileState != fullState)
		this->tileState = hovered;
}

TileState TileClicked::getTileState()
{
	return this->tileState;
}

void TileClicked::setTileState(TileState tileState)
{
	this->tileState = tileState;
}

void TileClicked::setTexture(sf::Texture * texture)
{
	this->shape.setTexture(texture, false);
}

void TileClicked::updateTileState(const sf::Vector2f mousePos, sf::Clock *clock, TileStateSelect tileStateSelect)
{
	this->updateHoverState(mousePos);


	if (clock->getElapsedTime() > this->timeDelay)
	{
		if (tileStateSelect == full)
		this->updateFullStateClicked(mousePos,clock);
		else 
		this->updateCrossStateClicked(mousePos,clock);
	}

	switch (this->tileState)
	{
	case TileState::blankState:
	{
		this->shape.setFillColor(emptyColorTile);
		break;
	}
	case TileState::fullState:
	{
		this->shape.setFillColor(fullColorTile);
		break;
	}
	case TileState::hovered:
	{
		this->shape.setFillColor(hoverColorTile);
		break;
	}
	case TileState::crossState:
	{
		//this->setTexture(crossTexture);
		this->shape.setFillColor(emptyColorTile);


		//this->sprite.setTextureRect(shape.getTextureRect());

		//this->sprite.setColor(emptyColorTile);

		//this->shape.setFillColor(colorUnderCross);
		break;
	}
	case TileState::endState:
	{
		this->shape.setFillColor(endStateColor);
		break;

	}
	default:
	{
		this->shape.setFillColor(sf::Color::Blue);
		break;
	}

	}

}



TileClicked::TileClicked(sf::Vector2f position, TileLoadData *tileLoadData, int size, TextureManager * textureManager) : Tile(position, size)
{
	//color
	this->endStateColor = tileLoadData->color;
	this->emptyColorTile = sf::Color(255, 255, 255);
	this->fullColorTile = sf::Color(54, 54, 54);
	this->hoverColorTile = sf::Color(128, 128, 128);
	this->colorUnderCross = sf::Color(255, 255, 255,0);

	//shape
	this->shape.setSize(sf::Vector2f(size, size));
	this->shape.setPosition(position);
	this->shape.setFillColor(emptyColorTile); 
	this->shape.setOutlineColor(outlineColor);
	this->shape.setOutlineThickness(thicknesEdge);
	
	
	//textures
	this->textureManager = textureManager;
	this->crossTexture = this->textureManager->getTexture("cross");


	//sprite for crossState
	
	this->sprite.setTexture(*crossTexture);
	this->sprite.setPosition(position);
	this->sprite.setScale(sf::Vector2f(size/100.f ,size/100.f));
	
	
	//states
	if (tileLoadData->crossState)
		this->tileState = crossState;
	else
	   this->tileState = blankState;

	this->endState = tileLoadData->endState;

}

TileClicked::~TileClicked()
{
	
}




void TileClicked::update(const sf::Vector2f mousePos, sf::Clock *clock, TileStateSelect tileStateSelect)
{
	
	this->updateTileState(mousePos,clock,tileStateSelect);
	
}

void TileClicked::render(sf::RenderTarget* target) 
{
	 target->draw(this->shape);

	 if( tileState== crossState)
	 target->draw(this->sprite);

	 if (tileState == endState)
	 {
		 //wait to visual better :))
	 }
}