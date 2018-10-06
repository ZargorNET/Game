#ifndef GAME_CENTEREDMENU_HPP
#define GAME_CENTEREDMENU_HPP

#include "Menu.hpp"

namespace GUI {
	class CenteredMenu : public Menu {
	private:
		float m_currentSpace = 0;
		const int m_space;
	public:
		explicit CenteredMenu(int space = 10) : m_space(space) {}

		void addComponent(std::unique_ptr<Component> component) override;
	};
}


#endif //GAME_CENTEREDMENU_HPP
