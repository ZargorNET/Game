#ifndef GAME_TEXTBUTTON_HPP
#define GAME_TEXTBUTTON_HPP

#include "Interactive.hpp"

namespace GUI {
	class TextButton : public Interactive {
	public:
		explicit TextButton(sf::RectangleShape &&shape) : Interactive(std::move(shape)) {}

		void draw(GameRenderer &renderer) override;

	protected:
		void onLeftClick() override;

		void onRightClick() override;

		void onHover() override;
	};
}


#endif //GAME_TEXTBUTTON_HPP
