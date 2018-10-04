#ifndef GAME_BUTTON_HPP
#define GAME_BUTTON_HPP


#include "Component.hpp"

namespace GUI {
	class Button : public Component {
	private:
		const sf::RectangleShape &m_shape;

		void onEvent(const sf::Event &event) override;

		virtual void onLeftClick() = 0;

		virtual void onRightClick() = 0;

		virtual void onHover() = 0; //TODO Add Hover functionality

	public:
		Button(const sf::RectangleShape &shape) : Component(shape.getSize().x, shape.getSize().y), m_shape(shape) {}
	};
}


#endif //GAME_BUTTON_HPP
