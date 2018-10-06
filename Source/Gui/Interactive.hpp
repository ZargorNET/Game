#ifndef GAME_BUTTON_HPP
#define GAME_BUTTON_HPP


#include "Component.hpp"
#include <functional>

namespace GUI {
	/**
	 * Base class for components which shall be clickable/hoverable
	 */
	class Interactive : public Component {
	protected:
		sf::RectangleShape m_shape;

	public:
		explicit Interactive(sf::RectangleShape &&shape) : Component(shape.getSize().x, shape.getSize().y),
		                                                   m_shape(std::move(shape)) {}

		void onEvent(const sf::Event &event) override;

		void setLeftClickCallback(std::function<void()> func);

		void setRightClickCallback(std::function<void()> func);

		void setHoverCallback(std::function<void()> func);

	private:
		std::function<void()> m_onLeftClick = []() {};
		std::function<void()> m_onRightClick = []() {};
		std::function<void()> m_onHover = []() {};
	};
}


#endif //GAME_BUTTON_HPP
