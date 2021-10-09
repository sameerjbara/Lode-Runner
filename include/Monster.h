#pragma once
#include "DynamicObject.h"


class Monster : public DynamicObject
{
public:
	Monster();
	Monster(const sf::Texture& texture, const sf::Vector2f& pos, float size);
	virtual ~Monster();


	virtual bool collision(Wall& otherobj);
	virtual bool collision(Player& otherobj);
	virtual bool collision(Object& otherobj);
	virtual bool collision(Coins& otherobj);
	virtual bool collision(Ladder& otherobj);
	virtual bool collision(Pole& otherobj);
	virtual bool collision(Monster& otherobj);
	virtual bool collision(GiftMonster& otherobj);
	virtual bool collision(GiftTime& otherobj);
	virtual bool collision(GiftLive& otherobj) ;
	virtual bool collision(GiftPoints& otherobj) ;


	virtual char getType();

private:
	sf::Clock m_clock;

};