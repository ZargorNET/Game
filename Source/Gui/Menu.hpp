#ifndef GAME_MENU_HPP
#define GAME_MENU_HPP

#include <vector>
#include <memory>
#include "Component.hpp"
#include "Background.hpp"

namespace GUI {
	class Menu {
	protected:
		std::vector<std::unique_ptr<Component>> m_components;
		std::unique_ptr<GUI::Background> m_background;

	public:
		virtual void addComponent(std::unique_ptr<Component> component);

		void clear();

		void draw(GameRenderer &renderer);

		void onEvent(const sf::Event &event);

		void setBackground(const sf::Texture &text);
	};

}

#endif //GAME_MENU_HPP
