#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include "TileData.h"



class Tile
{
	
	sf::Vector2f position;
	sf::RectangleShape shape;

	int size;
	 sf::Color defaultColor= sf::Color::White;
	 sf::Color blackColor = sf::Color::Black;


	//to bedzie X xd 
	/*sf::Vertex line[2] =
	{
		sf::Vertex(sf::Vector2f(10, 10)),
		sf::Vertex(sf::Vector2f(150, 150))
	};*/

	sf::Color endStateColor;



public:
	Tile(sf::Vector2f position,sf::Color endStateColor);
	~Tile();

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

};