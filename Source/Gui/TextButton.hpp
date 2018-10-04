#ifndef GAME_TEXTBUTTON_HPP
#define GAME_TEXTBUTTON_HPP

#include "Button.hpp"

namespace GUI {
	class TextButton : public Button {
	public:
	private:
		void onLeftClick() override;

		void onRightClick() override;

		void onHover() override;
	};
}


#endif //GAME_TEXTBUTTON_HPP
