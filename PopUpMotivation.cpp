#include "PopUpMotivation.h"

void  PopUpMotivation::updateAnimation()
{
	this->ifTransparencyWasZero
		? this->transparency += stepTransparency
		: this->transparency -= stepTransparency;

	if (this->transparency > maxTransparency-stepTransparency)
		this->ifTransparencyWasZero = false;
	if (this->transparency == minTransparency)
		this->ifTransparencyWasZero = true;


	if (this->transparency > maxTransparency - stepTransparency)
	{
		this->wasMaxTransparency = true;
		timeWhenMaxTransparency = clock.getElapsedTime();
	}

	sf::Color newColor = sf::Color( this->color.r, this->color.g, this->color.b, this->transparency);
	sf::Color newOutlineColor = sf::Color(this->outlineColor.r, this->outlineColor.g, this->outlineColor.b, this->transparency);
	

	text.setFillColor(newColor);
	text.setOutlineColor(newOutlineColor);
	
}

PopUpMotivation::PopUpMotivation(float x, float y, sf::Font* font, std::string message, sf::Color color)
{
	this->color = color;
	this->outlineColor= sf::Color(sf::Color::Black);

	this->text.setPosition(sf::Vector2f(x, y));
	this->text.setString(message);
	this->text.setCharacterSize(32);
	this->text.setOutlineColor(outlineColor);
	this->text.setOutlineThickness(1.0f);
	this->text.setFillColor(color);
	this->text.setFont(*font);
	
	this->transparency = 0; 
	this->timeDelay= sf::seconds(2);   //should be bigger 
	this->end = false;
}

PopUpMotivation::~PopUpMotivation()
{

}

bool PopUpMotivation::ifPopUpMotivationEnd()
{
	return this->end;
}

void PopUpMotivation::setPopUpMotivationEnd(bool state)
{
	this->end = state;
}

void PopUpMotivation::update()
{
	if (this->end)
		return;
	
	if (this->wasMaxTransparency)
		if (clock.getElapsedTime() > timeWhenMaxTransparency + timeDelay)
		{
			this->wasMaxTransparency = false;
			this->updateAnimation();
		}

	if (!this->wasMaxTransparency)
	     this->updateAnimation();

	if (this->transparency == minTransparency)
	{
		this->end = true;
		this->ifTransparencyWasZero = true;
	}
}

void PopUpMotivation::render(sf::RenderTarget* target)
{
	target->draw(this->text);
}
