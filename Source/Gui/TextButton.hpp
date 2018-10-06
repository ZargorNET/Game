#ifndef GAME_TEXTBUTTON_HPP
#define GAME_TEXTBUTTON_HPP

#include "Interactive.hpp"

namespace GUI {
	class TextButton : public Interactive {
	public:
		explicit TextButton(sf::RectangleShape &&shape, sf::Text &&text) : Interactive(std::move(shape)),
		                                                                   m_text(std::move(text)) {
			const sf::FloatRect textBound(m_text.getGlobalBounds());
			const sf::FloatRect shapeBound(m_shape.getGlobalBounds());
			m_text.setPosition(shapeBound.left + (shapeBound.width / 2) - (textBound.width / 2),
			                   shapeBound.top + (shapeBound.height / 2) - textBound.height);
		}

		void draw(GameRenderer &renderer) override;


	protected:
		sf::Text m_text;
	};
}


#endif //GAME_TEXTBUTTON_HPP
