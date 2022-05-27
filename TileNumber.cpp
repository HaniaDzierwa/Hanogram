#include "TileNumber.h"

TileNumber::TileNumber(sf::Vector2f position,  int size, int number) : Tile (position,size)
{
	this->shape.setSize(sf::Vector2f(size, size));
	this->shape.setPosition(position);
	this->shape.setFillColor(sf::Color(215, 217, 197));
	this->shape.setOutlineColor(outlineColor);
	this->shape.setOutlineThickness(thicknesEdge);
	
	initFonts();
	initText();

	if(number==0) 
    this->text.setString(" ");
	else
	this->text.setString(std::to_string(number));

	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 1.f);
}

TileNumber::~TileNumber() {}

void TileNumber::initFonts()
{
	if (!this->font.loadFromFile("Fonts/JosefinSans-Bold.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::failed to load font!" << "\n";
	}
}

void TileNumber::initText()
{
	this->text.setFont(this->font);
	this->text.setCharacterSize(24);
	this->text.setFillColor(sf::Color::Black);
	this->text.setString("NULL");
}

void TileNumber::update(const sf::Vector2f mousePos, sf::Clock* clock, TileStateSelect tileStateSelect) {}

void TileNumber::render(sf::RenderTarget * target) // virtualna 
{
	target->draw(this->shape);
	target->draw(this->text);
}
