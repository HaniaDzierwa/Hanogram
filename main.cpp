#include <vld.h>
#include "GameManager.h"

int main ()
{
    {
        GameManager gameManager;
        while (gameManager.running() and !gameManager.getEndGame())
        {
            // Update 
            gameManager.update();
            // Render 
            gameManager.render();
        }
    }
    return 0;
}