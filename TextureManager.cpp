
#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager() {}

TextureManager::~TextureManager()
{
	// Delete all of the textures we used
	sf::Texture* texture;
	std::map<std::string, sf::Texture*>::iterator iter = textures.begin();
	while (iter != textures.end())
	{
		texture = iter->second;
		delete texture;
		iter++;
	}
}


void TextureManager::loadAllTextures( std::string pathToTextures)
{
	std::string nameTexture;
	for (auto const& dir_entry : std::filesystem::directory_iterator(pathToTextures))
	{
		if (dir_entry.exists())  
		{
			sf::Texture* texture = new sf::Texture();
			nameTexture = createTextureName((dir_entry.path().filename().generic_string()));
			texture->loadFromFile(dir_entry.path().generic_string());
			this->textures[nameTexture] = texture;
		}
		else
			std::cout << " Couldn't load textures\n";
	}
	std::cout << "Textures loaded\n";
}

std::string TextureManager::createTextureName(std::string fileName)   // usuwanie rozszerzenia pliku 
{
	char character = '.';
	auto trimToCharacter =
		std::views::reverse
		| std::views::drop_while([character](char& c)
			{ return c != character;

			})
		| std::views::reverse;

			auto newLine = fileName
				| trimToCharacter;

	return { newLine.begin() , newLine.end()-1 };
}


sf::Texture* TextureManager::getTexture(std::string name)
{
	if (this->textures.find(name) != this->textures.end()) {
		return this->textures[name];
	}
	else {
		std::cout << " Couldn't find texture" << name ;
		return NULL;
	}
}

void TextureManager::inicjalize()
{
	loadAllTextures("C:\\Users\\hania\\Desktop\\Hanogram2\\Hanogram2\\Hanogram2\\Textures");
}
