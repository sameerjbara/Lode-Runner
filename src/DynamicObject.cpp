#include "DynamicObject.h"
#include <iostream>

using std::cout;
using std::endl;

DynamicObject::DynamicObject()
	:Object()
{

}

DynamicObject::DynamicObject(const sf::Texture& texture, const sf::Vector2f& pos, float size)
	: Object(texture, pos, size)
{
	

}

DynamicObject::~DynamicObject()
{
}
void DynamicObject::move1(sf::Vector2f direction, float time, int dir)
{

	m_direction = setDirection(direction, time,dir);
	m_figure.move(m_direction);
	if (!isinBound())
	{
		keepInPlace();
	}
}

void DynamicObject::keepInPlace()
{
	m_figure.move(-m_direction);
}

bool DynamicObject::isinBound()
{
	if (m_figure.getPosition().x  < 0 ||m_figure.getPosition().x > width - TILE_SIZE ||m_figure.getPosition().y + 3 * TILE_SIZE < 0 ||
		m_figure.getPosition().y  > height - 2 * TILE_SIZE)
		return false;

	return true;
}