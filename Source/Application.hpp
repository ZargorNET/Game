#ifndef GAME_APPLICATION_HPP
#define GAME_APPLICATION_HPP


#include "Util/Singleton.hpp"
#include "GameWindow.hpp"
#include "GameRenderer.hpp"
#include "State/IStateBase.hpp"

class Application : public Singleton {
private:
	Application();

	GameWindow m_window;
	GameRenderer m_renderer;
	std::unique_ptr<IStateBase> m_state;
	std::unique_ptr<IStateBase> m_replaceState;

public:
	static Application &getInstance();

	GameWindow &getGameWindow();

	GameRenderer &getGameRenderer();

	IStateBase *getCurrenState();

	void setState(std::unique_ptr<IStateBase> state);
};


#endif //GAME_APPLICATION_HPP
