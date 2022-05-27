#include "GameManager.h"

void GameManager::initVariables()
{
   this->textureManager = new TextureManager();
   textureManager->inicjalize();
   this->window = nullptr;
   this->endGame = false;
}
void GameManager::initWindow()
{
    this->videoMode.height = 1000;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Hanogram", sf::Style::Titlebar | sf::Style::Close); // widht and hight 
    this->window->setFramerateLimit(60);
    this->window->setKeyRepeatEnabled(false);
}



void GameManager::pullEvents()
{
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
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
    
    initVariables();
    initWindow();
    states.push(new MenuState(this->window, &states, this->textureManager, event, endGame));
    
    
   
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
     delete this->textureManager;
    
}

void GameManager::update()
{
   
   this->pullEvents();
   this->states.top()->update();

    if (this->states.top()->endGameState())
    {
        delete states.top();
        this->states.pop();
        if (states.empty())
        {
            this->endGame = true;
        }

    }
}


void GameManager::render()
{
    if (!endGame)
    {
        this->window->clear(sf::Color(215, 237, 209));
        this->states.top()->render(this->window);
        this->window->display();
    }
}
