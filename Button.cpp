#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color unactiveColor, sf::Color hoverColor, sf::Color activeColor)
{

	this->buttonState = unactive;
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setRadius(50);
	this->shape.setScale(2, 1);


	//this->shape.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(40);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->unactiveColor = unactiveColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;


	this->shape.setFillColor(this->unactiveColor);



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

void Button::update(const sf::Vector2f mousePos)
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

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
