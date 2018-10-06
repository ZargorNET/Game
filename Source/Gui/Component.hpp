#ifndef GAME_COMPONENT_HPP
#define GAME_COMPONENT_HPP


#include "../GameRenderer.hpp"

namespace GUI {
	/**
	 * Base class for GUI components
	 */
	class Component {
	private:
		float m_width, m_height;
	protected:
		bool isMouseOver(const sf::Shape &shape) const;

	public:
		Component(float width, float height) : m_width(width), m_height(height) {}

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
	};
}


#endif //GAME_COMPONENT_HPP
