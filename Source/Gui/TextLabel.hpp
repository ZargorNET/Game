#ifndef GAME_TEXTLABEL_HPP
#define GAME_TEXTLABEL_HPP


#include "Component.hpp"

namespace GUI {
	class TextLabel : public virtual Component {
	protected:
		sf::Text m_text;
	public:
		explicit TextLabel(sf::RectangleShape &&shape, sf::Text &&text) : Component(std::move(shape)),
		                                                                  m_text(std::move(text)) {
			setPosition(getShape().getPosition());
		}

		explicit TextLabel(sf::RectangleShape &shape, sf::Text &&text) : Component(shape),
		                                                                 m_text(std::move(text)) {
			setPosition(getShape().getPosition());
		}

		void setPosition(const sf::Vector2f &vector) override {
			Component::setPosition(vector);

			const sf::FloatRect &textBound(m_text.getGlobalBounds());
			const sf::FloatRect &shapeBound(getShape().getGlobalBounds());
			m_text.setPosition(shapeBound.left + (shapeBound.width / 2) - (textBound.width / 2),
			                   shapeBound.top + (shapeBound.height / 2) - textBound.height);
		}
	};
}

#endif //GAME_TEXTLABEL_HPP
