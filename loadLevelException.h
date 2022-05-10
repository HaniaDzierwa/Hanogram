#pragma once
#include <iostream>
#include <exception>


struct loadLevelExcpetion : public std::exception
{

    const char* what() const override
    {
        return "Couldn't load Game \n";
    }




};