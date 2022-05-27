#pragma once
#include "RectangleButton.h"
#include "CircleButton.h"

#include <iostream>

class PopUpMistake
{
	RectangleButton* popUpMistakeWindow;
	RectangleButton* messageBox;
	
	CircleButton* continueButton;
	CircleButton* restartButton;
	
	sf::Font font;



	

public:

	PopUpMistake(sf::Font *font);
	~PopUpMistake();

	bool continueButtonClicked();
	bool restartButtonClicked();

	void setNumberOfMistakes(int mistake);

	void update(sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

};