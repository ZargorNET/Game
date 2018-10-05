#include "ResourceManager.hpp"

const sf::Font &ResourceManager::getFont(const std::string &name) {
	return m_fonts.get(name);
}

const sf::Texture &ResourceManager::getTexture(const std::string &name) {
	return m_textures.get(name);
}

const sf::SoundBuffer &ResourceManager::getSound(const std::string &name) {
	return m_sounds.get(name);
}
