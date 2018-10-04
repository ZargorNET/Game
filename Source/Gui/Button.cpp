#include "Button.hpp"

void GUI::Button::onEvent(const sf::Event &event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Button::Left)
			onLeftClick();
		if (event.mouseButton.button == sf::Mouse::Button::Right)
			onRightClick();
	}
}

