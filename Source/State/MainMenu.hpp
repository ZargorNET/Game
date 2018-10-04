#ifndef GAME_MAINMENUSTATE_HPP
#define GAME_MAINMENUSTATE_HPP

#include "IStateBase.hpp"


class GameRenderer;

namespace State {
	class MainMenu : public IStateBase {
	private:
	public:

		void onOpen() override;

		void onTick(int dt) override;

		void onEvent(const sf::Event &e) override;

		void draw(GameRenderer &renderer) override;
	};

}

#endif //GAME_MAINMENUSTATE_HPP
