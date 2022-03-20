#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <stack>
#include <iostream>

#include "Button.h"


class State {

protected:

	sf::Text text;
	sf::Font font;

public:
	void initFonts();
	void initText();

	State();
	~State();
	virtual void update() = 0;
	virtual void render(sf::RenderTarget* target) = 0;


};
