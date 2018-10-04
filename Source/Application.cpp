#include <c++/8.2.0/iostream>
#include "Application.hpp"

Application &Application::getInstance() {
	static Application app{};
	return app;
}

Application::Application() : m_window(GameWindow{"Game", Dimension(1080, 720)}) {

}

GameWindow &Application::getGameWindow() {
	return m_window;
}

GameRenderer &Application::getGameRenderer() {
	return m_renderer;
}

IStateBase *Application::getCurrenState() {
	if (m_replaceState) {
		m_state = std::move(m_replaceState);
		m_state->onOpen();
	}

	return m_state.get();
}

void Application::setState(std::unique_ptr<IStateBase> state) {
	m_replaceState = std::move(state);
}
