#include "Menu.hpp"

void GUI::Menu::addComponent(std::unique_ptr<GUI::Component> component) {
	m_components.push_back(std::move(component));
}

void GUI::Menu::clear() {
	m_components.clear();
	m_components.shrink_to_fit();
	m_offsetX = 0;
	m_offsetY = 0;
}

void GUI::Menu::setOffsetX(unsigned int x) {
	m_offsetX = x;
}

void GUI::Menu::setOffsetY(unsigned int y) {
	m_offsetY = y;
}

void GUI::Menu::draw(GameRenderer &renderer) {
	for (auto const &component: m_components) {
		component->draw(renderer);
	}
}

void GUI::Menu::onEvent(const sf::Event &event) {
	for (auto const &component: m_components) {
		component->onEvent(event);
	}
}
