#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
//#include <Thor/Config.hpp>

enum buttonState { unactive = 0, hover, active };

class Button
{
private:

	short unsigned buttonState;

	sf::CircleShape shape;
	sf::Font* font;
	sf::Text text;


	sf::Color unactiveColor;
	sf::Color hoverColor;
	sf::Color activeColor;



public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text,
		sf::Color unactiveColor, sf::Color hoverColor, sf::Color activeColor);

	~Button();


	const bool isPressed() const;

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);


	//sf::Shape RoundedRectangle(float x, float y, float rectWidth, float rectHeight, float radius, const sf::Color& Col, float Outline, const sf::Color& OutlineCol)
	//{
	//	sf::Shape rrect;    // creating a Shape - automatic storage class
	//	rrect.SetOutlineWidth(Outline);
	//	
	//		return rrect;
	//}

	//thor


};




