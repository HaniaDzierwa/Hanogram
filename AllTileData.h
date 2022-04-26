#pragma once

#include <SFML/Graphics.hpp>

class AllTileData {
public:
	

	static const int tileSize = (600);
	
	static const int thicknes = 1.f;
	static const int boxSize = 5; // size of the big blocks to make game easier ( squares 5x5 with boarder line)

	

};

static enum TileState { blankState = 0, hovered, fullState, crossState, endState};
static enum TileStateSelect {full =0, cross};