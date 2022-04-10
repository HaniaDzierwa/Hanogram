#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


enum buttonState { unactive = 0, hover, active };

class Button
{
protected:

	short unsigned buttonState;
	
	sf::Font* font;
	sf::Text text;

	sf::Color unactiveColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	


public:

	Button(float x, float y, float rotation,
		sf::Font* font, std::string text,
		sf::Color unactiveColor, sf::Color hoverColor, sf::Color activeColor);

	virtual ~Button() = 0;

	const bool isPressed() const;
	void setText(std::string text);

	virtual void update(const sf::Vector2f mousePos) = 0;
	virtual  void render(sf::RenderTarget* target) = 0;
};




