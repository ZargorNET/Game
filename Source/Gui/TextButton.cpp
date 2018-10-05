#include <utility>

#include "TextButton.hpp"

/*GUI::TextButton::TextButton(const RectangleShapeTest& shape) : Interactive(shape) {

}*/
void GUI::TextButton::draw(GameRenderer &renderer) {
	renderer.draw(std::make_unique<sf::RectangleShape>(m_shape));
}

void GUI::TextButton::onLeftClick() {
	std::cout << "LEFT\n";
}

void GUI::TextButton::onRightClick() {
	std::cout << "RIGHT\n";
}

void GUI::TextButton::onHover() {

}
