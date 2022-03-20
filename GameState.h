#pragma once
#include "State.h"


class GameState : public State
{

public:
	GameState()
	{

	}

	~GameState()
	{

	}

	void update()
	{
		this->text.setString("Game");
	}



	void render(sf::RenderTarget* target)
	{
		target->draw(this->text);
	}


};
