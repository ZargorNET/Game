#ifndef GAME_COMPONENT_HPP
#define GAME_COMPONENT_HPP


#include "../GameRenderer.hpp"

namespace GUI {
	/**
	 * Base class for GUI components
	 */
	class Component {
	private:
		sf::RectangleShape m_shape;
	protected:
		bool isMouseOver(const sf::Shape &shape) const;

	public:
		explicit Component(sf::RectangleShape &&shape) : m_shape(std::move(shape)) {}

		explicit Component(sf::RectangleShape &shape) : m_shape(shape) {}

		virtual ~Component() = default;

		/**
		 * Gets every frame called
		 * @param renderer The renderer to draw in
		 */
		virtual void draw(GameRenderer &renderer) = 0;

		/**
		 * Gets every frame called
		 * @param event Any event (not specific to the component)
		 */
		virtual void onEvent(const sf::Event &event) = 0;

		virtual void setPosition(const sf::Vector2f &vector) {
			m_shape.setPosition(vector);
		}

		sf::RectangleShape &getShape() {
			return m_shape;
		}
	};
}


#endif //GAME_COMPONENT_HPP
