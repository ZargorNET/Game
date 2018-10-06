#ifndef GAME_APPLICATION_HPP
#define GAME_APPLICATION_HPP


#include "Util/Singleton.hpp"
#include "GameWindow.hpp"
#include "GameRenderer.hpp"
#include "State/IStateBase.hpp"

/**
 * This class represents the Application itself
 */
class Application : public Singleton {
private:
	Application();

	GameWindow m_window;
	GameRenderer m_renderer;
	std::unique_ptr<IStateBase> m_state;
	std::unique_ptr<IStateBase> m_replaceState;

public:
	/**
	 * @returns This (static)
	 */
	static Application &getInstance();

	/**
	 * @returns The main OS window
	 */
	GameWindow &getGameWindow();

	/**
	 * @returns The main game renderer
	 */
	GameRenderer &getGameRenderer();

	/**
	 * @returns The current scene(state) as a pointer
	 * @warning Can be null!
	 */
	IStateBase *getCurrentState();

	/**
	 * Replaces the state in the next frame
	 */
	void setState(std::unique_ptr<IStateBase> state);
};


#endif //GAME_APPLICATION_HPP
