

#include <vld.h>
#include <iostream>
#include "GameManager.h"
#include <fstream>


int main ()
{
    {

        GameManager gameManager;

        while (gameManager.running())
        {

            // Update 
            gameManager.update();
            // Render 
            gameManager.render();

        }

    }
        
    return 0;


}