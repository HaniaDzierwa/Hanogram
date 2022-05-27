#include "PopUpMistake.h"

PopUpMistake::PopUpMistake (sf::Font *font)
{
	this->font = *font;

	this->popUpMistakeWindow = new RectangleButton(150, 300, 500, 400, 0,
		&this->font,"" ,
		sf::Color(228, 242, 239), sf::Color::White, sf::Color::Green);
	
	this->messageBox= new RectangleButton(300, 300, 200, 100, 0,
		&this->font, "You have " + std::to_string(0) + " errors",
		sf::Color(228, 242, 239), sf::Color::White, sf::Color::Green);

	this->continueButton= new CircleButton(280, 400, 60, 0,
		&this->font, "CONTINUE",
		sf::Color(141, 195, 217), sf::Color::White, sf::Color::Green);

	this-> restartButton= new CircleButton(280, 550,  60, 0,
		&this->font, "RESTART",
		sf::Color(141, 195, 217), sf::Color::White, sf::Color::Green);
}

PopUpMistake::~PopUpMistake()
{
	delete this->popUpMistakeWindow;
	delete this->continueButton;
	delete this->messageBox;
	delete this->restartButton;
}

bool PopUpMistake::continueButtonClicked()
{
		return this->continueButton->isPressed();
}
bool PopUpMistake::restartButtonClicked()
{
	return this->restartButton->isPressed();
}


void PopUpMistake::setNumberOfMistakes(int amountOfMistake)
{
	messageBox->setText("You have " + std::to_string(amountOfMistake) + " errors" );
}

void PopUpMistake::update(sf::Vector2f mousePos)
{
	continueButton->update(mousePos);
	restartButton->update(mousePos);
}

void PopUpMistake::render(sf::RenderTarget* target)
{
	this->popUpMistakeWindow->render(target);
	this->messageBox->render(target);
	this->continueButton->render(target);
	this->restartButton->render(target);
}


