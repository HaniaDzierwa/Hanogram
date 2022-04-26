#pragma once

#include "Button.h"

class RectangleButton : public Button
{
	sf::RectangleShape shape;

public:
	
	RectangleButton(float x, float y, float width, float height, float rotation, sf::Font* font, std::string text,
		sf::Color unactiveColor, sf::Color hoverColor, sf::Color activeColor);

	sf::RectangleShape getShape();
	~RectangleButton();

	void setTexture(sf::Texture *texture);

	void setTextPosition();
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
	

};