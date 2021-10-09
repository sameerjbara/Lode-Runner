#include "RandMonster.h"


RandMonster::RandMonster(const sf::Texture& texture, const sf::Vector2f& pos, float size)
	:Monster(texture, pos, size)
{


}
RandMonster::~RandMonster()
{
}


Vector2f RandMonster::setDirection(sf::Vector2f& direction, float time,int dir)
{
	

	float  timeElaped = m_clock.getElapsedTime().asSeconds();

	if (timeElaped >= 1.5) {
		int direction = rand() % 4;

		switch (direction)
		{

		case 0:
			if (dir == 1 || dir == 0)
			{
				m_direction = sf::Vector2f({ 0,-m_Monstermovespeed * time });
				break;
			}
			else
			{
				break;
			}


		case 1:
			if (dir == 2 || dir == 0)
			{
				m_direction = sf::Vector2f({ 0, m_Monstermovespeed * time });
				break;
			}
			else
			{
				break;
			}

		case 2:
			m_direction = sf::Vector2f({ -m_Monstermovespeed * time,0 });
			break;

		case 3:
			m_direction = sf::Vector2f({ m_Monstermovespeed * time,0 });
			break;

		
		default:
			m_direction = sf::Vector2f(0, 0);
		}

		m_clock.restart();
	}
	return m_direction;
}
