#include "GameWindow.hpp"
#include <utility>

GameWindow::GameWindow(std::string title, Dimension size, WindowType windowType, unsigned int frameLimit)
		: m_title(std::move(title)),
		  m_size(size),
		  m_windowType(windowType),
		  m_frameLimit(frameLimit) {

	m_ContextSettings.depthBits = 24;
	m_ContextSettings.stencilBits = 8;
	m_ContextSettings.antialiasingLevel = 0;
	m_ContextSettings.majorVersion = 3;
	m_ContextSettings.minorVersion = 3;

	this->open();
}

void GameWindow::close() {
	m_raw.close();
}

bool GameWindow::isOpen() {
	return m_raw.isOpen();
}

void GameWindow::setTitle(std::string title) {
	m_title = std::move(title);
	this->getRaw().setTitle(m_title);
}

void GameWindow::setFrameLimit(unsigned int frameLimit) {
	m_frameLimit = frameLimit;
	this->getRaw().setFramerateLimit(m_frameLimit);
}

void GameWindow::setSize(Dimension size) {
	m_size = size;
	this->open();
}

void GameWindow::setWindowType(WindowType windowType) {
	m_windowType = windowType;
	this->open();
}

void GameWindow::draw(const sf::Drawable &drawable) {
	m_raw.draw(drawable);
}

void GameWindow::clear(const sf::Color &color) {
	m_raw.clear(color);
}

void GameWindow::update() {
	m_raw.display();
}

void GameWindow::open() {
	if (this->isOpen())
		this->close();

	unsigned int flags = 0;
	switch (m_windowType) {
		case WindowType::FULLSCREEN:
			flags |= sf::Style::Fullscreen;
			break;
		case WindowType::BORDERLESS:
			flags |= sf::Style::None;
			break;
		default:
		case WindowType::BORDER:
			flags |= sf::Style::Close;
			break;
	}


	m_raw.create(sf::VideoMode(m_size.m_width,
	                           m_size.m_height),
	             m_title, flags, m_ContextSettings);
	m_raw.setFramerateLimit(this->getFrameLimit());
}

