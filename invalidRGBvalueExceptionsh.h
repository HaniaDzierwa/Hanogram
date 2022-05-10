#pragma once
#include <iostream>
#include <exception>
#include <string>
class invalidRGBvalueExcepions : public std::exception
{
    int line; 
    int value;
    std::string message;
public:

    invalidRGBvalueExcepions(std::string fileName,int position, int value)
    {
        this->line = line;
        this->value = value;
        this->message = "invalid RGB value in file " + fileName
            + " at positon: " + std::to_string(position)
            + " value was: " + std::to_string(value) + "\n";
    }


    const char* what() const override
    {

        return  this->message.c_str();
    }

    
   

};