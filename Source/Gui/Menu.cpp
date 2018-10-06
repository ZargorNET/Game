#include "Menu.hpp"

void GUI::Menu::addComponent(std::unique_ptr<GUI::Component> component) {
	m_components.push_back(std::move(component));
}

void GUI::Menu::clear() {
	m_components.clear();
	m_components.shrink_to_fit();
}

void GUI::Menu::draw(GameRenderer &renderer) {
	if (m_background)
		m_background->draw(renderer);
	for (auto const &component: m_components) {
		component->draw(renderer);
	}
}

void GUI::Menu::onEvent(const sf::Event &event) {
	for (auto const &component: m_components) {
		component->onEvent(event);
	}
}

void GUI::Menu::setBackground(const sf::Texture &text) {
	m_background = std::make_unique<GUI::Background>(std::move(sf::RectangleShape()), text);
}
