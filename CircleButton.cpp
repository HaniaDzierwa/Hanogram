#include "CircleButton.h"
#include "State.h"

CircleButton::CircleButton(float x, float y, float radius, float rotation,sf::Font* font, std::string text, sf::Color unactiveColor, sf::Color hoverColor, sf::Color activeColor)
	: Button(x, y, rotation, font, text, unactiveColor, hoverColor, activeColor)
{
	this->shape.setPosition(x, y);
	this->shape.setRadius(radius);
	this->shape.setScale(2, 1);

	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 1.f),
		this->shape.setFillColor(this->unactiveColor);

	this->shape.setFillColor(this->unactiveColor);
	this->shape.rotate(rotation);
}

CircleButton::~CircleButton()
{

}


void CircleButton::update(const sf::Vector2f mousePos)
{
	this->buttonState = unactive;
	//hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = hover;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = active;
		}

	}


	switch (this->buttonState)
	{
	case unactive:
		this->shape.setFillColor(this->unactiveColor);
		break;
	case hover:
		this->shape.setFillColor(this->hoverColor);
		break;
	case active:
		this->shape.setFillColor(this->activeColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;

	}
}

void CircleButton::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}





