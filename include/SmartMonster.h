#pragma once
#include <string>
#include "Monster.h"
#include "Player.h"


class SmartMonster : public Monster
{
public:
	SmartMonster(const sf::Texture& texture, const sf::Vector2f& pos, float size,Player& player);
	virtual ~SmartMonster();
	virtual Vector2f setDirection(sf::Vector2f& direction, float time,int dir);
	int distance(sf::Vector2f diggerLoc, sf::Vector2f other) const;


private:
	sf::Clock m_clock;
protected:
	Player& m_player1;



};