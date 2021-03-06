#pragma once

#include "Button.h"

class CircleButton : public Button
{

	sf::CircleShape shape;  

public :

	

	CircleButton(float x, float y, float radius, float rotation, sf::Font* font, std::string text,
		sf::Color unactiveColor, sf::Color hoverColor, sf::Color activeColor);
	
	~CircleButton();

	sf::CircleShape getShape();

	void setTexture(sf::Texture *texture);
	
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
	

};