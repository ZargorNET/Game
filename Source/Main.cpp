#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include "GameWindow.hpp"
#include "State/MainMenu.hpp"
#include "Application.hpp"
#include "Gui/Button.hpp"
#include "Resource/ResourceManager.hpp"
#include "Gui/CenteredMenu.hpp"


int main() {
	Application::getInstance();
	sf::Clock clock;
	GameWindow &mainWindow = Application::getInstance().getGameWindow();
	GameRenderer &renderer = Application::getInstance().getGameRenderer();

	auto fontHolder = ResourceHolder<sf::Font>("Res/", ".ttf", false);
	auto textureHolder = ResourceHolder<sf::Texture>("Res/", ".png");
	auto soundHolder = ResourceHolder<sf::SoundBuffer>("Res/", ".ogg", false);

	ResourceManager resourceManager(std::move(fontHolder),
	                                std::move(textureHolder),
	                                std::move(soundHolder));


	{
		GUI::CenteredMenu menu(10);
		menu.setBackground(resourceManager.getTexture("Download"));
		sf::RectangleShape buttonShape({200.f, 50.f});
		buttonShape.setOutlineColor(sf::Color::Green);
		buttonShape.setFillColor(sf::Color::Black);
		buttonShape.setOutlineThickness(2.f);

		GUI::Button textButton(buttonShape,
		                       sf::Text("Hello world", resourceManager.getFont("Roboto-Black")));
		textButton.setLeftClickCallback([]() {
			std::cout << "Clicked\n";
		});
		menu.addComponent(std::make_unique<GUI::Button>(std::move(textButton)));
		auto rect = sf::RectangleShape();
		rect.setFillColor(sf::Color::Black);
		rect.setSize({200.f, 50.f});
		menu.addComponent(std::make_unique<GUI::Button>(
				std::move(GUI::Button(rect, std::move(sf::Text("Second", resourceManager.getFont("Roboto-Black")))))));
		Application::getInstance().setState(std::make_unique<State::MainMenu>(std::move(menu)));
	}


	while (mainWindow.isOpen()) {
		float fps = 1.f / clock.getElapsedTime().asSeconds();
		clock.restart();

		mainWindow.setTitle("My Game [FPS: " + std::to_string(fps) + "]");

		IStateBase *state = Application::getInstance().getCurrentState();
		if (!state)
			throw std::runtime_error("Current state is fontHolder nullptr!");

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
