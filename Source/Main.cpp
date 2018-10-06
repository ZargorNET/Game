#include <SFML/Graphics.hpp>
#include <memory>
#include "GameWindow.hpp"
#include "State/MainMenu.hpp"
#include "Application.hpp"
#include "Gui/TextButton.hpp"
#include "Resource/ResourceManager.hpp"


int main() {
	Application::getInstance();
	sf::Clock clock;
	GameWindow &mainWindow = Application::getInstance().getGameWindow();
	GameRenderer &renderer = Application::getInstance().getGameRenderer();

	auto fontHolder = ResourceHolder<sf::Font>("Res/", ".ttf", false);
	auto textureHolder = ResourceHolder<sf::Texture>("Res/", ".png");
	auto soundHolder = ResourceHolder<sf::SoundBuffer>("Res/", ".ogg", false);

	ResourceManager resoureManager(std::move(fontHolder),
	                               std::move(textureHolder),
	                               std::move(soundHolder));


	{
		GUI::Menu menu;
		sf::RectangleShape buttonShape({300.f, 100.f});
		buttonShape.setOutlineColor(sf::Color::Green);
		buttonShape.setFillColor(sf::Color::Black);
		buttonShape.setOutlineThickness(2.f);
		buttonShape.setPosition(400.f, 400.f);

		GUI::TextButton textButton(std::move(buttonShape),
		                           sf::Text("Hello world", resoureManager.getFont("Roboto-Black")));
		textButton.setLeftClickCallback([]() {
			std::cout << "HOVVV\n";
		});
		menu.addComponent(std::make_unique<GUI::TextButton>(std::move(textButton)));
		Application::getInstance().setState(std::make_unique<State::MainMenu>(std::move(menu)));
	}


	while (mainWindow.isOpen()) {
		float fps = 1.f / clock.getElapsedTime().asSeconds();
		clock.restart();

		mainWindow.setTitle("My Game [FPS: " + std::to_string(fps) + "]");

		IStateBase *state = Application::getInstance().getCurrenState();
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
