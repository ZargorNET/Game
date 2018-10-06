#ifndef GAME_GAMERENDERER_HPP
#define GAME_GAMERENDERER_HPP

#include <list>
#include <memory>
#include <SFML/Graphics.hpp>

/**
 * This class stores raw pointer from sf::Drawable and draws it when the #update() method gets called
 */
class GameRenderer {
private:
	std::list<sf::Drawable *> m_toDraw;
public:
	/**
	 * Add a sf::Drawable pointer to the list
	 * \Warning Pointer needs to stay valid until #update() has been called!
	 * \param drawable The drawable reference
	 */
	void draw(sf::Drawable &drawable);

	/**
	 * Clears the vector and draws everything to the Application's GameWindow
	 */
	void update();
};


#endif //GAME_GAMERENDERER_HPP
