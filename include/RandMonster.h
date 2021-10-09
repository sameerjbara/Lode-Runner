#pragma once

#include <string>
#include "Monster.h"


class RandMonster : public Monster
{
public:
	RandMonster(const sf::Texture& texture, const sf::Vector2f& pos, float size);
	virtual ~RandMonster();

	virtual Vector2f setDirection(sf::Vector2f& direction, float time,int dir);



private:
	sf::Clock m_clock;

};