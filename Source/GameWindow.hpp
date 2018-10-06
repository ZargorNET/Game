#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Util/Singleton.hpp"

/**
 * This class combines to unsigned ints: <b>Width & Height</b>
 */
struct Dimension {
	Dimension(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

	unsigned int m_width, m_height;
};

/**
 * The window type defines the display type.
 * You can choose between:
 * <ul>
 * 	<li>BORDER</li>
 * 	<li>BORDERLESS</li>
 * 	<li>FULLSCREEN</li>
 * </ul>
 */
enum class WindowType {
	BORDER = 0,
	BORDERLESS,
	FULLSCREEN
};

/**
 * This class represents an OS' window
 */
class GameWindow {
private:
	sf::ContextSettings m_ContextSettings;
	std::string m_title;
	WindowType m_windowType;
	unsigned int m_frameLimit;
	Dimension m_size;
	sf::RenderWindow m_raw;

	void open();

public:
	GameWindow(std::string title, Dimension size, WindowType windowType = WindowType::BORDER,
	           unsigned int frameLimit = 60);

	/**
	 * Closes the window
	 */
	void close();

	/**
	 * Checks if the window is open
	 * @returns true if so
	 */
	bool isOpen();

	/**
	 * Sets the windows' title
	 * @param title The title
	 */
	void setTitle(std::string title);

	/**
	 * Sets the window's frame limit
	 * @param frameLimit Frame limit in frames per second(fps)
	 */
	void setFrameLimit(unsigned int frameLimit);

	/**
	 * Sets the window's size
	 * @param size The window size
	 */
	void setSize(Dimension size);

	/**
	 * Sets the window's display type
	 * @see WindowType
	 * @param windowType The window type
	 */
	void setWindowType(WindowType windowType);

	/**
	 * Draws to the current window
	 */
	void draw(const sf::Drawable &drawable);

	/**
	 * Clears the drawn stuff and replaces them with the given color
	 * @param color The clear color
	 */
	void clear(const sf::Color &color);

	/**
	 * Displays the drawn stuff
	 */
	void update();


	std::string &getTitle() {
		return this->m_title;
	}

	const WindowType &getWindowType() {
		return this->m_windowType;
	}

	unsigned int getFrameLimit() {
		return this->m_frameLimit;
	}

	const Dimension &getSize() {
		return this->m_size;
	}

	sf::RenderWindow &getRaw() {
		return this->m_raw;
	}
};

#endif //GAME_WINDOW_HPP
