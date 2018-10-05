#ifndef GAME_MENU_HPP
#define GAME_MENU_HPP

#include <vector>
#include <memory>
#include "Component.hpp"

namespace GUI {
	class Menu {
	private:
		std::vector<std::unique_ptr<Component>> m_components;
		unsigned int m_offsetX = 0;
		unsigned int m_offsetY = 0;

	public:
		void addComponent(std::unique_ptr<Component> component);

		void clear();

		void setOffsetX(unsigned int x);

		void setOffsetY(unsigned int y);

		void draw(GameRenderer &renderer);

		void onEvent(const sf::Event &event);

	};

}

#endif //GAME_MENU_HPP
