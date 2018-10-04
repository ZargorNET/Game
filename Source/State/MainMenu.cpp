#include "MainMenu.hpp"

void State::MainMenu::onOpen() {

}

void State::MainMenu::onTick(int dt) {

}

void State::MainMenu::onEvent(const sf::Event &e) {

}

void State::MainMenu::draw(GameRenderer &renderer) {
	sf::RectangleShape rect{sf::Vector2f(120, 50)};
	rect.setFillColor(sf::Color::Red);

	sf::RectangleShape rect2 = rect;
	rect2.setPosition(500, 500);

	renderer.draw(std::make_unique<sf::RectangleShape>(std::move(rect)));
	renderer.draw(std::make_unique<sf::RectangleShape>(std::move(rect2)));
}