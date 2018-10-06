#include <utility>

#include "Interactive.hpp"

void GUI::Interactive::onEvent(const sf::Event &event) {
	if (Component::isMouseOver(getShape())) {
		m_onHover();
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Button::Left)
				m_onLeftClick();
			if (event.mouseButton.button == sf::Mouse::Button::Right)
				m_onRightClick();
		}
	}
}

void GUI::Interactive::setLeftClickCallback(std::function<void()> func) {
	m_onLeftClick = std::move(func);
}

void GUI::Interactive::setRightClickCallback(std::function<void()> func) {
	m_onRightClick = std::move(func);
}

void GUI::Interactive::setHoverCallback(std::function<void()> func) {
	m_onHover = std::move(func);
}

