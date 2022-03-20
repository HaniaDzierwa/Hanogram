#pragma once
#include "State.h"


class MenuState : public State
{



public:
	MenuState()
	{

	}

	~MenuState()
	{

	}

	void update()
	{
		
		this->text.setString("Menu");
	}
	


	void render(sf::RenderTarget* target)
	{
		target->draw(this->text);
	}


};
