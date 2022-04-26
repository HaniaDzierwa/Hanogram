#pragma once

#include "Tile.h"
#include "TextureManager.h"

class TileClicked : public Tile
{
	//colors
	sf::Color endStateColor;
	sf::Color fullColorTile;
	sf::Color hoverColorTile;

	//textures
	TextureManager* textureManager;
	sf::Texture* crossTexture;


	TileState tileState;
	
	sf::Time timeDelay = sf::seconds(0.1);
	
	
	void updateTileState(const sf::Vector2f mousePos,sf::Clock *clock, TileStateSelect tileStateSelect);
	void updateFullStateClicked(sf::Vector2f mousePos, sf::Clock* clock);
	void updateCrossStateClicked(sf::Vector2f mousePos, sf::Clock* clock);
	void updateHoverState(const sf::Vector2f mousePos);

	

public :
	TileClicked(sf::Vector2f position, sf::Color endStateColor, int size, TextureManager *textureManager);
	~TileClicked();

	void setTexture(sf::Texture *texture);

    void update(const sf::Vector2f mousePos, sf::Clock *clock, TileStateSelect tileStateSelect);
	void render(sf::RenderTarget* target);
};