#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <map>
#include <fstream>
#include <filesystem>
#include <ranges>


class TextureManager
{
	std::map <std::string, sf::Texture*> textures;

public: 

	TextureManager();
	~TextureManager();

	void inicjalize();

	//get Texture by name 
	sf::Texture* getTexture(std::string name);

	std::string createName(std::string fileName);
	void loadAllTextures( std::string path);
	

	
};
