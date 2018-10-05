#ifndef GAME_MAINMENUSTATE_HPP
#define GAME_MAINMENUSTATE_HPP

#include "IStateBase.hpp"
#include "../Gui/Menu.hpp"


class GameRenderer;

namespace State {
	class MainMenu : public IStateBase {
	private:
		GUI::Menu m_menu;
	public:

		void onOpen() override;

		void onClose() override;

		void onTick(int dt) override;

		void onEvent(const sf::Event &e) override;

		void draw(GameRenderer &renderer) override;
	};

}

#endif //GAME_MAINMENUSTATE_HPP
