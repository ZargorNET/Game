

#include "TextButton.hpp"

/*GUI::TextButton::TextButton(const RectangleShapeTest& shape) : Interactive(shape) {

}*/
void GUI::TextButton::draw(GameRenderer &renderer) {
	renderer.draw(m_shape);
	renderer.draw(m_text);
}
