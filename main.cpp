
#include <iostream>
#include "GameManager.h"


int main ()
{
        GameManager gameManager;
        
      

        while (gameManager.running()) //&& !gameManager.getEndGame()) // while when true
        {
            
                
          // Update 
           gameManager.update();
         // Render 
           gameManager.render();

        }
        return 0;

}