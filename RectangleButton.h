#pragma once

#include "Button.h"

class RectangleButton : public Button
{

public:
	sf::RectangleShape shape;


	 sf::Texture texture;
	

	RectangleButton(float x, float y, float width, float height, float rotation, sf::Font* font, std::string text,
		sf::Color unactiveColor, sf::Color hoverColor, sf::Color activeColor);

	~RectangleButton();

	void setSprite(std::string name);
	void setTextPosition();
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
	

};