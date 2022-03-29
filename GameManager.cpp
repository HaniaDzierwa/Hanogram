#include "GameManager.h"

void GameManager::initVariables()
{
    this->window = nullptr;
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
    // nic nie robi 
    if (!this->font.loadFromFile("Fonts/Walkway_UltraBold.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONTS::failed to load font!" << "\n";
    }
}

void GameManager::pullEvents()
{
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

bool GameManager::mouseButtonReleased()
{
    if (this->event.type == sf::Event::MouseButtonReleased)
        if (event.mouseButton.button == sf::Mouse::Left)
            return true;


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

    states.push(new MenuState(this->window, &states, event));
}
GameManager::~GameManager()
{
   

    for (int i = 0; i < this->states.size(); i++)
    {
        State* toDelete = this->states.top();
        this->states.pop();
        delete toDelete;
    }

     delete this->window;
   
    
}

void GameManager::update()
{
   
    this->pullEvents();
   this->states.top()->update();

    if (this->states.top()->endGameState())
    {
        delete states.top();
        this->states.pop();
    }


    
}


void GameManager::render()
{
    this->window->clear(sf::Color(215, 237, 209));
   this->states.top()->render(this->window);
    this->window->display();
}
