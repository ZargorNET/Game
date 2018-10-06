#include "CenteredMenu.hpp"
#include "../Application.hpp"


void GUI::CenteredMenu::addComponent(std::unique_ptr<GUI::Component> component) {
	component->setPosition(
			{Application::getInstance().getGameWindow().getSize().m_width / 2 - component->getShape().getSize().x / 2,
			 Application::getInstance().getGameWindow().getSize().m_height / 2 - component->getShape().getSize().y / 2 +
			 m_currentSpace});
	m_currentSpace += component->getShape().getSize().y + m_space;

	Menu::addComponent(std::move(component));
}
