#include "GameRenderer.hpp"
#include "Application.hpp"

void GameRenderer::draw(sf::Drawable &drawable) {
	m_toDraw.push_back(&drawable);
}


void GameRenderer::update() {
	for (const auto &drawable : m_toDraw) {
		if (drawable)
			Application::getInstance().getGameWindow().draw(*drawable);
	}
	m_toDraw.clear();
}
