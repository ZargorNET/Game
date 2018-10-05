#include <utility>

#ifndef GAME_RESOURCEMANAGER_HPP
#define GAME_RESOURCEMANAGER_HPP

#include <utility>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourceHolder.hpp"

class ResourceManager {
private:
	ResourceHolder<sf::Font> m_fonts;
	ResourceHolder<sf::Texture> m_textures;
	ResourceHolder<sf::SoundBuffer> m_sounds;
	/*	ResourceHolder<sf::Font> m_fonts = ResourceHolder<sf::Font>("Res/", ".ttf", false);
	ResourceHolder<sf::Texture> m_textures = ResourceHolder<sf::Texture>("Res/", ".png");
	ResourceHolder<sf::SoundBuffer> m_sounds = ResourceHolder<sf::SoundBuffer>("Res/", ".ogg", false);*/
public:
	ResourceManager(ResourceHolder<sf::Font> &&fontHolder, ResourceHolder<sf::Texture> &&textureHolder,
	                ResourceHolder<sf::SoundBuffer> &&soundHolder) : m_fonts(std::move(fontHolder)),
	                                                                 m_textures(std::move(textureHolder)),
	                                                                 m_sounds(std::move(soundHolder)) {}

	const sf::Font &getFont(const std::string &name);

	const sf::Texture &getTexture(const std::string &name);

	const sf::SoundBuffer &getSound(const std::string &name);

};


#endif //GAME_RESOURCEMANAGER_HPP
