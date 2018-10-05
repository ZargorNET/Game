#include "Interactive.hpp"

void GUI::Interactive::onEvent(const sf::Event &event) {
	if (Component::isMouseOver(m_shape)) {
		onHover();
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Button::Left)
				onLeftClick();
			if (event.mouseButton.button == sf::Mouse::Button::Right)
				onRightClick();
		}
	}
}

