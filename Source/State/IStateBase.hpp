#ifndef GAME_STATEBASE_HPP
#define GAME_STATEBASE_HPP

#include <SFML/Graphics.hpp>
#include "../GameRenderer.hpp"

class IStateBase {
public:
	virtual ~IStateBase() = default;

	virtual void onOpen() = 0;

	virtual void onTick(int dt) = 0; //TODO IMPLEMENT METHOD TO GAME LOOP
	virtual void onEvent(const sf::Event &e) = 0;

	virtual void draw(GameRenderer &renderer) = 0;
};


#endif //GAME_STATEBASE_HPP
