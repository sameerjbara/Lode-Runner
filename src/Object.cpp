#include "Object.h"

Object::Object()
{
}

Object::Object(const Texture& texture, const Vector2f position, const float size)

{
	m_figure.setTexture(&texture);
	m_figure.setSize(sf::Vector2f(size, size));
	m_figure.setPosition(position);
	m_figure.setScale(0.8, 0.8);
}

Object::~Object()
{
}

Vector2f Object::getPosition() const
{
	return m_figure.getPosition();
}

void Object::setPosition1(Vector2f position)
{
	m_figure.setPosition(position);
}

Vector2f Object::getSize() const
{
	return m_figure.getSize();
}

void Object::draw(RenderWindow& window)
{
	window.draw(m_figure);
}
FloatRect Object::getGlobalBound() const
{
	return m_figure.getGlobalBounds();
}





