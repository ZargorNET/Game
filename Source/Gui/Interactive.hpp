#ifndef GAME_BUTTON_HPP
#define GAME_BUTTON_HPP


#include "Component.hpp"

namespace GUI {
	class Interactive : public Component {
	protected:
		sf::RectangleShape m_shape;

		virtual void onLeftClick() = 0;

		virtual void onRightClick() = 0;

		virtual void onHover() = 0; //TODO Add Hover functionality

	public:
		explicit Interactive(sf::RectangleShape &&shape) : Component(shape.getSize().x, shape.getSize().y),
		                                                   m_shape(std::move(shape)) {}

		void onEvent(const sf::Event &event) override;
	};
}


#endif //GAME_BUTTON_HPP
