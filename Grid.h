#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <vector>
#include "Tile.h"

using namespace std;
class Grid
{
	vector<vector<Tile*>> tiles; 

	sf::Vector2f gridOffSet;
	int size;
	
	sf::RectangleShape coastlineHorizontal;
	sf::RectangleShape coastlineVertical;
	float thicknesCoastline;

	int boxSize;

	void initTiles();
	void initLines();
public: 
	Grid(int size , sf::RenderWindow* window);
	~Grid();

	//update
	
	void updateTiles(const sf::Vector2f mousePos);
	void update(const sf::Vector2f mousePos);

	//render
	void renderLines(sf::RenderTarget* target);
	void renderTiles(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);


};