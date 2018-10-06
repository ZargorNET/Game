#include "MainMenu.hpp"

void State::MainMenu::onOpen() {

}

void State::MainMenu::onClose() {
	m_menu.clear();
}

void State::MainMenu::onTick(int dt) {

}

void State::MainMenu::onEvent(const sf::Event &e) {
	m_menu.onEvent(e);
}

void State::MainMenu::draw(GameRenderer &renderer) {
	m_menu.draw(renderer);
}
