#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "GameWindow.hpp"
#include "State/MainMenu.hpp"
#include "Application.hpp"
#include "Gui/TextButton.hpp"


int main() {
	Application::getInstance();
	sf::Clock clock;
	GameWindow &mainWindow = Application::getInstance().getGameWindow();
	GameRenderer &renderer = Application::getInstance().getGameRenderer();
	Application::getInstance().setState(std::make_unique<State::MainMenu>());

	GUI::TextButton button{};

	while (mainWindow.isOpen()) {
		float fps = 1.f / clock.getElapsedTime().asSeconds();
		clock.restart();

		mainWindow.setTitle("My Game [FPS: " + std::to_string(fps) + "]");

		IStateBase *state = Application::getInstance().getCurrenState();
		if (!state)
			throw std::runtime_error("Current state is a nullptr!");

		sf::Event event{};
		while (mainWindow.getRaw().pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mainWindow.close();
				break;
			}
			state->onEvent(event);
		}
		mainWindow.clear(sf::Color::Black);
		state->draw(renderer);

		renderer.update();
		mainWindow.update();
	}
	return 0;
}
