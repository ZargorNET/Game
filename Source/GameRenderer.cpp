#include "GameRenderer.hpp"
#include "Application.hpp"
#include <memory>

void GameRenderer::draw(std::unique_ptr<sf::Drawable> drawable) {
	m_toDraw.push_back(std::move(drawable));
}


void GameRenderer::update() {
	for (const auto &drawable : m_toDraw) {
		Application::getInstance().getGameWindow().draw(*drawable);
	}
	m_toDraw.clear();
}
