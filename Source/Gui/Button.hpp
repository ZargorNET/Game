#ifndef GAME_TEXTBUTTON_HPP
#define GAME_TEXTBUTTON_HPP

#include "Interactive.hpp"
#include "TextLabel.hpp"

namespace GUI {
	/**
	 * Represents a simple button with text in it
	 */
	class Button : public Interactive, public TextLabel {
	public:
		Button(sf::RectangleShape &shape, sf::Text &&text) : Component(shape), Interactive(shape),
		                                                     TextLabel(shape, std::move(text)) {

		}

		void draw(GameRenderer &renderer) override;

	protected:

	};
}


#endif //GAME_TEXTBUTTON_HPP
