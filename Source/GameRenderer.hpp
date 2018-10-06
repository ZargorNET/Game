#ifndef GAME_GAMERENDERER_HPP
#define GAME_GAMERENDERER_HPP

#include <list>
#include <memory>
#include <SFML/Graphics.hpp>

class GameRenderer {
private:
	std::list<sf::Drawable *> m_toDraw;
public:
	void draw(sf::Drawable &drawable);

	void update();
};


#endif //GAME_GAMERENDERER_HPP
