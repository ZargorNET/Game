

#include "Button.hpp"

/*GUI::Button::Button(const RectangleShapeTest& shape) : Interactive(shape) {

}*/
void GUI::Button::draw(GameRenderer &renderer) {
	renderer.draw(m_shape);
	renderer.draw(m_text);
}
