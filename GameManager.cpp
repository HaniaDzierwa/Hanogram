#include "GameManager.h"



void GameManager::initVariables()
{
    this->window = nullptr;


    states.push(new MenuState());

    this->gameStatebutton = new Button(300, 600, 250, 250,
        &this->font, "Start",
        sf::Color::Blue, sf::Color::White, sf::Color::Green);

}
void GameManager::initWindow()
{
    this->videoMode.height = 1000;
    this->videoMode.width = 800;

    this->window = new sf::RenderWindow(this->videoMode, "Hanogram", sf::Style::Titlebar | sf::Style::Close); // widht and hight 

    this->window->setFramerateLimit(60);

}

void GameManager::initFonts()
{
    if (!this->font.loadFromFile("Fonts/BubbleShine.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONTS::failed to load font!" << "\n";
    }

}

const bool GameManager::running() const
{
    return this->window->isOpen();
}

const bool GameManager::getEndGame() const
{
    return this->endGame;
}

GameManager::GameManager()
{
    initFonts();
    initVariables();
    initWindow();

}
GameManager::~GameManager()
{
    delete this->gameStatebutton;
    delete this->window;


}


void GameManager::update()
{
    // zob funkkcjde pool events
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }

     auto mousePosWindow = sf::Mouse::getPosition(*this->window);
     auto mousePosFloat  = this->window->mapPixelToCoords(mousePosWindow);

     if (gameStatebutton->isPressed())
     {
         states.push(new GameState());
     }

   // auto mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition());

    this->gameStatebutton->update(mousePosFloat);

    states.top()->update();
}


void GameManager::render()
{
    this->window->clear(sf::Color(179, 255, 172));

    states.top()->render(this->window);

    this->gameStatebutton->render(window);
    this->window->display();
}
