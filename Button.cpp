#include "Button.h"


Button::Button(float x, float y,  float rotation, sf::Font* font, std::string text,
	sf::Color unactiveColor, sf::Color hoverColor, sf::Color activeColor)
{

	this->buttonState = unactive;
	
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::Black);

	this->text.setCharacterSize(40);
	
	this->unactiveColor = unactiveColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

}


 Button::~Button()
{
}

const bool Button::isPressed() const
{

	if (this->buttonState == active) 
	{
		return true;
	}
	return false;
}

void Button::setText(std::string text)
{
	this->text.setString(text);
}




