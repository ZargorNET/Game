#ifndef GAME_GAMERENDERER_HPP
#define GAME_GAMERENDERER_HPP

#include <list>
#include <SFML/Graphics.hpp>
#include <memory>

class GameRenderer {
private:
	std::list<std::unique_ptr<sf::Drawable>> m_toDraw;
public:
	void draw(std::unique_ptr<sf::Drawable> drawable);

	void update();
};


#endif //GAME_GAMERENDERER_HPP
