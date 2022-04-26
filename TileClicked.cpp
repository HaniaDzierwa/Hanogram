#pragma once

#include "TileClicked.h"
#include <iostream>
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
	case blankState:
	{
		this->shape.setFillColor(emptyColorTile);
		
		break;
	}
	case fullState:
	{
		this->shape.setFillColor(fullColorTile);
		break;
	}

	case hovered:
	{
		this->shape.setFillColor(hoverColorTile);
		break;
	}
	case crossState:
		
		this->setTexture(crossTexture);
		//this->setSprite(crossSprite);
		this->shape.setFillColor(emptyColorTile);
		break;

	default:
		this->shape.setFillColor(sf::Color::Blue);
		break;

	}

		

}



TileClicked::TileClicked(sf::Vector2f position, sf::Color endStateColor, int size, TextureManager * textureManager) : Tile(position, size)
{
	this->shape.setSize(sf::Vector2f(size, size));
	this->shape.setPosition(position);
	this->shape.setFillColor(emptyColorTile); 
	this->shape.setOutlineColor(outlineColor);
	this->shape.setOutlineThickness(thicknesEdge);
	this->endStateColor = endStateColor;
	this->emptyColorTile = sf::Color(255, 255, 255,255);

	this->fullColorTile = sf::Color(54, 54, 54);
	this->hoverColorTile = sf::Color(128, 128, 128);
	this->tileState = blankState;

	this->textureManager = textureManager;
	this->crossTexture = this->textureManager->getTexture("cross");
	

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
}