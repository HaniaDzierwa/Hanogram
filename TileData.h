#pragma once

#include <SFML/Graphics.hpp>

class TileData {
public:
	static const int sizeA = 15;
	static const int sizeB = 500;

	static const int tileSize = (sizeB/sizeA);
	static  const sf::Color blankStateColor;
	static const sf::Color fullStateColor;

	static enum tileState { blankState = 0, fullState, crossState, endState };

};