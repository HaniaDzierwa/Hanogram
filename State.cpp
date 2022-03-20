#include "State.h"


void State::initFonts()
{
    if (!this->font.loadFromFile("Fonts/BubbleShine.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONTS::failed to load font!" << "\n";
    }

}

void State::initText()
{
    this->text.setFont(this->font);
    this->text.setCharacterSize(24);
    this->text.setFillColor(sf::Color::Blue);
    this->text.setString("NULL");


}

State::State()
{
    initFonts();
    initText();
}

State::~State()
{
}
