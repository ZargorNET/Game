#include "Component.hpp"
#include "../Application.hpp"


bool GUI::Component::isMouseOver(const sf::Shape &shape) const {
	auto &window = Application::getInstance().getGameWindow().getRaw();
	return shape.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
}
