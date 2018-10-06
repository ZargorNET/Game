#ifndef GAME_BACKGROUND_HPP
#define GAME_BACKGROUND_HPP

#include "Component.hpp"
#include "../Application.hpp"

namespace GUI {
	class Background : public Component {
	public:
		Background(sf::RectangleShape &&shape, const sf::Texture &texture) : Component(std::move(shape)) {
			getShape().setSize({static_cast<float>(Application::getInstance().getGameWindow().getSize().m_width),
			                    static_cast<float>(Application::getInstance().getGameWindow().getSize().m_height)});
			getShape().setTexture(&texture);
		}

		void draw(GameRenderer &renderer) override {
			renderer.draw(getShape());
		}

		void onEvent(const sf::Event &event) override {

		}
	};
}

#endif //GAME_BACKGROUND_HPP
