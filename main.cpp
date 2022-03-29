// enable memleak detection
//#if defined(_DEBUG) && defined(WINDOWS)
//int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
//tmpFlag |= _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF;  // Check heap alloc and dump mem leaks at exit
//_CrtSetDbgFlag(tmpFlag);
//assert(!errno);
//_crtBreakAlloc = 101;
//#endif


#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "GameManager.h"


#include <cstdlib>
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

int main ()
{
    
    {

        GameManager gameManager;



        while (gameManager.running()) //&& !gameManager.getEndGame()) // while when true
        {


            // Update 
            gameManager.update();
            // Render 
            gameManager.render();

        }






        std::cout << "-------------------------------------------------";
       /* _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
        _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
        _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
        _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
        _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
        _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);*/
    }

    std::cout << std::endl;
    std::cout << "Wyciek pamieci: ";
    std::cout << _CrtDumpMemoryLeaks();
        
    return 0;


}