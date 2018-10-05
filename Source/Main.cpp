#include <SFML/Graphics.hpp>
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
	Application::getInstance().setState(std::make_unique<State::MainMenu>());

	GUI::Menu menu;

	auto a = ResourceHolder<sf::Font>("Res/", ".ttf", false);
	auto b = ResourceHolder<sf::Texture>("Res/", ".png");
	auto c = ResourceHolder<sf::SoundBuffer>("Res/", ".ogg", false);
	ResourceManager resoureManager(std::move(a),
	                               std::move(b),
	                               std::move(c));

	{
		sf::RectangleShape buttonShape({600.f, 600.f});
		buttonShape.setOutlineColor(sf::Color::Green);
		buttonShape.setOutlineThickness(2.f);
		buttonShape.setTexture(&resoureManager.getTexture("Download"));
		menu.addComponent(std::make_unique<GUI::TextButton>(std::move(buttonShape)));
	}


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
			menu.onEvent(event);
		}
		mainWindow.clear(sf::Color::Black);
		state->draw(renderer);
		menu.draw(renderer);
		//	mainWindow.draw(buttonShape);

		renderer.update();
		mainWindow.update();
	}
	return 0;
}
