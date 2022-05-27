#pragma once
#include "RectangleButton.h"
#include <thread>
#include <chrono>
#include <future>

class PopUpMotivation
{
	sf::Text text;
	int transparency;
	int maxTransparency = 255;
	int minTransparency = 0;
	int stepTransparency = 4;
	bool wasMaxTransparency = false; 

	sf::Color color;
	sf::Color outlineColor;

	bool end = false;

	void updateAnimation();

	bool ifTransparencyWasZero = true;
	sf::Clock clock;
	sf::Time timeDelay;
	sf::Time timeWhenMaxTransparency;
public:

	PopUpMotivation(float x, float y, sf::Font* font, std::string message, sf::Color color);
	~PopUpMotivation();

	bool ifPopUpMotivationEnd();
	void setPopUpMotivationEnd(bool state);
	void update();
	void render(sf::RenderTarget* target);
};