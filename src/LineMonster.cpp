#include "LineMonster.h"


LineMonster::LineMonster(const sf::Texture& texture, const sf::Vector2f& pos, float size)
	:Monster(texture, pos, size)
{


}
LineMonster::~LineMonster()
{
}


Vector2f LineMonster::setDirection(sf::Vector2f& direction, float time,int dir)
{

	float  timeElaped = m_clock.getElapsedTime().asSeconds();

	if (timeElaped >= 1.5) {
		int direction = rand() % 2;

		switch (direction)
		{

		case 0:
			m_direction = sf::Vector2f({ m_Monstermovespeed * time,0 });
			break;

		case 1:
			m_direction = sf::Vector2f({ -m_Monstermovespeed * time,0 });
			break;
		default:
			m_direction = sf::Vector2f(0, 0);
		}
		m_clock.restart();
	}
	return m_direction;
}

