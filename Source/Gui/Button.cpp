

#include "Button.hpp"

/*GUI::Button::Button(const RectangleShapeTest& shape) : Interactive(shape) {

}*/
void GUI::Button::draw(GameRenderer &renderer) {
	renderer.draw(Interactive::getShape());
	renderer.draw(TextLabel::m_text);
}
