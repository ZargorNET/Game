#ifndef GAME_WINDOW_HPP
#define GAME_WINDOW_HPP

#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Util/Singleton.hpp"


struct Dimension {
	Dimension(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

	unsigned int m_width, m_height;
};

enum class WindowType {
	BORDER = 0,
	BORDERLESS,
	FULLSCREEN
};

class GameWindow {
private:
	sf::ContextSettings m_ContextSettings;
	std::string m_title;
	WindowType m_windowType;
	unsigned int m_framelimit;
	Dimension m_size;
	sf::RenderWindow m_raw;

	void open();

public:
	GameWindow(std::string title, Dimension size, WindowType windowType = WindowType::BORDER,
	           unsigned int framelimit = 60);

	void close();

	bool isOpen();

	void setTitle(std::string title);

	void setFramelimit(unsigned int framelimit);

	void setSize(Dimension size);

	void setWindowType(WindowType windowType);

	void draw(const sf::Drawable &drawable);

	void clear(const sf::Color &color);

	void update();


	std::string &getTitle() {
		return this->m_title;
	}

	const WindowType &getWindowType() {
		return this->m_windowType;
	}

	unsigned int getFramelimit() {
		return this->m_framelimit;
	}

	const Dimension &getSize() {
		return this->m_size;
	}

	sf::RenderWindow &getRaw() {
		return this->m_raw;
	}
};

#endif //GAME_WINDOW_HPP
