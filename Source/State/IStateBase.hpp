#ifndef GAME_STATEBASE_HPP
#define GAME_STATEBASE_HPP

#include <SFML/Graphics.hpp>
#include "../GameRenderer.hpp"

/**
 * Represents the base class of every state
 */
class IStateBase {
public:
	virtual ~IStateBase() = default;

	/**
	 * Called when the state is set
	 */
	virtual void onOpen() = 0;

	/**
	 * Called when the state is going to be replaced
	 */
	virtual void onClose() = 0;

	/**
	 * Called every tick
	 * @param dt delta time
	 */
	virtual void onTick(int dt) = 0; //TODO IMPLEMENT METHOD TO GAME LOOP

	/**
	 * Called on every event from the main window
	 * @param e The event
	 */
	virtual void onEvent(const sf::Event &e) = 0;

	/**
	 * Called every frame to draw in the renderer
	 * @param renderer The renderer to draw in
	 */
	virtual void draw(GameRenderer &renderer) = 0;
};


#endif //GAME_STATEBASE_HPP
