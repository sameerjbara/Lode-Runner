#include "SmartMonster.h"


SmartMonster::SmartMonster(const sf::Texture& texture, const sf::Vector2f& pos, float size,Player& player)
	:Monster(texture, pos, size) , m_player1(player)
{


}
SmartMonster::~SmartMonster()
{
}


Vector2f SmartMonster::setDirection(sf::Vector2f& direction, float time, int dir)
{
	Vector2f currPosition1, currPosition2;//, currPosition3, currPosition4;
	Vector2f org_possition = m_figure.getPosition();
	int dest1 = 10000000000000;
	int dest3 = 100000000000001;
	int dest4 = 100000000000002;


	m_figure.move({ m_movespeed * time, 0 });
	dest1 = distance(m_player1.getPosition(), m_figure.getPosition());
	m_figure.setPosition(org_possition);

	m_figure.move({ -m_movespeed * time, 0 });
	int dest2 = distance(m_player1.getPosition(), m_figure.getPosition());
	m_figure.setPosition(org_possition);

	if (dir == 1 || dir == 0)
	{
		m_figure.move({ 0, -m_movespeed * time });

		dest3 = distance(m_player1.getPosition(), m_figure.getPosition());
		m_figure.setPosition(org_possition);
	}
	if (dir == 2 || dir == 0)
	{

		m_figure.move({ 0, m_movespeed * time });
		dest4 = distance(m_player1.getPosition(), m_figure.getPosition());
		m_figure.setPosition(org_possition);
	}

	if (dest1 > dest2 && dest3 > dest2 && dest4 > dest2)
	{
		return { -m_movespeed * time, 0 };
	}
	else if (dest1 > dest3 && dest2 > dest3 && dest4 > dest3)
	{

		return{ 0, -m_movespeed * time };
	}
	else if (dest1 < dest3 && dest2 > dest1 && dest4 > dest1)
	{
		return { m_movespeed * time, 0 };
	}
	
	else if (dest4 < dest3 && dest2 > dest4 && dest4 < dest1)
	{
		return { 0, m_movespeed * time };
	}
	
	else
	{
		return { 0,0 };
	}
}
int SmartMonster::distance(sf::Vector2f playerPos, sf::Vector2f other) const
{
	return sqrt(    (      (playerPos.y - other.y)   *     (playerPos.y - other.y)  ) +( (playerPos.x - other.x)* (playerPos.x - other.x)    )    );
}


